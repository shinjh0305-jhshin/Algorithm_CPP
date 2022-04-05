#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

char map[21][21];
bool visited[27] = { false };
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

int DFS(int row, int col, int result) {
	char ch;
	bool deadend = true; //더 이상 갈 수 없는 막다른 길인지
	int temp = 0, subtemp, nrow, ncol;

	visited[map[row][col] - 'A'] = true; 

	for (int i = 0; i < 4; i++) {
		nrow = row + drow[i]; ncol = col + dcol[i];

		if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols) continue;

		ch = map[nrow][ncol]; ch -= 'A';
		if (visited[ch] == false) {
			deadend = false; //막다른 길이 아니다.
			visited[ch] = true;
			subtemp = DFS(nrow, ncol, result + 1);
			visited[ch] = false;

			temp = max(temp, subtemp);
		}
	}

	if (deadend == true) return result;
	return temp;
}

void operate() {
	cout << DFS(0, 0, 1) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();
	return 0;
}
