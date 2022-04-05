#include <iostream>
#include <cstring>
#include <queue>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

short rows, cols;
short map[100][100], visited[100][100];
short drow[4] = { 1,0,-1,0 };
short dcol[4] = { 0,1,0,-1 };

struct info {
	short row, col;
	short history;
};

void initialize() {
	cin >> rows >> cols; cin.get();

	char temp;
	for (int i = 0; i < rows; i++) {
		memset(visited[i], 0, sizeof(short)*cols);
		memset(map[i], 0, sizeof(short)*cols);

		for (int j = 0; j < cols; j++) {
			temp = cin.get();
			map[i][j] = temp - '0';
		}
		cin.get();
	}
}

void operate() {
	queue<info> qu;
	qu.push({ 0,0,1 });
	visited[0][0] = 1;

	short curRow, curCol, curHistory, nextRow, nextCol;
	while (1) {
		curRow = qu.front().row;
		curCol = qu.front().col;
		curHistory = qu.front().history;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			nextRow = curRow + drow[i];
			nextCol = curCol + dcol[i];

			if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols || !map[nextRow][nextCol] || visited[nextRow][nextCol]) continue;

			if (nextCol == cols - 1 && nextRow == rows - 1) {
				cout << curHistory + 1 << endl;
				return;
			}

			visited[nextRow][nextCol] = 1;
			qu.push({ nextRow, nextCol, curHistory + 1 });
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();
	return 0;
}