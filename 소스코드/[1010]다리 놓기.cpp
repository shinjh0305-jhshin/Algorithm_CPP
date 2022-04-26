#include <iostream>
#include <ctime>
#define endl "\n"
using namespace std;

int dp[32][32] = { 0 }; //ROW : 왼쪽 마을의 개수, COL : 오른쪽 마을의 개수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cases, rTarget, cTarget;

	cin >> cases; cin.get();

	//왼쪽 마을이 1개일 때는 오른쪽 마을의 개수만큼 경우의 수가 생긴다.
	for (int i = 1; i <= 29; i++) dp[1][i] = i; //초기화

	for (int i = 2; i <= 29; i++) { //왼쪽 마을의 최대 개수만큼 미리 작업해둔다.
		for (int j = i; j <= 29; j++) { //오른쪽 마을이 왼쪽 마을의 개수부터 최대 개수까지 늘어난다.
			//dp[i][j]는 dp[i-1][j-1]부터 dp[i-1][1]까지 더한 값인데,
			//dp[i-1][j-2]부터 dp[i-1][1]까지 더한 값은 dp[i][j-1]에 저장되어 있기에 이를 가져다 쓴다.
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < cases; i++) {
		cin >> rTarget >> cTarget; cin.get();
		cout << dp[rTarget][cTarget] << endl;
	}

	return 0;

}