#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][100005]; //숫자 안 뺀 것, 숫자 1개 뺀 것
int rawdata[100005];
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	dp[0][0] = dp[1][0] = rawdata[0];
}

void operate() {
	int maxNum = rawdata[0];

	for (int i = 1; i < sz_rawdata; i++) {
		//dp[0] : 앞에 있는 연속합에 날 붙이는게 좋을지, 내가 새로운 연속합을 시작하는게 좋을지
		dp[0][i] = max(dp[0][i - 1] + rawdata[i], rawdata[i]);
		//dp[1] : 앞에 있는 연속합이 최선인거는 알겠다. 만약에 나를 빼면...?? 나중에 더 좋아질까...?? 
		dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + rawdata[i]); //나를 뺀 것과, 이미 뭔가 빠진 역사에 날 추가시키는 것 중 최댓값
		maxNum = max(maxNum, max(dp[0][i], dp[1][i]));
	}

	cout << maxNum << endl;
}	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}