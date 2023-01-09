#include <iostream>
#define ll long long
using namespace std;

int sz, divisor;
int rawdata[1000005];
int divData[1005] = { 0 };

void initialize() {
	cin >> sz >> divisor;
	for (int i = 0; i < sz; i++) {
		cin >> rawdata[i];
	}
}

void operate() {
	int curmod = 0;

	ll ans = 0;
	for (int i = 0; i < sz; i++) {
		curmod = (curmod + rawdata[i]) % divisor;
		if (curmod == 0) ans++;
		ans += divData[curmod];
		divData[curmod]++;
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}