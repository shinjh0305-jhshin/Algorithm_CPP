#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> rawdata;
int sz_rawdata, handFull;

void initialize() {
	cin >> sz_rawdata >> handFull;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata.begin(), rawdata.end());
}

void operate() {
	vector<int> groups;
	
	for (int i = 0; i < sz_rawdata && rawdata[i] < 0; i += handFull) {
		groups.push_back(-rawdata[i]);
	}

	for (int i = sz_rawdata - 1; i >= 0 && rawdata[i] > 0; i -= handFull) {
		groups.push_back(rawdata[i]);
	}

	sort(groups.begin(), groups.end());

	int ans = 0, sz_groups = groups.size();
	for (int i = 0; i < sz_groups - 1; i++) {
		ans += groups[i] * 2;
	}
	ans += groups[sz_groups - 1];

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}