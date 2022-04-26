#include <iostream>
#include <vector>
#include <algorithm>
#define DIV3(a) (((a) % 3) ? false : true)
#define DIV2(a) (((a) % 2) ? false : true)
using namespace std;

vector<int> dp(1000003);

void operate() {
	int sz;
	cin >> sz;

	dp[1] = 0;
	for (int i = 2; i <= sz; i++) {
		dp[i] = 2134567890;
		if (DIV3(i)) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (DIV2(i)) dp[i] = min(dp[i], dp[i / 2] + 1);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	cout << dp[sz] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}