#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int rawdata[1002][1002];
int dp[1002][1002];
int rows, cols;
int drow[3] = { 0,1,1 };
int dcol[3] = { 1,1,0 };

void initialize() {
	cin >> rows >> cols;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> rawdata[i][j];
			dp[i][j] = 0;
		}
	}
}

void operate() {
	int currow, curcol, nrow, ncol, temp;
	dp[0][0] = rawdata[0][0];

	for (currow = 0; currow < rows; currow++) {
		for (curcol = 0; curcol < cols; curcol++) {

			for (int i = 0; i < 3; i++) {
				nrow = currow + drow[i]; ncol = curcol + dcol[i];

				if (nrow >= rows || ncol >= cols) continue;

				temp = dp[currow][curcol] + rawdata[nrow][ncol];
				if (temp > dp[nrow][ncol]) {
					dp[nrow][ncol] = temp;
				}
			}

		}
	}

	cout << dp[rows - 1][cols - 1] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}