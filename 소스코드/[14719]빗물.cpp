#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][503] = { 0 };
int height, width;

void operate() {
	cin >> height >> width;
	for (int i = 0; i < width; i++) {
		cin >> dp[0][i];
	}
	
	for (int i = 1; i < width; i++) {
		dp[1][i] = max(dp[1][i - 1], dp[0][i - 1]);
	}
	for (int i = width - 2; i >= 0; i--) {
		dp[2][i] = max(dp[2][i + 1], dp[0][i + 1]);
	}

	int ans = 0;
	for (int i = 0; i < width; i++) {
		int minimum = min(dp[1][i], dp[2][i]);
		if (minimum > dp[0][i]) {
			ans += minimum - dp[0][i];
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}