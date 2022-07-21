#include <iostream>
#include <string>
using namespace std;

string rawdata, target;

void operate() {
	getline(cin, rawdata);
	getline(cin, target);

	int lenRawdata = rawdata.length(), lenTarget = target.length(), ans = 0;

	for (int i = 0; i <= lenRawdata - lenTarget; i++) {
		if (rawdata[i] != target[0] || rawdata[i + lenTarget - 1] != target[lenTarget - 1]) continue;

		string tempStr = rawdata.substr(i, lenTarget);
		if (tempStr == target) {
			ans++;
			i += lenTarget - 1;
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}