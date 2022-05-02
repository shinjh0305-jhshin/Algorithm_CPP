#include <iostream>
using namespace std;

long long int dp[101][10];
long long int mod = 1000000000;

int main() {
	int i, mov = 1, trail, num;
	long long int sum = 0;

	cin >> num;
	for (i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	while (mov != num) {
		trail = mov;
		mov++;
		for (i = 0; i < 10; i++) {
			if (i == 0) dp[mov][0] = dp[trail][1];
			else if (i == 9) dp[mov][9] = dp[trail][8];
			else dp[mov][i] = (dp[trail][i - 1] + dp[trail][i + 1]) % mod;
		}
	}

	for (i = 0; i < 10; i++) {
		sum += dp[num][i];
	}
	cout << sum % mod << endl;
	return 0;
}