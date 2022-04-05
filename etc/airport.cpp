#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

#define DURATION 60 //시뮬레이션 시간은 100초
#define available true
#define busy false

// A : 좌측 유도선, B : 우측 유도선
// C : 좌측 유도선X상부 주행로, D : 우측 유도선X상부 주행로, E : 상부 활주로
// F : 좌측 유도선X하부 주행로, G : 우측 유도선X하부 주행로, H : 하부 활주로
enum checkpoint{A, B, C, D, E, F, G, H};


//100초간의 타임테이블 제공
// 해당 시간에 해당 checkpoint를 점유하고 있는 항공기의 index를 저장한다.
// 0번, 1번 행은 taxiway 배열과 호환을 위한 만든 dummy row. 사용하지 않는다.
short timetable[8][DURATION]; 

//유도로 타임테이블. 상하로 모두 움직이기에, 튜플 형태의 자료구조 필요.
//row1 : A , row2 : B, tuple <first : 위로 올라가는 비행기 출발 gate 번호, second : 아래로 내려가는 비행기 출발 gate 번호>
pair<short, short> taxiway[2][DURATION]; 

struct airplane {
	bool status; //available : 사용하지 않는 비행기, busy : 운행중인 비행기
	char code[5]; //비행기 편명
	int gate; //몇 번 게이트에서 왔나
	int departure; //몇 시 출발 예정인가
	int case_type; //어떤 케이스를 이용하는가
	int current_location; //현 시점에서의 위치(0 : 게이트, 1 : 유도로, 2 : 주행로, 3 : 최종대기, 4 : 활주로, 5 : 이륙)
	short schedule[6]; //게이트 출발-유도선-주행로-최종대기(A의 경우 주행로와 동일)-활주로-이륙
};

char offset[5][6] = { //비행기가 다닐 때 거쳐가는 지점
	{0, 0, 0, 0, 0, 0},
	{0, 'A', 'C', 'C', 'E', 0},
	{0, 'A', 'F', 'F', 'H' ,0},
	{0, 'B', 'D', 'C', 'E', 0},
	{0, 'B', 'G', 'F', 'H', 0}
};

int latest; //현재 구성 된 비행기 중에서 가장 늦게 이륙하는 비행기의 이륙 시점
airplane plane[100]; //게이트 10대 + 유도로 3대 * 유도로 2개, index 1부터 시작
airplane landing_plane[2]; //착륙하는 비행기
int plane_index = 0; //plane index

bool gate[10]; //gate의 현재 사용 여부를 확인

void initialize();
void make_route(int index);
void prNewPlane(int index);
void makeNewPlane();

int main() {
	//gate 배정 단계에서 경로 확정
	srand((unsigned int)time(NULL));
	initialize();

	
	for (int t = 0; t < DURATION; t++) {
		//기존에 있던 비행기의 상태 업데이트를 진행한다.
		cout << "현재 시각 : " << t << endl;
		for (int i = 1; i <= 10; i++) {
			if (plane[i].status == busy) { //운행중인 비행기일 경우
				if (plane[i].schedule[plane[i].current_location] == t) {
					if (plane[i].current_location == 0) { //gate에서 빠져 나오고 있는 중이기에, gate flag을 최신화한다.
						gate[plane[i].gate] = available;
					}

					if (plane[i].current_location == 0) 
						cout << plane[i].code << "이(가) 게이트 " << plane[i].gate << "에서 후진하고 있습니다." << endl;
					else if (plane[i].current_location == 4) {
						cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
						cout << plane[i].code << "이(가) 이륙했습니다." << endl;
						cout << "이륙예정시각 : " << plane[i].departure << "   실제이륙시각 : " << plane[i].schedule[5] << endl;
						cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
					}
					else
						cout << plane[i].code << "이(가) " << offset[plane[i].case_type][plane[i].current_location] << "에서 " << offset[plane[i].case_type][plane[i].current_location + 1] << "로 이동중입니다." << endl;

					plane[i].current_location++; //비행기가 현재 향해 가고 있는 곳. 이 과정에서 변화 그린다.
					if (plane[i].current_location == 2 && (plane[i].case_type == 1 || plane[i].case_type == 2)) plane[i].current_location++; //최종 대기장소(index 2와 3)가 중복됨을 해결한다.

					if (plane[i].current_location == 5) {
						//비행기가 이륙했기에 다시 pool로 돌려보낸다.
						plane[i].status = available;
						available_plane.push(i);
					}
				}
			}
		}

		//새로운 비행기를 구성한다.
		//latest로부터 2초 이상 5초 이하로 떨어진 시점에 출발하는 비행기를 만든다.
		//비행기는 구성 시점에서 최적의 장소에 만든다.
		if (available_plane.size()>=3 && t%2) {
			int j;
			for (j = 0; j < 10; j++) {
				if (gate[j] == available) {
					break;
				}
			}
			if (j != 10) makeNewPlane();
			
		}
		cout << endl;
	}
}

