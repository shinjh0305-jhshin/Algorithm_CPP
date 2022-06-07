#include <iostream>
#include <algorithm>
using namespace std;

int rawdata[2005];
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata, rawdata + sz_rawdata);
}

void operate() {
	int left, right, result = 0, target, temp;

	for (int i = 0; i < sz_rawdata; i++) {
		target = rawdata[i];
		left = 0; right = sz_rawdata - 1;

		while (left < right) {
			temp = rawdata[left] + rawdata[right];

			if (temp != target) {
				if (temp > target) {
					right--;
				}
				else left++;
			}
			else {
				if (left != i && right != i) {
					result++;
					break;
				}
				else if (left == i) left++;
				else right--;
			}
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