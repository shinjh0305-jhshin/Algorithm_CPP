#include <iostream>
#define endl "\n"
using namespace std;

long long target;

void operate() {
	int left = 1, right = 1, ans = 0;
	long long sum = 1;

	cin >> target;

	int upperBound = target / 2 + 1;
	while (left <= right && right <= upperBound) {
		if (sum == target) {
			ans++; 
			sum -= left;
			left++;
		}
		else if (sum < target) {
			right++;
			sum += right;
		}
		else {
			sum -= left;
			left++;
		}
	}

	if (left <= right) ans++; //자기자신
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}