void initialize() {
	for (int i = 0; i < 10; i++) { //모든 게이트가 초기에는 사용 가능한 상태로 만든다.
		gate[i] = available;
	}
	for (int i = 1; i <= 10; i++) { //모든 비행기가 초기에는 사용 가능한 상태로 만든다.
		available_plane.push(i);
		plane[i].status = available;
		for (int j = 0; j < 6; j++) { //모든 비행기의 경로도 초기화한다.
			plane[i].schedule[j] = -1;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < DURATION; j++) {
			timetable[i][j] = 0; //timetable을 초기화한다.
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < DURATION; j++) { //유도로 timetable을 초기화한다.
			taxiway[i][j].first = taxiway[i][j].second = -1;
		}
	}

	int initial_planes = rand() % 5 + 1; //처음에는 1개 ~ 5개의 비행기를 만든다.
	priority_queue<int> departure; //출발 시간 순서대로 뽑아내기 위해 우선순위 큐를 만든다.
	
	int temp;
	for (int i = 0; i < initial_planes; i++) { //처음에는 5초에서 10초 사이에 출발하는 비행기를 만든다.
		temp = rand() % 6 + 5;
		departure.push(-temp);
		//for debugging : heap input checking
		cout << i << " : " << temp << endl;
	}
	 
	//for debugging : heap searching
	//while (!departure.empty()) {
	//	cout << -departure.top() << endl;
	//	departure.pop();
	//}

	for (int i = 0; i < initial_planes; i++) { //초기 비행기에 대해 게이트를 배정한다. 이 단계에서 경로 확정이 일어난다.
		if (available_plane.empty()) break;
		temp = available_plane.front(); available_plane.pop();
		plane[temp].status = busy;
		plane[temp].departure = -departure.top(); //힙에 있는 초기 항공편 중 가장 이른 항공편의 출발 시각
		departure.pop();

		plane[temp].code[0] = 'S';
		plane[temp].code[1] = 'G';
		plane[temp].code[2] = rand() % 10 + '0';
		plane[temp].code[3] = rand() % 10 + '0';
		plane[temp].code[4] = rand() % 10 + '0';

		make_route(temp);
		plane[temp].current_location = 0;

		prNewPlane(temp);
		
	}
	latest = plane[initial_planes].schedule[5];

}

