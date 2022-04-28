#include <iostream>
using namespace std;
long long int dp[91][2];

int main() {
	int mov = 1, num, trail;
	dp[1][0] = 0; dp[1][1] = 1;

	cin >> num;
	while (mov != num) {
		trail = mov;
		mov++;
		dp[mov][0] = dp[trail][0] + dp[trail][1];
		dp[mov][1] = dp[trail][0];
	}
	cout << dp[num][0] + dp[num][1] << endl;
	return 0;
}