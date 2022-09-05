#include <iostream>
#include <deque>
#include <vector>
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

struct info { //말의 번호와 방향
	int idx, dir;
};
pair<int, int> pos[15]; //말의 위치 row, col
int drow[4] = { 0,0,-1,1 }, dcol[4] = { 1,-1,0,0 };
deque<info> map[15][15]; //말 저장소
int mapColor[15][15], changeDir[4] = { 1,0,3,2 };
int sz_map, horses;

void initialize() {
	cin >> sz_map >> horses;
	for (int i = 1; i <= sz_map; i++) {
		for (int j = 1; j <= sz_map; j++) {
			cin >> mapColor[i][j];
		}
	}

	int row, col, dir;
	for (int i = 0; i < horses; i++) {
		cin >> row >> col >> dir;
		pos[i] = { row, col };
		map[row][col].push_back({ i, dir - 1 });
	}
}

void popHorse(int currow, int curcol, int nrow, int ncol) {
	deque<info>& curSlot = map[currow][curcol];

	while (!curSlot.empty()) {
		const auto& temp = curSlot.front();
		pos[temp.idx] = { nrow, ncol };
		map[nrow][ncol].push_back({ temp.idx, temp.dir });
		curSlot.pop_front();
	}
}

void popInverseHorse(int currow, int curcol, int nrow, int ncol) {
	deque<info>& curSlot = map[currow][curcol];

	while (!curSlot.empty()) {
		const auto& temp = curSlot.back();
		pos[temp.idx] = { nrow, ncol };
		map[nrow][ncol].push_back({ temp.idx, temp.dir });
		curSlot.pop_back();
	}
}


bool moveHorse() {
	int currow, curcol, curdir, nrow, ncol, ndir;

	for (int i = 0; i < horses; i++) {
		currow = pos[i].first; curcol = pos[i].second;
		deque<info>& curSlot = map[currow][curcol];

		if (curSlot.front().idx != i) continue; //가장 아래에 있는 말이 아니다

		curdir = curSlot.front().dir; //현재 말의 방향
		nrow = currow + drow[curdir]; ncol = curcol + dcol[curdir]; //현재 말의 방향에 따른 다음 위치

		if (nrow <= 0 || nrow > sz_map || ncol <= 0 || ncol > sz_map || mapColor[nrow][ncol] == BLUE) { //다음 위치가 outofbound거나 blue일 경우
			ndir = changeDir[curdir];
			nrow = currow + drow[ndir]; ncol = curcol + dcol[ndir];

			curSlot.front().dir = ndir; //일단 방향을 바꿔준다.

			if (nrow <= 0 || nrow > sz_map || ncol <= 0 || ncol > sz_map || mapColor[nrow][ncol] == BLUE) continue;
			else if (mapColor[nrow][ncol] == RED) popInverseHorse(currow, curcol, nrow, ncol); 
			else if (mapColor[nrow][ncol] == WHITE) popHorse(currow, curcol, nrow, ncol);
		}
		else if (mapColor[nrow][ncol] == RED) popInverseHorse(currow, curcol, nrow, ncol);
		else popHorse(currow, curcol, nrow, ncol);

		if (map[nrow][ncol].size() >= 4) return true;
	}

	return false;
}

void operate() {
	int turn = 1;
	while (turn <= 1000) {
		if (moveHorse()) {
			cout << turn;
			return;
		}
		turn++;
	}
	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}