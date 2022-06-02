#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#define endl "\n"
using namespace std;

string st1, st2;
int lenSt1, lenSt2;
int dp[1003][1003];

void initialize() {
	cin >> st1 >> st2;
	lenSt1 = st1.length(); 
	lenSt2 = st2.length();

	st1 = '0' + st1;
	st2 = '0' + st2;

	for (int i = 0; i < lenSt1; i++) dp[i][0] = 0;
	for (int i = 0; i < lenSt2; i++) dp[0][i] = 0;
}

void operate() {
	//row´Â st1, colÀº st2´Ù.

	for (int row = 1; row <= lenSt1; row++) {
		for (int col = 1; col <= lenSt2; col++) {
			if (st1[row] == st2[col]) dp[row][col] = dp[row - 1][col - 1] + 1;
			else dp[row][col] = max(dp[row][col - 1], dp[row - 1][col]);
		}
	}
	cout << dp[lenSt1][lenSt2] << endl;
	if (dp[lenSt1][lenSt2] == 0) return;

	stack<char> st;
	int row = lenSt1, col = lenSt2;
	while (row > 0 && col > 0) {
		if (st1[row] == st2[col]) {
			st.push(st1[row]);
			row--; col--;
		}
		else {
			if (dp[row][col] == dp[row][col - 1]) col--;
			else row--;
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}