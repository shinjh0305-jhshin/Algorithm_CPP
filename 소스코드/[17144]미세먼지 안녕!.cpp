#include <iostream>
#include <cstring>
#define endl "\n"
using namespace std;

int map[2][52][52];
int curMap = 0, nextMap = 1; //map 상에서의 index
int rows, cols, iter;
pair<int, int> refresher[2];
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> rows >> cols >> iter;

	int refresh = 0;
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			cin >> map[curMap][i][j];
			if (map[curMap][i][j] == -1) {
				refresher[refresh++] = { i ,j };
			}
		}
	}
}

void cleanAir() {
	//upper half
	for (int i = refresher[0].first - 1; i > 1; i--) { //left side
		map[curMap][i][1] = map[curMap][i - 1][1];
	}
	for (int i = 1; i < cols; i++) { //top side
		map[curMap][1][i] = map[curMap][1][i + 1];
	}
	for (int i = 1; i < refresher[0].first; i++) { //right side
		map[curMap][i][cols] = map[curMap][i + 1][cols];
	}
	for (int i = cols; i > 2; i--) { //bottom side
		map[curMap][refresher[0].first][i] = map[curMap][refresher[0].first][i - 1];
	}
	map[curMap][refresher[0].first][2] = 0;

	//lower half
	for (int i = refresher[1].first + 1; i < rows; i++) { //left side
		map[curMap][i][1] = map[curMap][i + 1][1];
	}
	for (int i = 1; i < cols; i++) { //bottom side
		map[curMap][rows][i] = map[curMap][rows][i + 1];
	}
	for (int i = rows; i > refresher[1].first; i--) { //right side
		map[curMap][i][cols] = map[curMap][i - 1][cols];
	}
	for (int i = cols; i > 2; i--) { //top side
		map[curMap][refresher[1].first][i] = map[curMap][refresher[1].first][i - 1];
	}

	map[curMap][refresher[1].first][2] = 0;
}

void diffuse() {
	memset(map[nextMap], 0, sizeof(map[nextMap]));

	int nrow, ncol, qty;
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			if (map[curMap][i][j] >= 5) {
				qty = map[curMap][i][j] / 5;

				for (int k = 0; k < 4; k++) {
					nrow = i + drow[k]; ncol = j + dcol[k];
					if (nrow < 1 || nrow > rows || ncol < 1 || ncol > cols || map[curMap][nrow][ncol] == -1) continue;
					map[nextMap][nrow][ncol] += qty;
					map[curMap][i][j] -= qty;
				}
			}
			map[nextMap][i][j] += map[curMap][i][j];
		}
	}

	swap(curMap, nextMap);
}

void operate() {
	for (int i = 0; i < iter; i++) {
		diffuse();
		cleanAir();
	}

	int sum = 0;
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			sum += map[curMap][i][j];
		}
	}
	cout << sum + 2 << endl; //공기청정기의 index인 -1을 두 개 더한다
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
3 3 7
0 30 7
-1 10 0
-1 0 20

7 8 3
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
*/