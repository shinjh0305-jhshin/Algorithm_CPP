#include <iostream>
#include <algorithm>
#define endl "\n"
#define INF 1234567890
using namespace std;

enum shin {
	ERASE, RESTORE
};
int map[10][10];
int ans = INF;
int leftPapers[6] = { 0,5,5,5,5,5 };

void initialize() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
}


bool isPossible(int size, int row, int col) {
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (map[i][j] == 0 || i >= 10 || j >= 10) return false;
		}
	}
	return true;
}

void change(int op, int size, int row, int col) {
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			map[i][j] = op;
		}
	}
}

void stickPaper(int row, int col, int papers) {
	if (papers >= ans) return;

	for (; row < 10; row++) {
		for (; col < 10; col++) {
			if (map[row][col]) {
				for (int i = 5; i >= 1; i--) {
					if (leftPapers[i] && isPossible(i, row, col)) {
						change(ERASE, i, row, col);
						leftPapers[i]--;

						stickPaper(row, col + 1, papers + 1);

						leftPapers[i]++;
						change(RESTORE, i, row, col);
					}
				}
				return;
			}
		}
		col = 0;
	}

	ans = min(ans, papers);
}

void operate() {
	stickPaper(0, 0, 0);
	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}