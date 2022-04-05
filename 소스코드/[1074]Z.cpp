#include <iostream>
#include <cmath>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

int sz, row, col;

int findQuad(int num) { //1부터 시작!!!!
	int divide = (int)pow(2, num);
	int newrow = row % divide, newcol = col % divide;
	int ret;

	divide /= 2;

	if (newrow < divide && newcol < divide) ret = 0;
	else if (newrow < divide && newcol >= divide) ret = 1;
	else if (newrow >= divide && newcol < divide) ret = 2;
	else ret = 3;

	return (int)(ret * pow(pow(2, num - 1), 2));
}

void operate() {
	cin >> sz >> row >> col;

	int ans = 0;

	for (int i = 1; i <= sz; i++) {
		ans += findQuad(i);
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	operate();

	return 0;
}