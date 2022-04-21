#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl "\n"
using namespace std;

int sz_rawdata, idx = 0;
vector<int> rawdata, dp, LIS;

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);
	LIS.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void print_result() {
	cout << dp.size() << endl;

	stack<int> st;
	int target = dp.size() - 1;
	for (int i = sz_rawdata - 1; i >= 0; i--) {
		if (LIS[i] == target) {
			st.push(rawdata[i]);
			target--;
		}
	}
	
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;
}

void operate() {
	dp.push_back(rawdata[0]);
	LIS[0] = 0;

	for (int i = 1; i < sz_rawdata; i++) {
		if (rawdata[i] > dp[idx]) {
			dp.push_back(rawdata[i]);
			idx++;
			LIS[i] = idx;
		}
		else {
			auto iter = lower_bound(dp.begin(), dp.end(), rawdata[i]);
			*iter = rawdata[i];
			LIS[i] = iter - dp.begin();
		}
	}
	print_result();
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
10 5 20 10 15 14

9
3 1 4 6 2 2 0 3 6
*/