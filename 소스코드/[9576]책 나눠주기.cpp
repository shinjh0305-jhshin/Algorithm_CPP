#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl "\n"
#define pii pair<int, int>
using namespace std;

bool given[1005];
int books, students;
vector<pii> rawdata;

bool compare(const pii& a, const pii& b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
	}

	return false;
}

void initialize() {
	memset(given, false, sizeof(given));
	cin >> books >> students;

	rawdata.clear();
	rawdata.resize(students);
	for (int i = 0; i < students; i++) {
		cin >> rawdata[i].first >> rawdata[i].second;
	}

	sort(rawdata.begin(), rawdata.end(), compare);
}

void operate() {
	int ans = 0;
	for (int i = 0; i < students; i++) {
		for (int j = rawdata[i].first; j <= rawdata[i].second; j++) {
			if (!given[j]) {
				given[j] = true;
				ans++;
				break;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--) {
		initialize();
		operate();
	}

	return 0;
}