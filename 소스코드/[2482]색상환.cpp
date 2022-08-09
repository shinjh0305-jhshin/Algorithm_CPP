#include <iostream>
#define MOD 1000000003
using namespace std;

int colors, choice;
int dp[1005][1005]; //colors, choice

void initialize() {
	cin >> colors >> choice;
}

void operate() {
	if (choice > colors / 2) {
		cout << 0 << endl;
		return;
	}

	for (int i = 1; i <= colors; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= colors; i++) {
		for (int j = 2; j <= choice; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	int ans = (dp[colors - 1][choice] + dp[colors - 3][choice - 1]) % MOD; //N번째 안 칠하는 경우 + 칠하는 경우

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}