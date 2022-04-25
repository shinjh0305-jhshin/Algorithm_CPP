#include <iostream>
#include <vector>
#define endl "\n"
#define INF 1234567890
using namespace std;

struct info {
	int _3kg, _5kg;
};
vector<info> dp;
int sz_dp;

void initialize() {
	cin >> sz_dp;
	dp.resize(sz_dp + 1);
	dp[0] = { 0,0 };
	dp[1] = { -1,-1 };
	dp[2] = { -1,-1 };
}

void operate() {
	info temp3, temp5;
	int sum3, sum5;

	for (int i = 3; i <= sz_dp; i++) {
		if (i >= 3 && dp[i - 3]._3kg != -1) { //3kg으로 만들 수 있는 경우
			temp3 = { dp[i - 3]._3kg + 1, dp[i - 3]._5kg };
			sum3 = temp3._3kg + temp3._5kg;
		}
		else {
			temp3 = { -1,-1 };
			sum3 = INF;
		}

		if (i >= 5 && dp[i - 5]._5kg != -1) { //5kg으로 만들 수 있는 경우
			temp5 = { dp[i - 5]._3kg, dp[i - 5]._5kg + 1 };
			sum5 = temp5._3kg + temp5._5kg;
		}
		else {
			temp5 = { -1,-1 };
			sum5 = INF;
		}

		if (sum3 < sum5) dp[i] = temp3;
		else dp[i] = temp5;
	}

	if (dp[sz_dp]._3kg == -1) cout << -1 << endl;
	else cout << dp[sz_dp]._3kg + dp[sz_dp]._5kg << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

