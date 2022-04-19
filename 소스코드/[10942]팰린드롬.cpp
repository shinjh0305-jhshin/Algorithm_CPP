#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

bool dp[2002][2002] = { false };
vector<int> rawdata;
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	for (int i = 0; i < sz_rawdata; i++) {
		dp[i][i] = true;
		if (i < sz_rawdata - 1 && rawdata[i] == rawdata[i + 1]) {
			dp[i][i + 1] = true;
		}
	}

	int st;
	for (int sz = 2; sz <= sz_rawdata - 1; sz++) {
		for (int fin = sz; fin <= sz_rawdata-1; fin++) {
			st = fin - sz;
			if (rawdata[st] == rawdata[fin] && dp[st + 1][fin - 1]) {
				dp[st][fin] = true;
			}
		}
	}
}

void operate() {
	int query, to, from;
	cin >> query;

	for (int i = 0; i < query; i++) {
		cin >> to >> from;
		cout <<	dp[to - 1][from - 1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}