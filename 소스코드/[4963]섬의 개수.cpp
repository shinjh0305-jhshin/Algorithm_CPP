#include <iostream>
#include <stack>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

short map[52][52];
int rows, cols;
int drow[8] = { 1,1,0,-1,-1,-1,0,1 };
int dcol[8] = { 0,-1,-1,-1,0,1,1,1 };

void DFS(int row, int col) {
	int nrow, ncol;
	
	map[row][col] = 0;

	for (int i = 0; i < 8; i++) {
		nrow = row + drow[i]; ncol = col + dcol[i];
		if (nrow < 0 || nrow > rows || ncol < 0 || ncol > cols || !map[nrow][ncol]) continue;

		DFS(nrow, ncol);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans;
	while (1) {
		cin >> cols >> rows; cin.get();
		if (rows == 0 && cols == 0) return 0;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin >> map[i][j]; cin.get();
			}
		}
		
		ans = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (map[i][j]) {
					DFS(i, j);
					ans++;
				}
			}		
		}

		cout << ans << endl;
	}
}