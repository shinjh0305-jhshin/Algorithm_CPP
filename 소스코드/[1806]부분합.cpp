#include <iostream>
#include <vector>
#define INF 1234567890
using namespace std;

int rawdata[100002];
int sz_rawdata, lowerBound;

void initialize() {
	cin >> sz_rawdata >> lowerBound;

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
	rawdata[sz_rawdata] = 0;
}

void operate() {
	int left = 0, right = 0, ans = INF, sum = rawdata[0];

	while (right < sz_rawdata) {
		if (sum < lowerBound) {
			right++;
			sum += rawdata[right];
		}
		else {
			if (ans > right - left + 1) ans = right - left + 1;
			sum -= rawdata[left];
			left++;
		}
	}

	if (ans == INF) cout << 0 << endl;
	else cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
10 10
5 1 3 5 10 7 4 9 2 8
*/