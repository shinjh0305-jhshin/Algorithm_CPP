#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int sz, iter;
int dp[1030][1030];

void initialize() {
	cin >> sz >> iter;

	int num;
	for (int row = 0; row <= sz; row++) {
		for (int col = 0; col <= sz; col++) {
			if (row * col == 0) {
				dp[row][col] = 0;
			}
			else {
				cin >> num;
				dp[row][col] = dp[row - 1][col] + dp[row][col - 1] - dp[row - 1][col - 1] + num;
			}
		}
	}
}

void operate() {
	int x1, y1, x2, y2;

	while (iter--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	operate();

	return 0;
}