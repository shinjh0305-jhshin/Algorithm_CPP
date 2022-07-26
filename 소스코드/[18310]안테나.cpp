#include <iostream>
#include <algorithm>
using namespace std;

int houses;
int rawdata[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> houses;
	for (int i = 0; i < houses; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata, rawdata + houses);

	cout << rawdata[(houses - 1) / 2] << endl;

	return 0;
}