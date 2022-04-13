#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int rawdata[4003][4003];
string st1, st2; //st1 : row, st2 : col
int len_st1, len_st2;

void initialize() {
	cin >> st1 >> st2;

	len_st1 = st1.length();
	len_st2 = st2.length();

	for (int i = 0; i <= len_st1; i++) {
		rawdata[0][i] = 0;
	}
	for (int i = 0; i < len_st2; i++) {
		rawdata[i][0] = 0;
	}
}

void operate() {
	int ans = 0;

	for (int row = 1; row <= len_st1; row++) {
		for (int col = 1; col <= len_st2; col++) {
			if (st1[row - 1] == st2[col - 1]) {
				rawdata[row][col] = rawdata[row - 1][col - 1] + 1;
				ans = max(ans, rawdata[row][col]);
			}
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}