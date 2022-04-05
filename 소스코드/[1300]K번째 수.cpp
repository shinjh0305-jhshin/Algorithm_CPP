#include <iostream>
#include <algorithm>
#include <cmath>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int N, k;

void initialize() {
	cin >> N >> k;
}

int query(int mid) {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += min(N, mid / i);
	}
	return ans;
}

void operate() {
	int left, right, mid;

	left = 1; right = min(pow(10, 9), pow(N, 2));

	while (left != right) {
		mid = (left + right) / 2;
		if (query(mid) >= k) right = mid;
		else left = mid + 1;
	}

	cout << left << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}