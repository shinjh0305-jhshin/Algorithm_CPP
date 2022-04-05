#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int dp[1003][1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0][0] = 1;

	int n, k, mod = 10007;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][i] = 1;

		for (int j = 1; j < i; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
	}

	cout << dp[n][k] << endl;

	return 0;
}