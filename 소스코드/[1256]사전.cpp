#include <iostream>
#include <cmath>
#include <string>
#define MIN -1
#define INF 2134567890
using namespace std;

string st = "";
int dp[203][203];
int N, M, K;

void initialize() {
	cin >> N >> M >> K;
	
	for (int i = 0; i <= N + M; i++) {
		for (int j = 0; j <= N + M; j++) {
			dp[i][j] = MIN;
		}
	}
}

int getCombination(int n, int r) {
	if (r >= n / 2) r = n - r;

	if (r == 0) return 1;
	if (r == 1) return n;
	if (dp[n][r] != MIN) return dp[n][r];

	int ret1 = getCombination(n - 1, r - 1);
	int ret2 = getCombination(n - 1, r);

	if (ret1 == INF || ret2 == INF || ret1 + ret2 > 1000000000) return dp[n][r] = INF;
	else return dp[n][r] = ret1 + ret2;
}

void makeString(int leftA, int leftZ, int sizeToGo) {
	if (leftA == 0 && leftZ == 0) return;

	int combination = getCombination(leftA + leftZ - 1, leftZ);
	if (combination >= sizeToGo) {
		st += 'a';
		makeString(leftA - 1, leftZ, sizeToGo);
	}
	else {
		st += 'z';
		makeString(leftA, leftZ - 1, sizeToGo - combination);
	}
}

void operate() {
	if (getCombination(N + M, M) < K) {
		cout << -1 << endl;
		return;
	}

	makeString(N, M, K);
	cout << st << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}