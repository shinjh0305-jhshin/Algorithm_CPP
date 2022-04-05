#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
#define wall -2
#define available -1
#pragma warning (disable:4996)
using namespace std;

vector<int> map[1003];
queue<pair<int, int>> qu;
int drow[4] = { 0,1,0,-1 };
int dcol[4] = { 1,0,-1,0 };
int rows, cols, max_mov;
int row_st, row_fin, col_st, col_fin;

void initialize() {
	int temp;
	cin >> rows >> cols >> max_mov; cin.get();
	for (int i = 1; i <= rows; i++) {
		map[i].resize(cols + 1);

		for (int j = 1; j <= cols; j++) {
			temp = cin.get();
			if (temp == '.') map[i][j] = available;
			else map[i][j] = wall;
		}

		cin.get();
	}

	cin >> row_st >> col_st >> row_fin >> col_fin;

	map[row_st][col_st] = 0;
	qu.push({ row_st,col_st });
}

void BFS() {
	int currow, curcol, nrow, ncol;

	while (!qu.empty()) {
		currow = qu.front().first; curcol = qu.front().second; qu.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= max_mov; j++) {
				nrow = currow + drow[i] * j; ncol = curcol + dcol[i] * j;
				
				if (nrow<1 || nrow>rows || ncol<1 || ncol>cols || map[nrow][ncol] == wall || (map[nrow][ncol] >= 0 && map[nrow][ncol] <= map[currow][curcol])) break;

				if (map[nrow][ncol] == available) {
					qu.push({ nrow, ncol });
					map[nrow][ncol] = map[currow][curcol] + 1;
				}
			}
		}
	}

	cout << map[row_fin][col_fin] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	BFS();

	return 0;
}
