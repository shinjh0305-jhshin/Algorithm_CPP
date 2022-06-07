/*
가장 작은 빌딩을 붙이는 경우로 생각해본다. (N = 5, L = 3, R = 2로 가정)
경우 1 : N = 4, L = 2, R = 2인 상황에서 맨 왼쪽에 빌딩이 붙는 경우
경우 2 : N = 4, L = 3, R = 1인 상황에서 맨 오른쪽에 빌딩이 붙는 경우
경우 3 : N = 4, L = 3, R = 2인 상황에서 사이사이에 빌딩이 들어가는 경우 N - 1군데 배치 가능.

제일 작은 빌딩이 들어가면 사이사이에 가려져서 빌딩이 절대 보이지 않게 되므로,
경우 3을 구현하기가 쉬워진다.
*/

#include <iostream>
#define MOD 1000000007
using namespace std;

long long dp[102][102][102] = { 0 }; //dp[N개 건물][왼쪽에서 보이는 건물 개수][오른쪽에서 보이는 건물 개수]
int L, R, N;

void operate() {
	cin >> N >> L >> R;
	dp[1][1][1] = 1; 

	for (int num = 2; num <= N; num++) {
		for (int left = 1; left <= L; left++) {
			for (int right = 1; right <= R; right++) {
				dp[num][left][right] = 
					(dp[num - 1][left - 1][right] + dp[num - 1][left][right - 1] + dp[num - 1][left][right] * (num - 2)) % MOD;
			}
		}
	}

	cout << dp[N][L][R] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}