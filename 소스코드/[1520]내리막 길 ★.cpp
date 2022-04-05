#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int map[502][502];
int dp[502][502];
int rows, cols;

int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,1,0,-1 };

void initialize() {
	cin >> rows >> cols;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}	
}

int DFS(int row, int col) {
	int nrow, ncol, temp;

	if (row == rows - 1 && col == cols - 1) return 1;
	if (dp[row][col] != -1) return dp[row][col];

	dp[row][col] = 0;

	for (int i = 0; i < 4; i++) {
		nrow = row + drow[i]; ncol = col + dcol[i];

		if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] >= map[row][col]) continue;

		dp[row][col] += DFS(nrow, ncol);
	}
	return dp[row][col];
}

void operate() {
	cout << DFS(0, 0) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}
