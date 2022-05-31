#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> map[203];
bool visited[203]; //축사 후보지를 가 봤는가?(오른쪽 노드들의 방문 여부)
int inRoom[203]; //index : 축사의 index, 내용 : 해당 축사에 있는 소의 index
int cows, rooms;

void initialize() {
	cin >> cows >> rooms;

	int iter, target;
	for (int i = 1; i <= cows; i++) {
		cin >> iter;
		for (int j = 0; j < iter; j++) {
			cin >> target;
			map[i].push_back(target);
		}
	}

	memset(inRoom, 0, sizeof(inRoom));
}

bool DFS(int cowNum) {
	for (const auto nextRoom : map[cowNum]) {
		/*
		A라는 소가 3번 축사로 가고싶어서 밀어내기를 연속한 결과 3-1-8-4-7로 탐색이 진행됐다고 하자.
		visited는 두 가지 목적을 위해 사용한다.

		1. 무한루프 방지
		8에 있던 소가 4로 밀려나고 4에 있던 소가 8로 밀려날 수 있는 상황이면, visited가 없으면 무한 루프가 발생할 것이다.
		즉, 그 자리에 있던 소가 밀려났는지를 표시하기 위해서 사용한다.

		2. 불필요한 연산 방지
		만약 위와 같은 탐색 결과 축사 배정이 실패해서 A가 8로 가려고 다시 평가하는 상황이라 가정하자.
		어차피 8-4-7로 가도 더 이상 막다른 경우의 수라는 것을 이미 구했기에, 더 이상 평가 할 필요가 없다.
		*/
		if (visited[nextRoom]) continue; //가 본 곳일 때
		visited[nextRoom] = true;

		if (inRoom[nextRoom] == 0 || DFS(inRoom[nextRoom])) { //다음 칸 안에 소가 없거나, 소를 밀어낼 수 있는 상황이라면.
			inRoom[nextRoom] = cowNum;
			return true;
		}
	}

	return false;
}

void operate() {
	int ans = 0; //축사에 들어갈 수 있는 소의 개수
	for (int i = 1; i <= cows; i++) {
		memset(visited, false, sizeof(visited));

		if (DFS(i)) ans++;
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}