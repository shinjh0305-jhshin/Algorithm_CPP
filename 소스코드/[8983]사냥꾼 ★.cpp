#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> shoot;
int shooters, animals, range;

void initialize() {
	cin >> shooters >> animals >> range;
	shoot.resize(shooters);

	for (int i = 0; i < shooters; i++) {
		cin >> shoot[i];
	}

	sort(shoot.begin(), shoot.end());
}

void operate() {
	int lowerBound, upperBound;
	int left, right, mid, curPos;

	int row, col, ans = 0;
	for (int i = 0; i < animals; i++) {
		cin >> row >> col;

		if (col > range) continue;

		lowerBound = row + col - range;
		upperBound = row - col + range;

		left = 0; right = shooters - 1;
		
		while (left <= right) {
			mid = (left + right) / 2;
			curPos = shoot[mid];
			
			if (lowerBound <= curPos && curPos <= upperBound) {
				ans++;
				break;
			}
			else if (curPos < lowerBound) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}