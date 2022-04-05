#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int money;
	cin >> money;

	money = 1000 - money;

	int currency[6] = { 500,100,50,10,5,1 };
	int result = 0;

	for (int i = 0; i < 6; i++) {
		result += money / currency[i];
		money %= currency[i];
	}

	cout << result << endl;
	return 0;
}