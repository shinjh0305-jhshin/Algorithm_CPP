#include <iostream>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int height[9], total_height = 0, i, j, k, sum;
	for (i = 0; i < 9; i++) {
		cin >> height[i];
		total_height += height[i];
	}
	sort(height, height + 9);

	int height_to_go = total_height - 100; //빠져야 되는 키

	for (i = 8; i >= 1; i--) {
		for (j = i - 1; j >= 0; j--) {
			sum = height[i] + height[j];
			if (sum < height_to_go) break;
			if (sum == height_to_go) goto found;
		}
	}

found:;
	for (k = 0; k < 9; k++) {
		if (k == i || k == j) continue;
		cout << height[k] << endl;
	}
	return 0;
}