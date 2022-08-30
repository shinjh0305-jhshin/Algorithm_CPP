#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
using namespace std;

int nums;
pii rawdata[10005];
priority_queue<pii> pq;

bool compare(const pii& a, const pii& b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
	}

	return false;
}

void initialize() {
	cin >> nums;
	for (int i = 0; i < nums; i++) {
		cin >> rawdata[i].first >> rawdata[i].second;
	}
	sort(rawdata, rawdata + nums, compare);
}

void operate() {
	int targetTime, ans = 0;

	int idx = nums - 1;
	for (int curDate = rawdata[nums - 1].second; curDate > 0; curDate--) {
		while (idx >= 0 && rawdata[idx].second == curDate) {
			pq.push(rawdata[idx]);
			idx--;
		}

		if (pq.empty()) continue;
		ans += pq.top().first;
		pq.pop();
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}