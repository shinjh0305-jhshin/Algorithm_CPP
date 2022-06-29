#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int map[2][300][300];
int rows, cols, totalIce = 0, previous = 0, cur = 1;
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };
bool visited[300][300];

void initialize() {
	cin >> rows >> cols;

	int temp;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> map[previous][i][j];
			totalIce++;
		}
	}
}

bool meltIce(int row, int col) {
	int nrow, ncol, currow, curcol;

	queue<pair<int, int>> qu; //row, col
	memcpy(map[cur], map[previous], sizeof(map[previous])); //결과 빙산을 이전 빙산에서 갖고온다.
	memset(visited, false, sizeof(visited));

	qu.push({ row, col });
	visited[row][col] = true;

	while (!qu.empty()) {
		currow = qu.front().first; curcol = qu.front().second; qu.pop();
		
		for (int i = 0; i < 4; i++) {
			nrow = currow + drow[i]; ncol = curcol + dcol[i];
			if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || visited[nrow][ncol]) continue;
			
			if (map[previous][nrow][ncol] == 0) map[cur][currow][curcol]--;
			else {
				visited[nrow][ncol] = true;
				qu.push({ nrow, ncol });
			}
		}

		if (map[cur][currow][curcol] < 0) map[cur][currow][curcol] = 0; //음수면 0으로 보정
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (map[previous][i][j] && !visited[i][j]) return false; //가야하는 빙산인데 안 갔다.
		}
	}

	swap(previous, cur);
	return true;
}

void operate() {
	for (int time = 0; ; time++) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (map[previous][i][j]) {
					if (meltIce(i, j)) {
						goto next;
					}
					else {
						cout << time << endl;
						return;
					}
				}
			}
		}
		cout << 0 << endl; //다 녹을때까지 빙산이 분리되지 않은 경우.
		return;
	next:;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	initialize();
	operate();

	return 0;
}