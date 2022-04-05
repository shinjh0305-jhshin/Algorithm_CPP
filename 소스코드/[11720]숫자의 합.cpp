#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt, sum = 0; char temp;
	cin >> cnt; cin.get();

	for (int i = 0; i < cnt; i++) {
		temp = cin.get() - '0';
		sum += temp;
	}
	cout << sum << endl;
	return 0;
}