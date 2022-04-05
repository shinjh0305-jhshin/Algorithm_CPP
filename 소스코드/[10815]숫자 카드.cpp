#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning(disable:4996)
using namespace std;

vector<int> rawdata;
vector<int> searchdata;
int sz_data, sz_search;

void initialize() {
	cin >> sz_data;
	rawdata.resize(sz_data);
	for (int i = 0; i < sz_data; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata.begin(), rawdata.end());

	cin >> sz_search;
	searchdata.resize(sz_search);
	for (int i = 0; i < sz_search; i++) {
		cin >> searchdata[i];
	}
}

int findNum(int target) {
	int front = 0, end = sz_data - 1, mid;

	while (front <= end) {
		mid = (front + end) / 2;

		if (rawdata[mid] == target) return 1;

		if (rawdata[mid] > target) end = mid - 1;
		else front = mid + 1;
	}

	return 0;
}

void operate() {
	for (int i = 0; i < sz_search; i++) {
		cout << findNum(searchdata[i]) << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}