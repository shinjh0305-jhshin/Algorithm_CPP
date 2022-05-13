#include <iostream>
#include <algorithm>
#define INF 1234567890
using namespace std;

int N, M;
int dp[2][10005] = { 0 };
int memory[102], cost[102];
int cur = 0, previous = 1, sum = 0;

//Row : 탐색을 마친 앱의 개수, Col : 비용
//dp에는 Row개의 앱을 탐색했을 때, Col의 비용으로 얻을 수 있는 메모리의 최댓값을 적고,
//마지막 Row에서 M보다 크거나 같은 값이 나오는 Col 값이 정답이다.

void initialize() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> memory[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

}

void operate() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j < cost[i]) {
				dp[cur][j] = dp[previous][j];
			}
			else {
				dp[cur][j] = max(dp[previous][j - cost[i]] + memory[i], dp[previous][j]);
			}
		}
		swap(cur, previous);
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[previous][i] >= M) {
			cout << i << endl;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}