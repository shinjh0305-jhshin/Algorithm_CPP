#include <iostream>
#include <string>
#define ll long long
#define MOD 1000000
using namespace std;

ll dp[2][5003]; //dp[0] : 앞 숫자와 연계됨, dp[1] : 앞 숫자와 연계하지 않음.
string rawdata;

void operate() {
	cin >> rawdata;

	if (rawdata[0] == '0') { //impossible
		cout << 0;
		return;
	}
	int len = rawdata.length();

	rawdata = '0' + rawdata;

	dp[0][0] = 1; dp[1][0] = 0; //dummy data(used for 2nd character of string)
	dp[1][0] = 0; dp[1][1] = 1;

	for (int i = 2; i <= len; i++) {
		int temp = (rawdata[i - 1] - '0') * 10 + (rawdata[i] - '0');

		if (temp == 0 || (rawdata[i] == '0' && temp > 26)) {
			cout << 0;
			return;
		}

		if (rawdata[i - 1] != '0' && temp <= 26) {
			dp[0][i] = (dp[0][i - 2] + dp[1][i - 2]) % MOD;
		}
		
		if (rawdata[i] != '0') dp[1][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
	}

	cout << (dp[0][len] + dp[1][len]) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}