#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rawdata[1002], result[1002];
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void operate() {
	int idx = 0;
	result[0] = 0;

	for (int i = 0; i < sz_rawdata; i++) {
		if (rawdata[i] > result[idx]) {
			result[++idx] = rawdata[i];
		}
		else {
			result[lower_bound(result, result + idx, rawdata[i]) - result] = rawdata[i];
		}
	}

	cout << idx << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
