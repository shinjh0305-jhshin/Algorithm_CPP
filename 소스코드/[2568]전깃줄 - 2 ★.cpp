#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int start;
	int end;
	int loc; //LIS 상에서 놓일 위치(역추적에 사용됨)
};

bool compare(const info &a, const info &b) {
	if (a.end < b.end) return true;
	return false;
}

vector<info> rawdata;
vector<int> dp;
priority_queue<int> pq;
int sz;

void initialize() {
	cin >> sz;
	rawdata.resize(sz);
	dp.resize(sz);

	for (int i = 0; i < sz; i++) {
		cin >> rawdata[i].start >> rawdata[i].end;
	}

	sort(rawdata.begin(), rawdata.end(), compare);
	dp[0] = rawdata[0].start;
	rawdata[0].loc = 0;
}

void update(int left, int right, int target, int idx) {
	int mid = (left + right) / 2;

	while (left < right) {
		mid = (left + right) / 2;

		if (dp[mid] > target) right = mid;
		else left = mid + 1;
	}
	
	dp[left] = target;
	rawdata[idx].loc = left;
}

void operate() {
	int idx = 0;

	for (int i = 1; i < sz; i++) {
		if (rawdata[i].start > dp[idx]) {
			dp[++idx] = rawdata[i].start;
			rawdata[i].loc = idx;
		}
		else {
			update(0, idx, rawdata[i].start, i);
		}
	}

	int result = idx;
	for (int i = sz - 1; i >= 0; i--) {
		if (rawdata[i].loc == result) {
			result--;
		}
		else pq.push(-rawdata[i].start);
	}

	cout << pq.size() << endl;
	while (!pq.empty()) {
		cout << -pq.top() << endl;
		pq.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	operate();
	
	return 0;
}

/*
3
1 3
2 2
3 1

7
1 2
2 5
3 1
4 7
5 3
6 6
7 4

6
1 2
2 3
3 1
4 4
5 6
6 5

7
1 2
2 1
3 4
4 5
5 3
6 7
7 6


*/