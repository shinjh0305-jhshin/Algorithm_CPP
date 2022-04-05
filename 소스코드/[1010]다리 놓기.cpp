#include <iostream>
#include <ctime>
#define endl "\n"
using namespace std;

int cases;
int rHistory = 0, cHistory = 0; //계산 완료 된 행 열 index
int dp[32][32] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cases, rTarget, cTarget;

	cin >> cases; cin.get();

	for (int i = 1; i <= 29; i++) dp[1][i] = i; //초기화

	for (int i = 2; i <= 29; i++) {
		for (int j = i; j <= 29; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < cases; i++) {
		cin >> rTarget >> cTarget; cin.get();
		cout << dp[rTarget][cTarget] << endl;
	}

	return 0;

}