#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int a, b, c, target;
	cin >> a >> b >> c;
	for (int i = 0;; i++) {
		target = 15 * i + a;
		if ((target - b) % 28) continue;
		if ((target - c) % 19) continue;
		break;
	}
	cout << target << endl;
	return 0;
}