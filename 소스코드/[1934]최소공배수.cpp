#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int getGCD(int num1, int num2) {
	if (num1 < num2) swap(num1, num2);
	if (num2 == 0) return num1;
	return getGCD(num2, num1%num2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases, num1, num2;
	cin >> cases;

	while (cases--) {
		cin >> num1 >> num2;
		cout << num1 * num2 / getGCD(num1, num2) << endl;
	}

	return 0;
}