#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

void operate() {
	int target;
	cin >> target;

	int num = 0, temp, i;
	for (i = 1;; i++) {
		temp = i;
		while (temp > 0) {
			if (temp % 1000 != 666) temp /= 10;
			else {
				num++;
				break;
			}
		}

		if (num == target) break;
	}

	cout << i << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	operate();

	return 0;
}