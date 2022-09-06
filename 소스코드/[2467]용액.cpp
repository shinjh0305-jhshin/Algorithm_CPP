#include <iostream>
#include <cmath>
using namespace std;

int rawdata[100005];
int sz_rawdata;
pair<int, int> result;

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void operate() {
	int distance = 2134567890;
	int left = 0, right = sz_rawdata - 1;

	int temp_distance;

	while (left < right) {
		temp_distance = rawdata[left] + rawdata[right];

		if (temp_distance == 0) {
			cout << rawdata[left] << ' ' << rawdata[right];
			return;
		}

		if (abs(temp_distance) < distance) {
			distance = abs(temp_distance);
			result.first = rawdata[left];
			result.second = rawdata[right];
		}

		if (temp_distance < 0) left++;
		else right--;
	}

	cout << result.first << ' ' << result.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}