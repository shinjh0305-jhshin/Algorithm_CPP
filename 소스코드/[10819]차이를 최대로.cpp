#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int rawdata[9];
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
	sort(rawdata, rawdata + sz_rawdata);
}

void operate() {
	int ans = -2134567890;

	do {
		int temp = 0;
		for (int i = 0; i < sz_rawdata - 1; i++) {
			temp += abs(rawdata[i] - rawdata[i + 1]);	
		}
		ans = max(ans, temp);
	} while (next_permutation(rawdata, rawdata + sz_rawdata));

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}