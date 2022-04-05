#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int rawdata[1005];

int main() {
	int target;
	cin >> target;

	rawdata[1] = 1; rawdata[2] = 2;

	for (int i = 3; i <= target; i++) {
		rawdata[i] = (rawdata[i - 1] + rawdata[i - 2]) % 10007;
	}

	cout << rawdata[target] << endl;
	return 0;
}