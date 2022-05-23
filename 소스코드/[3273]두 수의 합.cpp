#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rawdata;
int sz_rawdata, target;

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (auto &it : rawdata) {
		cin >> it;
	}

	cin >> target;

	sort(rawdata.begin(), rawdata.end());
}

void operate() {
	int left = 0, right = sz_rawdata - 1, cnt = 0, temp;

	while (left < right) {
		temp = rawdata[left] + rawdata[right];
		if (temp == target) {
			cnt++;
			left++;
		}
		else if (temp < target) left++;
		else right--;
	}

	cout << cnt << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}