void make_route(int index)  //index : plane 배열 상에서의 plane 번호
{
	//왼쪽 상부, 왼쪽 하부, 우측 상부, 우측 하부를 모두 검사한다.
	//단, 루트에서 딜레이 없는(게이트 출발부터 이륙까지 3초 소요) 경로가 발생하면 우측은 검사하지 않는다.
	//같은 조건이라면, 상부 활주로를 이용하는 것을 선호한다.
	//딜레이가 최대한 없도록 만드는 것이 목표다.

	//제한조건 : 항공기 푸시백, 유도로 진입 과정에서는 절대 딜레이가 발생하지 않는다. 게이트에서 늦게 출발하는 방법으로 해결한다.

	int departure = plane[index].departure;
	int time; //각 경우에서 정시출발을 위해 출발해야 하는 마지노선 시각
	int candid[5]; //후보 게이트
	int test, i;

	deque<int> case1, case2, case3, case4; //각 이동 경로에 대해 case 저장
	
	//1. 왼쪽 상부 이동 판정
	for (i = 0; i <= 2; i++) { //후보 게이트를 선정한다.
		if (gate[i] == busy) continue;
		candid[1] = i; break;
	}
	if (i == 3) goto second;

	time = departure - 4; 
	for (time = departure - 4; time < DURATION ; time++) {
		if (taxiway[A][time].first != -1) continue; //위로 올라가는 비행기가 있다.
		if (taxiway[A][time].second != -1) { //아래로 내려오는 비행기가 있다.
			test = taxiway[A][time].second;
			if (test < candid[1]) continue; //아래로 내려오는 비행기가 더 위에 있는 게이트에서 출발한 비행기이다.
		}
		if (timetable[C][time + 2] != 0) continue; //주행로에 이미 비행기가 있다.
		break;
	}
	case1.push_back(time); //푸시백 및 유도로 진입 시작 시간을 저장한다.
	time++; //유도로 진입 완료 시각으로 바꾼다.
	case1.push_back(time); //유도로 진입 완료 시각을 저장한다. A에 있는 시각.
	time++; //주행로 진입 완료 시각으로 바꾼다.
	case1.push_back(time); //주행로 진입 완료 시각을 저장한다.
	time++;
	while (timetable[E][time] != 0) time++; //활주로가 비는 시각으로 바꾼다.
	case1.push_back(time); //활주로 진입 완료 시각을 저장한다.
	time++;
	/*착륙과 관련된 코드*/
	case1.push_back(time); //이륙 완료 시각을 저장한다. // 착륙 비행기 정해지면 이 부분 바꿀껏.

	if (time == departure) { //현재 케이스에서 최적의 경로가 구해짐.
		if (candid[1] == 2) goto second; //중간 게이트는 추후 다른 비행기를 딜레이 시킬 수 있다.

		plane[index].case_type = 1;

		for (i = case1[0]; i <= case1[1]; i++) { //푸시백, 유도로 진입
			taxiway[A][i].first = candid[1];
		}
		for (i = case1[2]; i < case1[3]; i++) { //유도로에서 대기
			timetable[C][i] = index;
		}
		for (i = case1[3]; i < case1[4]; i++) { //활주
			timetable[E][i] = index;
		}
		
		//비행기의 이동 스케쥴을 저장한다.
		plane[index].schedule[0] = case1[0];
		plane[index].schedule[1] = case1[1];
		plane[index].schedule[2] = case1[2];
		plane[index].schedule[3] = case1[2];
		plane[index].schedule[4] = case1[3];
		plane[index].schedule[5] = case1[4];


		gate[candid[1]] = busy; //게이트 사용 중임을 표시
		plane[index].gate = candid[1]; //비행기가 사용한 게이트
		return;
	}

second:;
	//2. 왼쪽 하부 이동 판정
	for (i = 4; i >= 2; i--) { //후보 게이트를 선정한다.
		if (gate[i] == busy) continue;
		candid[2] = i; break;
	}
	if (i == 1) goto third;

	time = departure - 4;
	for (time = departure - 4; time < DURATION ; time++) {
		if (taxiway[A][time].second != -1) continue; //아래로 내려오는 비행기가 있다.
		if (taxiway[A][time].first != -1) { //위로 올라가는 비행기가 있다.
			test = taxiway[A][time].first;
			if (test > candid[2]) continue; //위로 올라가는 비행기가 더 위에 있는 게이트에서 출발한 비행기이다.
		}
		if (timetable[F][time + 2] != 0) continue; //주행로에 이미 비행기가 있다.
		break;
	}
	case2.push_back(time); //푸시백 및 유도로 진입 시작 시간을 저장한다.
	time++; //유도로 진입 완료 시각으로 바꾼다.
	case2.push_back(time); //유도로 진입 완료 시각을 저장한다.
	time++; //주행로 진입 완료 시각으로 바꾼다.
	case2.push_back(time); //주행로 진입 완료 시각을 저장한다.
	time++;
	while (timetable[H][time] != 0) time++; //활주로가 비는 시각으로 바꾼다.
	case2.push_back(time); //활주로 진입 완료 시각을 저장한다.
	time++;
	/*착륙과 관련된 코드*/
	case2.push_back(time); //이륙 완료 시각을 저장한다. // 착륙 비행기 정해지면 이 부분 바꿀껏.

	if (time == departure) { //현재 케이스에서 최적의 경로가 구해짐.
		if (candid[2] == 2) goto third; //중간 게이트는 추후 다른 비행기를 딜레이 시킬 수 있다.

		plane[index].case_type = 2;

		for (i = case2[0]; i <= case2[1]; i++) { //푸시백, 유도로 진입
			taxiway[A][i].second = candid[2];
		}
		for (i = case2[2]; i < case2[3]; i++) { //유도로에서 대기
			timetable[F][i] = index;
		}
		for (i = case2[3]; i < case2[4]; i++) { //활주
			timetable[H][i] = index;
		}

		//비행기의 이동 스케쥴을 저장한다.
		plane[index].schedule[0] = case2[0];
		plane[index].schedule[1] = case2[1];
		plane[index].schedule[2] = case2[2];
		plane[index].schedule[3] = case2[2];
		plane[index].schedule[4] = case2[3];
		plane[index].schedule[5] = case2[4];

		gate[candid[2]] = busy; //게이트 사용 중임을 표시
		plane[index].gate = candid[2]; //비행기가 사용한 게이트
		return;
	}

third:;
	//3. 오른쪽 상부 이동 판정
	for (i = 5; i <= 7; i++) { //후보 게이트를 선정한다.
		if (gate[i] == busy) continue;
		candid[3] = i; break;
	}
	if (i == 8) goto fourth;

	time = departure - 5;
	for (time = departure - 5; time < DURATION ; time++) {
		if (taxiway[B][time].first != -1) continue; //위로 올라가는 비행기가 있다.
		if (taxiway[B][time].second != -1) { //아래로 내려오는 비행기가 있다.
			test = taxiway[B][time].second;
			if (test < candid[3]) continue; //아래로 내려오는 비행기가 더 위에 있는 게이트에서 출발한 비행기이다.
		}
		if (timetable[D][time + 2] != 0) continue; //주행로에 이미 비행기가 있다.
		break;
	}
	case3.push_back(time); //푸시백 및 유도로 진입 시작 시간을 저장한다.
	time++; //유도로 진입 완료 시각으로 바꾼다.
	case3.push_back(time); //유도로 진입 완료 시각을 저장한다.
	time++; //주행로(D) 진입 완료 시각으로 바꾼다.
	case3.push_back(time); //주행로(D) 진입 완료 시각을 저장한다.
	time++; 
	while (timetable[C][time] != 0) time++; //주행로(C)가 비는 시각으로 바꾼다.
	case3.push_back(time); //주행로(C) 진입 완료 시각을 저장한다.
	time++; 
	while (timetable[E][time] != 0) time++; //활주로가 비는 시각으로 바꾼다.
	case3.push_back(time); //활주로 진입 완료 시각을 저장한다.
	time++;
	/*착륙과 관련된 코드*/
	case3.push_back(time); //이륙 시각을 저장한다. // 착륙 비행기 정해지면 이 부분 바꿀껏.

	if (time == departure) { //현재 케이스에서 최적의 경로가 구해짐.
		if (candid[3] == 7) goto fourth; //중간 게이트는 추후 다른 비행기를 딜레이 시킬 수 있다.

		plane[index].case_type = 3;

		for (i = case3[0]; i <= case3[1]; i++) { //푸시백, 유도로 진입
			taxiway[B][i].first = candid[3];
		}
		for (i = case3[2]; i < case3[3]; i++) { //유도로(D)에서 대기
			timetable[D][i] = index;
		}
		for (i = case3[3]; i < case3[4]; i++) { //유도로(C)에서 대기
			timetable[C][i] = index;
		}
		for (i = case3[4]; i < case3[5]; i++) { //활주
			timetable[E][i] = index;
		}

		//비행기의 이동 스케쥴을 저장한다.
		plane[index].schedule[0] = case3[0];
		plane[index].schedule[1] = case3[1];
		plane[index].schedule[2] = case3[2];
		plane[index].schedule[3] = case3[3];
		plane[index].schedule[4] = case3[4];
		plane[index].schedule[5] = case3[5];

		gate[candid[3]] = busy; //게이트 사용 중임을 표시
		plane[index].gate = candid[3]; //비행기가 사용한 게이트
		return;
	}

fourth:;
	//4. 왼쪽 하부 이동 판정
	for (i = 9; i >= 7; i--) { //후보 게이트를 선정한다.
		if (gate[i] == busy) continue;
		candid[4] = i; break;
	}
	if (i == 6) goto finale;

	time = departure - 5;
	for (time = departure - 5; time < DURATION ; time++) {
		if (taxiway[B][time].second != -1) continue; //아래로 내려오는 비행기가 있다.
		if (taxiway[B][time].first != -1) { //위로 올라가는 비행기가 있다.
			test = taxiway[B][time].first;
			if (test > candid[4]) continue; //위로 올라가는 비행기가 더 위에 있는 게이트에서 출발한 비행기이다.
		}
		if (timetable[G][time + 2] != 0) continue; //주행로에 이미 비행기가 있다.
		break;
	}
	case4.push_back(time); //푸시백 및 유도로 진입 시작 시간을 저장한다.
	time++; //유도로 진입 완료 시각으로 바꾼다.
	case4.push_back(time); //유도로 진입 완료 시각을 저장한다.
	time++; //주행로(G) 진입 완료 시각으로 바꾼다.
	case4.push_back(time); //주행로(G) 진입 완료 시각을 저장한다.
	time++; 
	while (timetable[F][time] != 0) time++; //주행로(F)가 비는 시각으로 바꾼다.
	case4.push_back(time); //주행로(F) 진입 완료 시각을 저장한다.
	time++; 
	while (timetable[H][time] != 0) time++; //활주로가 비는 시각으로 바꾼다.
	case4.push_back(time); //활주로 진입 완료 시각을 저장한다.
	time++;
	/*착륙과 관련된 코드*/
	case4.push_back(time); //이륙 시각을 저장한다. // 착륙 비행기 정해지면 이 부분 바꿀껏.

	if (time == departure) { //현재 케이스에서 최적의 경로가 구해짐.
		if (candid[4] == 7) goto finale; //중간 게이트는 추후 다른 비행기를 딜레이 시킬 수 있다.

		plane[index].case_type = 4;

		for (i = case4[0]; i <= case4[1]; i++) { //푸시백, 유도로 진입
			taxiway[B][i].second = candid[4];
		}
		for (i = case4[2]; i < case4[3]; i++) { //유도로(G)에서 대기
			timetable[G][i] = index;
		}
		for (i = case4[3]; i < case4[4]; i++) { //유도로(F)에서 대기
			timetable[F][i] = index;
		}
		for (i = case4[4]; i < case4[5]; i++) { //활주
			timetable[H][i] = index;
		}
		
		//비행기의 이동 스케쥴을 저장한다.
		plane[index].schedule[0] = case4[0];
		plane[index].schedule[1] = case4[1];
		plane[index].schedule[2] = case4[2];
		plane[index].schedule[3] = case4[3];
		plane[index].schedule[4] = case4[4];
		plane[index].schedule[5] = case4[5];

		gate[candid[4]] = busy; //게이트 사용 중임을 표시
		plane[index].gate = candid[4]; //비행기가 사용한 게이트
		return;
	}

finale:; 
	//한 번에 가는 루트는 없고, 반드시 딜레이가 발생되거나, 중간 게이트가 최적인 경우임이다.
	//이 때는 case1 ~ 4 중에서 가장 소요시간이 짧은 경로를 선택해야 한다.

	int min; //몇 번째 케이스에 최적의 루트가 있는지 저장한다.
	int min_back = 999; //최적의 루트를 통해 이륙할 수 있는 시간을 저장한다.

	if (!case1.empty() && case1.back() < min_back) {
		min = 1;
		min_back = case1.back();
	}
	if (!case2.empty() && case2.back() < min_back) {
		min = 2;
		min_back = case2.back();
	} 
	if (!case3.empty() && case3.back() < min_back) {
		min = 3;
		min_back = case3.back();
	}
	if (!case4.empty() && case4.back() < min_back) {
		min = 4;
		min_back = case4.back();
	}

	if (min == 1) {
		for (i = case1[0]; i <= case1[1]; i++) { //푸시백, 유도로 진입
			taxiway[A][i].first = candid[1];
		}
		for (i = case1[2]; i < case1[3]; i++) { //유도로에서 대기
			timetable[C][i] = index;
		}
		for (i = case1[3]; i < case1[4]; i++) { //활주
			timetable[E][i] = index;
		}
		
		plane[index].case_type = 1;

		plane[index].schedule[0] = case1[0];
		plane[index].schedule[1] = case1[1];
		plane[index].schedule[2] = case1[2];
		plane[index].schedule[3] = case1[2];
		plane[index].schedule[4] = case1[3];
		plane[index].schedule[5] = case1[4];

		gate[candid[1]] = busy; //게이트 사용 중임을 표시
		plane[index].gate = candid[1]; //비행기가 사용한 게이트
	}

	else if (min == 2) {
		for (i = case2[0]; i <= case2[1]; i++) { //푸시백, 유도로 진입
			taxiway[A][i].second = candid[2];
		}
		for (i = case2[2]; i < case2[3]; i++) { //유도로에서 대기
			timetable[F][i] = index;
		}
		for (i = case2[3]; i < case2[4]; i++) { //활주
			timetable[H][i] = index;
		}

		plane[index].case_type = 2;

		plane[index].schedule[0] = case2[0];
		plane[index].schedule[1] = case2[1];
		plane[index].schedule[2] = case2[2];
		plane[index].schedule[3] = case2[2];
		plane[index].schedule[4] = case2[3];
		plane[index].schedule[5] = case2[4];

		gate[candid[2]] = busy; //게이트 사용 중임을 표시
		plane[index].gate = candid[2]; //비행기가 사용한 게이트
	}

	else if (min == 3) {
		for (i = case3[0]; i <= case3[1]; i++) { //푸시백, 유도로 진입
			taxiway[B][i].first = candid[3];
		}
		for (i = case3[2]; i < case3[3]; i++) { //유도로(D)에서 대기
			timetable[D][i] = index;
		}
		for (i = case3[3]; i < case3[4]; i++) { //유도로(C)에서 대기
			timetable[C][i] = index;
		}
		for (i = case3[4]; i < case3[5]; i++) { //활주
			timetable[E][i] = index;
		}

		plane[index].case_type = 3;

		//비행기의 이동 스케쥴을 저장한다.
		plane[index].schedule[0] = case3[0];
		plane[index].schedule[1] = case3[1];
		plane[index].schedule[2] = case3[2];
		plane[index].schedule[3] = case3[3];
		plane[index].schedule[4] = case3[4];
		plane[index].schedule[5] = case3[5];

		gate[candid[3]] = busy; //게이트 사용 중임을 표시
		plane[index].gate = candid[3]; //비행기가 사용한 게이트
	}

	else if (min == 4) {
		for (i = case4[0]; i <= case4[1]; i++) { //푸시백, 유도로 진입
			taxiway[B][i].second = candid[4];
		}
		for (i = case4[2]; i < case4[3]; i++) { //유도로(G)에서 대기
			timetable[G][i] = index;
		}
		for (i = case4[3]; i < case4[4]; i++) { //유도로(F)에서 대기
			timetable[F][i] = index;
		}
		for (i = case4[4]; i < case4[5]; i++) { //활주
			timetable[H][i] = index;
		}

		plane[index].case_type = 4;

		//비행기의 이동 스케쥴을 저장한다.
		plane[index].schedule[0] = case4[0];
		plane[index].schedule[1] = case4[1];
		plane[index].schedule[2] = case4[2];
		plane[index].schedule[3] = case4[3];
		plane[index].schedule[4] = case4[4];
		plane[index].schedule[5] = case4[5];
		gate[candid[4]] = busy; //게이트 사용 중임을 표시
		plane[index].gate = candid[4]; //비행기가 사용한 게이트
	}
}

void prNewPlane(int index) {
	cout << "-----------------------------------" << endl;
	cout << "새로운 비행기가 배정되었습니다." << endl;
	cout << "편명 : " << plane[index].code << endl;
	cout << "게이트 : " << plane[index].gate << endl;
	cout << "-----------------------------------" << endl;
}

void makeNewPlane() {
	//새로운 비행기를 구성한다.
	//latest로부터 2초 이상 5초 이하로 떨어진 시점에 출발하는 비행기를 만든다.
	//비행기는 구성 시점에서 최적의 장소에 만든다.
	int newplane; //새로운 비행기가 출발할 시각

	newplane = latest + rand() % 4 + 2;
	latest = newplane;
	
	int temp = available_plane.front(); available_plane.pop();
	plane[temp].status = busy;
	plane[temp].departure = newplane;

	plane[temp].code[0] = 'S';
	plane[temp].code[1] = 'G';
	plane[temp].code[2] = rand() % 10 + '0';
	plane[temp].code[3] = rand() % 10 + '0';
	plane[temp].code[4] = rand() % 10 + '0';

	make_route(temp);

	plane[temp].current_location = 0;

	prNewPlane(temp);
}