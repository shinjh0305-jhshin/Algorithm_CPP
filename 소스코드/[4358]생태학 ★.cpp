#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define endl "\n"
using namespace std;

unordered_map<string, double> rawdata;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string st;
	int cnt = 0;

	while (getline(cin, st)) {
		rawdata[st]++;
		cnt++;
	}

	for (auto& it : rawdata) {
		it.second = it.second / cnt * 100;
	}

	vector<pair<string, double>> vec(rawdata.begin(), rawdata.end());
	sort(vec.begin(), vec.end());

	cout << fixed;
	cout.precision(4);

	for (auto it : vec) {
		cout << it.first << ' ' << it.second << endl;
	}

	return 0;
}