#include <iostream>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	cin >> x >> y;

	if (x > 0 && y > 0) cout << 1 << endl;
	else if (x < 0 && y > 0) cout << 2 << endl;
	else if (x < 0 && y < 0) cout << 3 << endl;
	else if (x > 0 && y < 0) cout << 4 << endl;

	return 0;
}