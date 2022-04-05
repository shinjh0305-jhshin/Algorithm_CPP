#include <iostream>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;
	
int nums, target, ans = 0;
int rawdata[22];

void initialize() {
	cin >> nums >> target;

	for (int i = 0; i < nums; i++) {
		cin >> rawdata[i];
	}
}

void decisionMaker(int idx, int localSum) {
	if (localSum + rawdata[idx] == target) ans++;

	if (idx < nums - 1) {
		decisionMaker(idx + 1, localSum);
		decisionMaker(idx + 1, rawdata[idx] + localSum);
	}
}

void operate() {
	decisionMaker(0, 0);

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}