#include <iostream>
#define endl "\n"
using namespace std;

pair<int, int> dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };
int sz_map, target;
int map[1002][1002];

void operate() {
	cin >> sz_map >> target;
	int curdir = 0, currow = 0, curcol = 0, targetrow, targetcol, nrow, ncol;
	int curnum = sz_map * sz_map;

	while (curnum != 0) {
		map[currow][curcol] = curnum;
		if (curnum == target) {
			targetrow = currow + 1; targetcol = curcol + 1;
		}

		nrow = currow + dir[curdir].first; ncol = curcol + dir[curdir].second;
		if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map || map[nrow][ncol] != 0) {
			curdir = curdir == 3 ? 0 : curdir + 1;
			nrow = currow + dir[curdir].first; ncol = curcol + dir[curdir].second;
		}

		currow = nrow; curcol = ncol;
		curnum--;
	}

	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}

	cout << targetrow << ' ' << targetcol;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}