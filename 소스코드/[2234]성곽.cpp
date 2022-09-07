#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int rows, cols;
int map[55][55];
int drow[4] = { 0,-1,0,1 }, dcol[4] = { -1,0,1,0 };
int visited[55][55];
int sz_room[2505];

void initialize() {
	cin >> cols >> rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> map[i][j];
		}
	}
}

int DFS(int row, int col, int idx) {
	visited[row][col] = idx;

	int nrow, ncol, ret = 1;

	for (int k = 0; k < 4; k++) {
		if ((map[row][col] & (1 << k)) != 0) { //wall
			continue;
		}
		nrow = row + drow[k]; ncol = col + dcol[k];

		if (visited[nrow][ncol]) continue;

		ret += DFS(nrow, ncol, idx);
	}

	return ret;
}

int collapse() {
	int nrow, ncol;
	int maxSize = -1;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = 2; k < 4; k++) { //동, 남 계산
				if ((map[i][j] & (1 << k)) == 0) continue; //벽이 없다
				
				nrow = i + drow[k]; ncol = j + dcol[k];

				if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols) continue; //지도 밖으로 나간다
				if (visited[i][j] == visited[nrow][ncol]) continue; //서로 같은 방에 속해 있다

				maxSize = max(maxSize, sz_room[visited[i][j]] + sz_room[visited[nrow][ncol]]);
			}
		}
	}

	return maxSize;
}

void operate() {
	int rooms = 0, maxSize = -1;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (!visited[i][j]) {
				sz_room[rooms] = DFS(i, j, ++rooms);
				maxSize = max(maxSize, sz_room[rooms]);	
			}
		}
	}

	int maxCollapseSize = collapse();

	cout << rooms << endl << maxSize << endl << maxCollapseSize;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}