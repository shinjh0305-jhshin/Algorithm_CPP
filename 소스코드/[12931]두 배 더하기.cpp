#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> rawdata;
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void operate() {
	int opers = 0;
	int adds, muls, max_muls = 0;

	for (int i = 0; i < sz_rawdata; i++) {
		adds = muls = 0;
		while (rawdata[i] > 0) {
			if (rawdata[i] % 2 == 0) {
				rawdata[i] /= 2;
				muls++;
			}
			else {
				rawdata[i] -= 1;
				adds++;
			}
		}
		opers += adds;
		max_muls = max(max_muls, muls);
	}
	opers += max_muls;

	cout << opers << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}