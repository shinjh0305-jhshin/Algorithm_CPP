/*
LIS는 그리디한 성질을 갖고있다.
즉, 길이가 5인 LIS의 경우, 5번째 숫자가 가장 작게 끝나는 수열이
반드시 LIS가 된다.
그러므로, 길이가 N인 배열을 만들어서
각 INDEX에 해당되는 길이의 LIS의 가장 끝 값을 저장하도록 하면 된다.
*/

#include <iostream>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> rawdata;
vector<int> dp;
int sz;

void initialize() {
	cin >> sz;
	rawdata.resize(sz);
	dp.resize(sz);

	for (int i = 0; i < sz; i++) {
		cin >> rawdata[i];
	}

	dp[0] = rawdata[0];
}

void update(int left, int right, int target) {
	int mid;

	while (left < right) {
		mid	= (left + right) / 2;

		if (dp[mid] == target) return;

		if (dp[mid] > target) right = mid;
		else left = mid + 1;
	}

	dp[left] = target;
}

void operate() {
	int idx = 0, right = 1;

	for (int i = 1; i < sz; i++) {
		if (rawdata[i] > dp[idx]) {
			dp[++idx] = rawdata[i];
		}
		else {
			update(0, idx, rawdata[i]);
		}
	}

	cout << idx + 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	operate();

	return 0;
}