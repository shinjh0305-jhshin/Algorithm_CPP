#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

string s1, s2;
int len_s1, len_s2;
int dp[1002][1002];

void initialize() {
	getline(cin, s1);
	getline(cin, s2);

	len_s1 = s1.length();
	len_s2 = s2.length();

	for (int i = 0; i <= len_s2; i++)
		dp[0][i] = 0;

	for (int i = 0; i <= len_s1; i++) 
		dp[i][0] = 0;
	
}

void operate() {
	for (int row = 1; row <= len_s1; row++) {
		for (int col = 1; col <= len_s2; col++) {
			if (s1[row - 1] == s2[col - 1]) dp[row][col] = dp[row - 1][col - 1] + 1;
			else dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
		}
	}

	cout << dp[len_s1][len_s2] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}
/*
ALURKT
ALBAKYOT
*/