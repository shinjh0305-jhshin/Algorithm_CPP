#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

priority_queue<int> pq;
int sz_rawdata;
vector<pair<int, int>> rawdata; //date, point

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i].first >> rawdata[i].second;
	}

	sort(rawdata.begin(), rawdata.end(), greater<pair<int, int>>());
}

void operate() {
	int rawdataIdx = 0, ans = 0;

	for (int date = rawdata[0].first; date >= 1; date--) {
		while (rawdataIdx < sz_rawdata && rawdata[rawdataIdx].first == date) {
			pq.push(rawdata[rawdataIdx].second);
			rawdataIdx++;
		}
		
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}