#include <iostream>
#include <algorithm>
using namespace std;

int rows, cols;
bool hasOne = false;
int map[1003][1003];
int dp[1003][1003];

void initialize() {
	cin >> rows >> cols; cin.get();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = cin.get() - '0';
			if (map[i][j]) hasOne = true;
		}
		cin.get();
	}

	for (int i = 0; i < rows; i++) {
		dp[i][cols - 1] = map[i][cols - 1];
	}
	for (int j = 0; j < cols; j++) {
		dp[rows - 1][j] = map[rows - 1][j];
	}
}

void operate() {
	int sz, ans = -1;

	if (rows == 1 || cols == 1) {
		if (hasOne) cout << 1 << endl;
		else cout << 0 << endl;
		return;
	}

	for (int row = rows - 2; row >= 0; row--) {
		for (int col = cols - 2; col >= 0; col--) {
			if (map[row][col] == 0) dp[row][col] = 0;
			else {
				sz = min(dp[row + 1][col], dp[row][col + 1]);
				for (int i = sz; i >= 0; i--) {
					if (map[row + i][col + i] == 1) {
						dp[row][col] = i + 1;
						break;
					}
				}
				ans = max(ans, dp[row][col] * dp[row][col]);
			}
		}
	}

	if (ans == -1) {
		if (hasOne) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}