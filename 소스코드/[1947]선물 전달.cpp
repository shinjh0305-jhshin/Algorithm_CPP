#include <iostream>
#define MOD 1000000000
#define ll long long
using namespace std;

ll dp[1000005];
int sz_dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> sz_dp;
	dp[0] = 0; dp[1] = 0; dp[2] = 1;

	for (int i = 3; i <= sz_dp; i++) {
		dp[i] = ((i - 1)*(dp[i - 2] + dp[i - 1])) % MOD;
	}

	cout << dp[sz_dp] << endl;

	return 0;
}