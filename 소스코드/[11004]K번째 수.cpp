#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int rawdata[5000003];
int sz_rawdata, target;

void operate() {
	cin >> sz_rawdata >> target;

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata, rawdata + sz_rawdata);

	cout << rawdata[target - 1] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}