#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rawdata[10002];
int sz_rawdata, target;

void initialize() {
	cin >> sz_rawdata >> target;

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
	rawdata[sz_rawdata] = 0; //마지막 index 오류 막기
}

void operate() {
	int left = 0, right = 0, sum = rawdata[0], result = 0;

	while (right < sz_rawdata) {
		if (sum == target) {
			result++;
		}
		if (sum <= target) {
			right++;
			sum += rawdata[right];
		}
		else if (sum > target) {
			sum -= rawdata[left];
			left++;
		}
	}

	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}