#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int first, second;
};

vector<info> rawdata;
int dp[102];
int lines;

bool cmp(const info &a, const info &b) {
	if (a.first < b.first) return true;
	return false;
}

void initialize() {
	cin >> lines;

	int a, b;
	for (int i = 0; i < lines; i++) {
		cin >> a >> b;
		rawdata.push_back({ a,b });
	}

	sort(rawdata.begin(), rawdata.end(), cmp);

	for (int i = 0; i < lines; i++) dp[i] = 1;
}

void operate() {
	int ans = 0;

	for (int start = lines - 1; start >= 0; start--) {
		for (int mov = start + 1; mov < lines; mov++) {
			if (rawdata[mov].second > rawdata[start].second) {
				dp[start] = max(dp[start], dp[mov] + 1); 
			}
		}

		ans = max(ans, dp[start]);
	}

	cout << lines - ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}