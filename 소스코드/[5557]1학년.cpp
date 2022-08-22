#include <iostream>
#define ll long long
using namespace std;

ll dp[102][22]; //100개의 숫자, 0~20까지

void operate() {
	int len;
	cin >> len;

	int target;

	cin >> target;
	dp[0][target] = 1; //initialize

	for (int idx = 1; idx < len - 1; idx++) {
		cin >> target;

		for (int i = 0; i <= 20; i++) {
			if (!dp[idx - 1][i]) continue;

			if (i - target >= 0) dp[idx][i - target] += dp[idx - 1][i];
			if (i + target <= 20) dp[idx][i + target] += dp[idx - 1][i];
		}

	}

	cin >> target;
	cout << dp[len - 2][target];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}