#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll getGCD(ll num1, ll num2) {
	if (num1 < num2) swap(num1, num2);
	if (num2 == 0) return num1;
	return getGCD(num2, num1 % num2);
}

void operate() {
	ll num1, num2;
	cin >> num1 >> num2;

	ll result = getGCD(num1, num2);
	while (result--) {
		cout << 1;
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}