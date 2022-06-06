#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll _min, _max;
vector<bool> isAvailable;

void operate() {
	cin >> _min >> _max;
	isAvailable.resize(_max - _min + 1); //전부 false로 초기화된다 자동으로.

	for (ll i = 2; i * i <= _max; i++) {
		ll curNum = i * i;
		ll startIdx = _min % curNum == 0 ? _min / curNum : _min / curNum + 1;

		while (curNum * startIdx <= _max) {
			isAvailable[curNum * startIdx - _min] = true;
			startIdx++;
		}
	}

	int ans = 0;
	for (auto it : isAvailable) {
		if (!it) ans++;
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}