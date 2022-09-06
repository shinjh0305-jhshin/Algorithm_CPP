#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

vector<ll> rawdata;
int sz_rawdata;
ll result[3];

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata.begin(), rawdata.end());
}

void operate() {
	ll sum = 3214567890;

	int left, right;
	ll temp;

	for (int target = 0; target < sz_rawdata - 2; target++) {
		left = target + 1; right = sz_rawdata - 1;
		while (left < right) {
			temp = rawdata[target] + rawdata[left] + rawdata[right];

			if (abs(temp) < sum) {
				result[0] = rawdata[target]; result[1] = rawdata[left]; result[2] = rawdata[right];
				sum = abs(temp);
			}

			if (temp < 0) left++;
			else right--;
		}
	}

	cout << result[0] << ' ' << result[1] << ' ' << result[2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}