#include <iostream>
#define ll long long
using namespace std;

void operate() {
	ll target;
	cin >> target;

	for (ll i = 1;; i++) {
		if (target - i <= i) {
			cout << i << endl;
			return;
		}
		target -= i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}