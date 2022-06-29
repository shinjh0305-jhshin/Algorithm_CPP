#include <iostream>
#include <cstring>
#include <queue>
#define node 103
#define endl "\n"
using namespace std;

bool visited[node][node];
int rows, cols, leftCheeze = 0;
int map[node][node];
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> rows >> cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> map[i][j];
			if (map[i][j]) leftCheeze++;
		}
	}
}

int meltCheeze() {
	int melted = 0;
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> qu; //row, col
	
	qu.push({ 0,0 });
	visited[0][0] = true;

	int nrow, ncol, currow, curcol;
	
	while (!qu.empty()) {
		currow = qu.front().first; curcol = qu.front().second; qu.pop();

		for (int i = 0; i < 4; i++) {
			nrow = currow + drow[i]; ncol = curcol + dcol[i];
			
			if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || visited[nrow][ncol]) continue;

			visited[nrow][ncol] = true;
			if (map[nrow][ncol]) { //공기중에 노출된 치즈일 경우
				melted++;
				map[nrow][ncol] = 0;
			}
			else { //공기일 경우에만 push
				qu.push({ nrow, ncol });
			}
		}
	}

	return melted;
}

void operate() {
	int melted, time = 1;
	while (1) {
		melted = meltCheeze();

		if (leftCheeze == melted) {
			cout << time << endl << melted << endl;
			return;
		}
		else {
			leftCheeze -= melted;
		}

		time++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}