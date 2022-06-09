#include <iostream>
#include <algorithm>
using namespace std;

int rawdata[15005];
int sz_rawdata, target;

void operate() {
	cin >> sz_rawdata >> target;
	
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata, rawdata + sz_rawdata);

	int ans = 0, left = 0, right = sz_rawdata - 1, temp;
	while (left < right) {
		temp = rawdata[left] + rawdata[right];
		if (temp == target) {
			ans++;
			right--;
		}
		else if (temp < target) {
			left++;
		}
		else right--;
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}