#include <iostream>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int map[500][500];
int visited[500][500];
int drow[4] = { 0,1,0,-1 };
int dcol[4] = { 1,0,-1,0 };
int sz_data;

void initialize() {
	cin >> sz_data;
	
	for (int i = 0; i < sz_data; i++) {
		for (int j = 0; j < sz_data; j++) {
			cin >> map[i][j];
			visited[i][j] = -1;
		}
	}
}

int DFS(int row, int col) {
	int nrow, ncol, curMax, temp;

	curMax = 1; //map[row][col]에 넣을 값(정답)
	for (int i = 0; i < 4; i++) {
		nrow = row + drow[i]; ncol = col + dcol[i];

		if (nrow < 0 || nrow >= sz_data || ncol < 0 || ncol >= sz_data || map[nrow][ncol] <= map[row][col]) continue;

		if (visited[nrow][ncol] == -1) {
			temp = 1 + DFS(nrow, ncol);
		}
		else {
			temp = 1 + visited[nrow][ncol];
		}
		curMax = max(curMax, temp);
	}

	return visited[row][col] = curMax;
}

void operate() {
	int result_max = -1;
	for (int i = 0; i < sz_data; i++) {
		for (int j = 0; j < sz_data; j++) {
			if (visited[i][j] == -1) DFS(i, j);
			result_max = max(result_max, visited[i][j]);
		}
	}
	cout << result_max << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();
	
	return 0;
}