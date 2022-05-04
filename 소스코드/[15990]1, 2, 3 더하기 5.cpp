#include <stdio.h>
#pragma warning (disable:4996)

long long dp[100001][3]; //각 열은 마지막으로 더해진 숫자를 의미한다.
long long mod = 1000000009;

int main() {
	int cases, i, current_max = 3;
	scanf("%d", &cases); getchar();

	dp[1][0] = 1; dp[1][1] = 0; dp[1][2] = 0;
	dp[2][0] = 0; dp[2][1] = 1; dp[2][2] = 0;
	dp[3][0] = 1; dp[3][1] = 1; dp[3][2] = 1;

	int num;
	long long sum;
	for (i = 0; i < cases; i++) {
		scanf("%d", &num); getchar();

		sum = 0;
		if (num > current_max) {
			while (current_max != num) {
				current_max++;
				dp[current_max][0] = (dp[current_max - 1][1] + dp[current_max - 1][2]) % mod;
				dp[current_max][1] = (dp[current_max - 2][0] + dp[current_max - 2][2]) % mod;
				dp[current_max][2] = (dp[current_max - 3][0] + dp[current_max - 3][1]) % mod;
			}
		}
		sum = dp[num][0] + dp[num][1] + dp[num][2];
		printf("%lld\n", sum % mod);
	}
}