#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rawdata;
int sz_rawdata;
int dp[3][301]; //0 : 이번 계단은 안 밟는다  1 : 이번 계단을 밟으면 1번 연속으로 밟는거다  2 : ...2번 연속으로 밟는거다

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	dp[0][0] = 0; dp[1][0] = rawdata[0]; dp[2][0] = 0;
}

void operate() {
	for (int i = 1; i < sz_rawdata; i++) {
		//이번 계단을 안 밟는 경우. 2계단 이상 못 뛰어넘기에 dp[0][i-1]은 고려 대상이 아니다.
		dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]);

		//이번 계단을 밟으면 1계단 연속으로 밟는 경우
		dp[1][i] = dp[0][i - 1] + rawdata[i];

		//이번 계단을 밟으면 2계단 연속으로 밟는 경우
		dp[2][i] = dp[1][i - 1] + rawdata[i];
	}

	cout << max(dp[1][sz_rawdata - 1], dp[2][sz_rawdata - 1]) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
6
123
14
3
2
13
4
ans : 143
*/