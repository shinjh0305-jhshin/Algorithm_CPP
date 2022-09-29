#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int sz_rawdata;
vector<pair<int, int>> rawdata;

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i].first >> rawdata[i].second;
	}

	sort(rawdata.begin(), rawdata.end());
}

void operate() {
	int max_date = rawdata[sz_rawdata - 1].first;
	priority_queue<int> pq;

	int mov = sz_rawdata - 1;
	int res = 0;

	for (int date = max_date; date > 0; date--) {
		while (mov >= 0 && rawdata[mov].first == date) {
			pq.push(rawdata[mov].second);
			mov--;
		}

		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}

	cout << res << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}