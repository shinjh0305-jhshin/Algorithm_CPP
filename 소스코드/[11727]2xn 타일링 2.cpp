#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int rawdata[1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int target;
	cin >> target;

	rawdata[1] = 1; rawdata[2] = 3;
	for (int i = 3; i <= target; i++) {
		rawdata[i] = (rawdata[i - 2] * 2 + rawdata[i - 1]) % 10007;
	}

	cout << rawdata[target] << endl;
	return 0;
}