#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

vector<int> rawdata;
int sz_rawdata, sz_block;

void initialize() {
	cin >> sz_rawdata >> sz_block;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void operate() {
	int sum = 0;
	for (int i = 0; i < sz_block; i++) {
		sum += rawdata[i];
	}
	
	int temp = sum;
	for (int i = sz_block; i < sz_rawdata; i++) {
		temp = temp - rawdata[i - sz_block] + rawdata[i];
		sum = max(sum, temp);
	}

	cout << sum << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}