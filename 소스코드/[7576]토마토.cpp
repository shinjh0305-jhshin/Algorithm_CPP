#include <iostream>
#include <queue>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

enum status { blank = -1, unripen };
struct pos {
	int row, col;
};
int graph[1002][1002];

class tomato {
private:
	queue<pos> qu;
	int rows, cols, days = 0, remaining = 0; //days : 걸리는 총 일수, remaining : 남아 있는 안 익은 토마토
	int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };

public:
	void initialize() {
		cin >> cols >> rows; cin.get();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin >> graph[i][j]; cin.get();

				if (graph[i][j] > unripen) qu.push({ i, j });
				else if (graph[i][j] == unripen) remaining++;
			}
		}
	}

	void operate() {
		BFS();
		if (remaining != 0) cout << -1 << endl;
		else cout << days - 1 << endl;
	}

	void BFS() {
		int curRow, curCol, curDays, nRow, nCol;
		
		while (!qu.empty()) {
			curRow = qu.front().row; curCol = qu.front().col, curDays = graph[curRow][curCol]; 
			qu.pop();

			days = max(days, curDays);

			for (int i = 0; i < 4; i++) {
				nRow = curRow + drow[i]; nCol = curCol + dcol[i]; 
				if (nRow < 0 || nRow >= rows || nCol < 0 || nCol >= cols || graph[nRow][nCol] != unripen) continue;
				qu.push({ nRow, nCol }); graph[nRow][nCol] = curDays + 1; remaining--;
			}
		}

	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tomato op;
	op.initialize();
	op.operate();
	return 0;
}