#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int houses;
int prices[1001][3], dp[1001][3];
enum color { R, G, B };

void initialize() {
	cin >> houses;
	for (int i = 0; i < houses; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> prices[i][j]; 
		}
	}
	for (int i = 0; i < 3; i++) {
		dp[0][i] = prices[0][i]; 
	}
}

void operate() {
	//가능한 이전 단계 색깔 중 최솟값에 자신의 색칠 비용을 더한다
	for (int i = 1; i < houses; i++) {
		dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + prices[i][R];
		dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + prices[i][G];
		dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + prices[i][B];
	}

	int result = 1234567890;
	for (int i = 0; i < 3; i++) { //결과 중 최솟값을 구한다
		result = min(result, dp[houses - 1][i]);
	}

	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}