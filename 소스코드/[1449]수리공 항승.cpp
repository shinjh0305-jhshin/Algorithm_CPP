#include <iostream>
#include <algorithm>
using namespace std;

bool taped[2005];
int loc[1003];

void operate() {
	int iter, length;

	cin >> iter >> length;
	length *= 2;

	for (int i = 0; i < iter; i++) {
		cin >> loc[i];
	}
	
	sort(loc, loc + iter);

	int target, mid, left, right, start, tape = 0;
	for (int i = 0; i < iter; i++) {
		target = loc[i];
		mid = target * 2;
		left = mid - 1; right = mid + 1;

		if (!taped[left]) {
			start = left;
		}
		else if (!taped[mid]) {
			start = mid;
		}
		else if (!taped[right]) {
			start = right;
		}
		else continue;

		for (int k = start; k <= start + length && k < 2005; k++) {
			taped[k] = true;

		}

		tape++;
	}

	cout << tape << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}