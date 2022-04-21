#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rawdata;
int sz_rawdata;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata.begin(), rawdata.end(), less<int>());

	int sum = 1;
	for (int i = 0; i < sz_rawdata; i++) {
		if (rawdata[i] > sum) break;
		sum += rawdata[i];
	}
	cout << sum << endl;
	return 0;
}