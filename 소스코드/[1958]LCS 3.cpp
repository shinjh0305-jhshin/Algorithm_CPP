#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

string s1, s2, s3;
int len_s1, len_s2, len_s3;
int dp[102][102][102];

void initialize() {
	cin >> s1 >> s2 >> s3;

	len_s1 = s1.length();
	len_s2 = s2.length();
	len_s3 = s3.length();

	for (int i = 0; i < 102; i++) {
		dp[i][0][0] = dp[0][i][0] = dp[0][0][i] = 0;
	}
}

void operate() {
	for (int i = 1; i <= len_s1; i++) {
		for (int j = 1; j <= len_s2; j++) {
			for (int k = 1; k <= len_s3; k++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}

	cout << dp[len_s1][len_s2][len_s3] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}