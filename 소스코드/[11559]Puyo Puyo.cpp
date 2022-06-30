#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char field[12][6];
bool visited[12][6] = { false };
int numburst = 0;
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };
queue<pair<int, int>> qu; //row, col

void initialize() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			field[i][j] = cin.get();
		}
		cin.get();
	}
}

void DFS(int row, int col, char target) {
	visited[row][col] = true;
	qu.push({ row, col });

	int nrow, ncol;
	for (int k = 0; k < 4; k++) {
		nrow = row + drow[k];
		ncol = col + dcol[k];

		if (nrow < 0 || nrow >= 12 || ncol < 0 || ncol >= 6 || visited[nrow][ncol] || field[nrow][ncol] != target) continue;

		DFS(nrow, ncol, target);
	}
}

void gravitate() {
	char temp;
	int rowMov;
	for (int row = 10; row >= 0; row--) {
		for (int col = 0; col < 6; col++) {
			if (field[row][col] != '.') {
				temp = field[row][col];
				rowMov = row;
				while (rowMov + 1 <= 11 && field[rowMov + 1][col] == '.') {
					field[rowMov][col] = '.';
					rowMov++;
				}
				field[rowMov][col] = temp;
			}
		}
	}
}

void operate() {
	bool bursted;
	while (1) {
		memset(visited, false, sizeof(visited));
		bursted = false;

		for (int row = 11; row >= 0; row--) {
			for (int col = 0; col < 6; col++) {
				if (field[row][col] != '.' && !visited[row][col]) {
					DFS(row, col, field[row][col]);

					if (qu.size() >= 4) {
						bursted = true; //뿌요뿌요 연쇄가 진행되었다.
						while (!qu.empty()) { //방문했던 모든 노드를 .으로 바꾼다.
							field[qu.front().first][qu.front().second] = '.';
							qu.pop();
						}
					}
					else {
						while (!qu.empty()) qu.pop(); //큐를 비운다.
					}
				}
			}
		}

		if (bursted) {
			numburst++;
			gravitate(); //아래로 내린다.
		}
		else {
			cout << numburst << endl;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}