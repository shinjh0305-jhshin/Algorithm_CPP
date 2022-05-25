#include <iostream>
#include <algorithm>
#define endl "\n"
#define ll long long
using namespace std;

ll rawdata[1000003] = { 0 };
ll sum[1000003];
int nums, opers;

ll getSum(ll idx) {
	ll ans = 0;

	while (idx > 0) {
		ans += sum[idx];
		idx -= (idx&-idx);
	}

	return ans;
}

void update(ll idx, ll diff) {
	while (idx <= nums) {
		sum[idx] += diff;
		idx += (idx&-idx);
	}
}

void operate() {
	cin >> nums >> opers;

	int op;
	ll idx, target, ans1, ans2, mod;

	for (int i = 0; i < opers; i++) {
		cin >> op >> idx >> target;
		if (op == 0) { //sum
			if (idx > target) swap(idx, target);

			ans2 = getSum(target); ans1 = getSum(idx);
			cout << ans2 - ans1 + rawdata[idx] << endl;
		}
		else { //modify
			mod = target - rawdata[idx];
			rawdata[idx] = target;
			update(idx, mod);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}