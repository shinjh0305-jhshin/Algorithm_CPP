#include <iostream>
using namespace std;

void operate() {
	int dp[13];
	dp[0] = 1; dp[1] = 1; dp[2] = 2;

	for (int i = 3; i <= 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int cases, query;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> query;
		cout << dp[query] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}