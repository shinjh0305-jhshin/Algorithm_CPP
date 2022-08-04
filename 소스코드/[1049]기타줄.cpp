#include <iostream>
#include <algorithm>
using namespace std;

void operate() {
	int strings, brands;

	int bundleMin = 2134567890, pieceMin = 2134567890;
	int bundle, piece;

	cin >> strings >> brands;
	for (int i = 0; i < brands; i++) {
		cin >> bundle >> piece;
		bundleMin = min(bundleMin, min(bundle, piece * 6));
		pieceMin = min(pieceMin, piece);
	}

	int sum = strings / 6 * bundleMin;
	sum += min(bundleMin, strings % 6 * pieceMin);

	cout << sum << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}