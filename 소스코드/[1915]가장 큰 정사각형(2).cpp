#include <iostream>
#include <algorithm>
using namespace std;

int rows, cols;
int dp[1003][1003];
bool hasOne = false;

void initialize() {
	cin >> rows >> cols; cin.get();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			dp[i][j] = cin.get() - '0';
			if (dp[i][j]) hasOne = true;
		}
		cin.get();
	}
}

void operate() {
	int sz = -1;

	for (int i = 1; i < rows; i++) {
		for (int j = 1; j < cols; j++) {
			if (dp[i][j]) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				sz = max(sz, dp[i][j]);
			}
		}
	}

	if (sz == -1 && !hasOne) cout << 0 << endl;
	else {
		cout << sz * sz << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
3 3
000
000
000
ans : 0

3 3
000
000
100
ans : 1

3 3
110
100
000
ans : 1

3 3
111
101
111
ans : 1

4 4
0110
0000
0000
0000
ans: 1

3 1
0
1
1
ans : 1

1 1
1
ans : 1

3 3
011
111
111
ans : 4
*/