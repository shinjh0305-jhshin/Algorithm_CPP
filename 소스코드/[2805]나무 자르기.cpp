#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

int trees, target;
int maxlen = 0;
vector<int> rawdata;

void initialize() {
	cin >> trees >> target;

	int temp;
	for (int i = 0; i < trees; i++) {
		cin >> temp; cin.get();
		maxlen = max(maxlen, temp);

		rawdata.push_back(temp);
	}
}

void operate() {
	int mid, left = 0, right = maxlen, result;
	long long temp;

	while (right >= left) {
		temp = 0; 
		mid = (left + right) / 2;

		for (int i = 0; i < trees; i++) {
			if (rawdata[i] > mid) temp += rawdata[i] - mid;
		}

		if (temp >= target) {
			result = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}