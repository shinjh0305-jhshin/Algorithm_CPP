#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2134567890
#define endl "\n"
using namespace std;

int dp[100003][5][5] = { 0 };
int cost[5][5] = {
	{0,2,2,2,2},
	{0,1,3,4,3},
	{0,3,1,3,4},
	{0,4,3,1,3},
	{0,3,4,3,1}
};
vector<int> mov;

void initialize() {
	int temp;
	while (1) {
		cin >> temp;
		if (temp == 0) break;
		mov.push_back(temp);
	}

	for (int i = 0; i < mov.size(); i++) {
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				dp[i][m][n] = INF;
			}
		}
	}
}

void getMin(int left, int right, int idx) { //각 발이 left, right에 있을 때, mov[idx]로 움직일 수 있는 최솟값 구하기.
	int target = mov[idx];
	
	//왼발 움직이기
	if (target != right) { //왼발-오른발 안 겹칠 때
		dp[idx][target][right] = min(dp[idx][target][right], dp[idx - 1][left][right] + cost[left][target]);
	}

	//오른발 움직이기
	if (target != left) {
		dp[idx][left][target] = min(dp[idx][left][target], dp[idx - 1][left][right] + cost[right][target]);
	}
}

int operate() {
	int sz_mov = mov.size(), ans = INF;
	if (sz_mov == 0) return 0;
	else if (sz_mov == 1) return 2;

	dp[0][mov[0]][0] = dp[0][0][mov[0]] = 2; //초기화!

	for (int i = 1; i < sz_mov; i++) {
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				if (dp[i - 1][m][n] != INF) {
					getMin(m, n, i);

					if (i == sz_mov - 1) {
						ans = min(ans, min(dp[i][mov[i]][n], dp[i][m][mov[i]]));
					}
				}
			}
		}
	}

	
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	cout << operate() << endl;

	return 0;
}