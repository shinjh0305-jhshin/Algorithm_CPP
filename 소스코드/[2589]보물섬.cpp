//그래프 내에서 서로 연결되지 않은 노드가 없을 때는
//아무 노드에서 가장 멀리 있는 노드 구하고
//거기에서 가장 멀리 있는 노드를 구하면 정답이다.
//하지만 이번 경우는, 연결되지 않은 노드가 있기에, 하나씩 다 구해야 한다.
//최대 참조 : 50^4 = 6,250,000

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

char map[52][52];
bool visited[52][52] = { false };
int rows, cols;
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> rows >> cols; cin.get();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = cin.get();
		}
		cin.get();
	}
}

int DFS(int row, int col) {
	int round = -1, currow, curcol, nrow, ncol, sz_queue;
	queue<pair<int, int>> qu;

	qu.push({ row, col });
	visited[row][col] = true;

	while (!qu.empty()) {
		sz_queue = qu.size();

		for (int i = 0; i < sz_queue; i++) {
			currow = qu.front().first; curcol = qu.front().second; qu.pop();

			for (int iter = 0; iter < 4; iter++) {
				nrow = currow + drow[iter]; ncol = curcol + dcol[iter];

				if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || visited[nrow][ncol] || map[nrow][ncol] == 'W') continue;

				qu.push({ nrow, ncol });
				visited[nrow][ncol] = true;
			}
		}

		round++;
	}

	return round;
}

void operate() {
	int ans = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (map[i][j] == 'L') {
				ans = max(ans, DFS(i, j));
				memset(visited, false, sizeof(visited));
			}
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}