#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define endl "\n"
using namespace std;

int rows, cols;
int rawdata[1005][1005];
int result[1005][1005];
int group[1005][1005] = { 0 };
int inGroup[1000005];
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> rows >> cols;
	string st;
	for (int i = 0; i < rows; i++) {
		cin >> st;
		for (int j = 0; j < cols; j++) {
			rawdata[i][j] = st[j] - '0';
		}
	}
}

void BFS(int row, int col, int idx) {
	queue<pair<int, int>> bfsqu;
	bfsqu.push({ row,col });
	group[row][col] = idx;
	inGroup[idx]++;

	int currow, curcol, nrow, ncol;
	while (!bfsqu.empty()) {
		currow = bfsqu.front().first; curcol = bfsqu.front().second;
		bfsqu.pop();

		for (int k = 0; k < 4; k++) {
			nrow = currow + drow[k]; ncol = curcol + dcol[k];
			if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || rawdata[nrow][ncol] == 1 || group[nrow][ncol]) continue;

			group[nrow][ncol] = idx;
			inGroup[idx]++;
			bfsqu.push({ nrow, ncol }); 
		}
	}
}

void makeGroup() {
	int groupIdx = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (rawdata[i][j] == 0 && !group[i][j]) {
				BFS(i, j, groupIdx++);
			}
		}
	}
}

void getResult() {
	int nrow, ncol;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (rawdata[i][j] == 1) {
				result[i][j] = 1;
				vector<int> visited;

				for (int k = 0; k < 4; k++) {
					nrow = i + drow[k]; ncol = j + dcol[k];
					if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || rawdata[nrow][ncol] == 1) continue;
					if (find(visited.begin(), visited.end(), group[nrow][ncol]) != visited.end()) continue;

					visited.push_back(group[nrow][ncol]);
					result[i][j] += inGroup[group[nrow][ncol]];
					result[i][j] %= 10;
				}
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << result[i][j];
		}
		cout << endl;
	}
}

void operate() {
	makeGroup();
	getResult();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}