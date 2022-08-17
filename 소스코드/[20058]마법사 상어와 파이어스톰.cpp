#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int sz_map, rota;
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };
int map[2][70][70], iceAlone[70][70];
int previous = 0, current = 1;
bool visited[70][70] = { false };
vector<pair<int, int>> zeros;

void initialize() {
	cin >> sz_map >> rota;
	sz_map = pow(2, sz_map);

	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[current][i][j];
			if (map[current][i][j] == 0) {
				zeros.push_back({ i,j });
			}
		}
	}
	
	swap(previous, current);
}

void doRotate(int startRow, int startCol, int sz) {
	int nrow, ncol;
	for (int row = startRow; row < startRow + sz; row++) {
		for (int col = startCol; col < startCol + sz; col++) {
			nrow = startRow + col % sz;
			ncol = startCol + sz - 1 - row % sz;
			map[current][nrow][ncol] = map[previous][row][col];
		}
	}
}

void rotateMap(int sz) {
	for (int i = 0; i < sz_map; i += sz) {
		for (int j = 0; j < sz_map; j += sz) {
			doRotate(i, j, sz);
		}
	}
}

void rotateZeros(int sz) {
	int rowtemp, coltemp, currow, curcol;
	for (auto& it : zeros) {
		currow = it.first; curcol = it.second;
		rowtemp = currow - currow % sz + curcol % sz;
		coltemp = curcol - curcol % sz + sz - 1 - currow % sz;
		
		it.first = rowtemp; it.second = coltemp;
	}
}

void meltIce() {
	memset(iceAlone, 0, sizeof(iceAlone));

	int currow, curcol, nrow, ncol;
	for (const auto& it : zeros) {
		currow = it.first; curcol = it.second;
		for (int k = 0; k < 4; k++) {
			nrow = currow + drow[k]; ncol = curcol + dcol[k];

			if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map) continue;

			iceAlone[nrow][ncol]++;
		}
	}

	for (int i = 0; i < sz_map; i++) {
		iceAlone[i][0]++;
		iceAlone[i][sz_map - 1]++;
		iceAlone[0][i]++;
		iceAlone[sz_map - 1][i]++;
	}

	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			if (iceAlone[i][j] >= 2 && map[current][i][j]) {
				map[current][i][j]--;
				if (map[current][i][j] == 0) zeros.push_back({ i,j });
			}
		}
	}
}

int DFS(int row, int col) {
	int nrow, ncol;
	int ans = 1;

	visited[row][col] = true;
	for (int k = 0; k < 4; k++) {
		nrow = row + drow[k]; ncol = col + dcol[k];
		if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map || visited[nrow][ncol] || map[previous][nrow][ncol] == 0) continue;

		ans += DFS(nrow, ncol);
	}

	return ans;
}

void getAnswer() {
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			sum += map[previous][i][j];

			if (map[previous][i][j] && !visited[i][j]) {
				ans = max(ans, DFS(i, j));
			}
		}
	}

	cout << sum << endl << ans << endl;
}

void operate() {
	int sz;

	for (int i = 0; i < rota; i++) {
		cin >> sz;

		sz = pow(2, sz);

		rotateMap(sz);
		rotateZeros(sz);
		meltIce();

		swap(current, previous);
	}

	getAnswer();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}