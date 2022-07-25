/*
0. 1의 번호를 가진 어른 상어는 가장 강력해서 나머지 모두를 쫓아낼 수 있다.
1. 먼저 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다
2. 그런 칸이 없으면 자신의 냄새가 있는 칸의 방향으로 잡는다.
3. 가능한 칸이 여러 개일때는 특정한 우선순위를 따른다
3-1. 우선순위는 상어마다 다를 수 있고, 같은 상어라도 현재 상어가 보고 있는 방향에 따라 또 다를 수 있다
4. 이동 후 상어의 방향은 방금 이동한 방향으로 바뀐다.
5. 자신의 냄새를 이동한 칸에 뿌린다. 냄새는 상어가 k번 이동하고 나면 사라진다.
6. 한 칸에 여러 마리의 상어가 남아 있으면, 가장 작은 번호를 가진 상어만 남고 나머지는 죽는다.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define EMPTY 0
#define INF 10
using namespace std;

int drow[5] = { 0,-1,1,0,0 }; //상 하 좌 우 순서
int dcol[5] = { 0,0,0,-1,1 };

struct info {
	pair<int, int> pos;
	int dir;
};

pair<int, int> smell[22][22]; //상어의 index, 상어가 뿌린 냄새의 유효기간
int priority[403][6][6]; //상어index, 상어방향, 우선순위방향
info shark[403];
int map[2][22][22]; //각 좌표에 있는 상어 index
int sz_map, sharks, leftshark, valid;
int current = 0, after = 1;


void initialize() {
	cin >> sz_map >> sharks >> valid;
	leftshark = sharks;

	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[current][i][j];
			if (map[current][i][j] != EMPTY) {
				shark[map[current][i][j]].pos = { i, j };
				smell[i][j] = { map[current][i][j], valid };
			}
		}
	}
	swap(current, after);

	for (int i = 1; i <= sharks; i++) {
		cin >> shark[i].dir;
	}

	for (int i = 1; i <= sharks; i++) {
		for (int dir = 1; dir <= 4; dir++) {
			for (int pdir = 0; pdir < 4; pdir++) {
				cin >> priority[i][dir][pdir];
			}
		}
	}
}

void operate() {
	int clk = 0;
	int currow, curcol, nrow, ncol, curdir;

	while (leftshark > 1 && clk <= 1000) {
		clk++;
		memset(map[current], 0, sizeof(map[current]));

		for (int i = 1; i <= sharks; i++) {
			if (shark[i].dir == INF) continue;

			const info& curShark = shark[i];
			currow = curShark.pos.first; curcol = curShark.pos.second; curdir = curShark.dir;

			bool foundEmptySpace = false;
			for (int k = 0; k < 4; k++) {
				nrow = currow + drow[priority[i][curdir][k]]; ncol = curcol + dcol[priority[i][curdir][k]];

				if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map) continue;

				if (smell[nrow][ncol].second < clk) { //빈 칸 혹은 냄새가 없어진 칸 혹은 먼저 도착한 상어를 쫓아낼 수 있다.
					foundEmptySpace = true;
					if (map[current][nrow][ncol]) { //이미 도착한 상어의 번호가 더 작다. 현재 상어가 쫓겨난다.
						shark[i].dir = INF;
						leftshark--;
						break;
					}					
					
					smell[nrow][ncol].second = 0; //해당 칸의 냄새를 초기화하고
					map[current][nrow][ncol] = i; //현재 상어가 위치한 것으로 표기한다.

					shark[i].pos = { nrow, ncol }; //현재 상어의 정보를 업데이트한다
					shark[i].dir = priority[i][curdir][k];

					break;
				}
			}

			if (!foundEmptySpace) { //빈 칸을 못 찾아서 내 냄새가 나는 칸을 찾아야 한다.
				for (int k = 0; k < 4; k++) {
					nrow = currow + drow[priority[i][curdir][k]]; ncol = curcol + dcol[priority[i][curdir][k]];

					if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map) continue;

					if (smell[nrow][ncol].first == i) { //내 냄새가 나는 칸 찾음
						map[current][nrow][ncol] = i; //현재 상어가 위치한 것으로 표기한다.

						shark[i].pos = { nrow, ncol }; //현재 상어의 정보를 업데이트한다
						shark[i].dir = priority[i][curdir][k];
						break;
					}
				}
			}
		}

		for (int i = 1; i <= sharks; i++) { //냄새 뿌리기
			if (shark[i].dir == INF) continue; //없어진 상어!
			const info& curShark = shark[i];
			currow = curShark.pos.first; curcol = curShark.pos.second;

			smell[currow][curcol] = { i, clk + valid };
		}

		swap(current, after);
	}
	
	if (clk > 1000) cout << -1 << endl;
	else cout << clk << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}