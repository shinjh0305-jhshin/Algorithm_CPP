#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define WALL '#'
#define EMPTYSET "........"
using namespace std;

vector<string> map(8);
int drow[9] = { 0,1,1,0,-1,-1,-1,0,1 }, dcol[9] = { 0,0,-1,-1,-1,0,1,1,1 };

bool operate() {
	for (int i = 0; i < 8; i++) {
		cin >> map[i];
	}

	queue<pair<int, int>> qu; //row, col;
	qu.push({ 7,0 });

	int sz_qu, currow, curcol, nrow, ncol;
	bool isPossible = false, isEmptyAbove;

	for (int i = 0; ; i++) {
		sz_qu = qu.size();
		if (qu.empty()) return false;

		while (sz_qu--) {
			currow = qu.front().first; curcol = qu.front().second;
			qu.pop();

			if (map[currow][curcol] == WALL) continue; //현재 내 위치가 벽이다.

			isEmptyAbove = true;
			for (int k = 0; k < currow; k++) {
				if (map[k] != EMPTYSET) {
					isEmptyAbove = false;
					break;
				}
			}
			if (isEmptyAbove) return true; //내 위로 더 이상 벽이 없다.

			for (int k = 0; k < 9; k++) {
				nrow = currow + drow[k]; ncol = curcol + dcol[k];
				if (nrow < 0 || nrow >= 8 || ncol < 0 || ncol >= 8 || map[nrow][ncol] == WALL) continue;
				if (nrow == 0 && ncol == 7) return true; //종료 지점 도착
				qu.push({ nrow, ncol });
			}
		}

		for (int k = 6; k >= 0; k--) {
			map[k + 1] = map[k];
		}
		map[0] = EMPTYSET;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << operate() << endl;

	return 0;
}