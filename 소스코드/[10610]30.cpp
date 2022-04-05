#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> rawdata(100003);

void initialize() {
	int sz = 0, temp, zeros = 0;
	while (1) {
		temp = cin.get();
		if (temp == '\n') break;
		if (temp == '0') zeros++;
		else rawdata[sz++] = temp - '0';
	}

	vector<int>::iterator rear;
	rear = rawdata.begin() + sz;

	sort(rawdata.begin(), rear, greater<int>());

	if (zeros == 0) cout << -1 << endl;
	else {
		int sum = 0;
		for (int i = 0; i < sz; i++) {
			sum += rawdata[i];
		}
		if (sum % 3 == 0) {
			for (int i = 0; i < sz; i++) {
				cout << rawdata[i];
			}
			for (int i = 0; i < zeros; i++) {
				cout << 0;
			}
			cout << endl;
		}
		else cout << -1 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();

	return 0;
}