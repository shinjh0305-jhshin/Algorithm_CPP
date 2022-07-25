#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<pair<int, int>, int> candidate; //좌표값, 친구 숫자
int favor[23][5]; //학생 번호, 학생 선호 1~4
bool seatTaken[22][22] = {false};
pair<int, int> seat[450]; //seat[studnet] = seatnumber
int sz_map, students;

int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> sz_map;
	students = sz_map * sz_map;

	for (int i = 0; i < students; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> favor[i][j];
		}
	}
}

void operate() {
	//첫 번째 학생은 항상 2,2에 앉는다
	seatTaken[2][2] = true;
	seat[favor[0][0]] = { 2,2 };

	int currow, curcol, nrow, ncol, curmax, curBlank, tempBlank;
	for (int i = 1; i < students; i++) {
		candidate.clear();
		int curStudent = favor[i][0];
		for (int j = 1; j <= 4; j++) {
			int favorStudent = favor[i][j];
			if (seat[favorStudent] == make_pair(0, 0)) continue; //선호하는 친구의 좌석은 아직 배정 이전임

			currow = seat[favorStudent].first;
			curcol = seat[favorStudent].second;

			for (int k = 0; k < 4; k++) {
				nrow = currow + drow[k];
				ncol = curcol + dcol[k];

				if (nrow < 1 || nrow > sz_map || ncol < 1 || ncol > sz_map || seatTaken[nrow][ncol]) continue;

				candidate[{nrow, ncol}]++;
			}
		}
		curmax = 0; curBlank = 0;

		c
		for (const auto& it : candidate) {
			if (it.second > curmax) { //인접한 친구 숫자가 더 많은 칸 발견!
				curmax = it.second;
				currow = it.first.first;
				curcol = it.first.second;

				curBlank = 0;
				for (int k = 0; k < 4; k++) { //인접한 칸 중에서 빈 칸 개수 센다
					nrow = currow + drow[k];
					ncol = curcol + dcol[k];

					if (!seatTaken[nrow][ncol]) curBlank++;
				}

			}
			else if (it.second == curmax) { //인접한 친구 숫자가 같다. 2번 조건 검사
				tempBlank = 0;
				for (int k = 0; k < 4; k++) {
					nrow = it.first.first + drow[k];
					ncol = it.first.second + dcol[k];

					if (!seatTaken[nrow][ncol]) tempBlank++;
				}
				
				if (tempBlank > curBlank) { //빈 칸이 더 많은 칸 발견!
					currow = it.first.first;
					curcol = it.first.second;
					curBlank = tempBlank;
				}
				else if (curBlank == tempBlank) { //인접한 칸 중에서 비어있는 칸의 개수도 똑같다
					if (currow > it.first.first || ((currow == it.first.first) && curcol > it.first.second)) {
						currow = it.first.first;
						curcol = it.first.second;
					}
				}
			}
		}

	}

}