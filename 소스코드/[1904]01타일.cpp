#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int dp[1000005];
int mod = 15746;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1; dp[2] = 2;

	int target;
	cin >> target;

	for (int i = 3; i <= target; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
	}

	cout << dp[target] << endl;
	return 0;
}