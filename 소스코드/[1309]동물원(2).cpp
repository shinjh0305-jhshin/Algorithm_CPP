#include <iostream>
#define MOD 9901
using namespace std;

int dp[100002][3];
enum status { none, _left, _right };
int sz;

void initialize() {
	cin >> sz;
	dp[1][none] = dp[1][_left] = dp[1][_right] = 1;
}

void operate() {
	for (int i = 2; i <= sz; i++) {
		//현재 상태에 따라 가능한 이전 상태를 확인한다.
		dp[i][none] = (dp[i - 1][_left] + dp[i - 1][_right] + dp[i - 1][none]) % MOD;
		dp[i][_left] = (dp[i - 1][none] + dp[i - 1][_right]) % MOD;
		dp[i][_right] = (dp[i - 1][none] + dp[i - 1][_left]) % MOD;
	}

	int ans = 0;
	for (int i = 0; i < 3; i++) {
		ans += dp[sz][i];
	}
	cout << ans % MOD << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}