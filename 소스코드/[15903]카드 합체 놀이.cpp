#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;

void operate() {
	int nums, opers;
	ll temp;

	cin >> nums >> opers;

	for (int i = 0; i < nums; i++) {
		cin >> temp;
		pq.push(temp);
	}

	ll num1, num2;
	while (opers--) {
		num1 = pq.top(); pq.pop();
		num2 = pq.top(); pq.pop();

		pq.push(num1 + num2);
		pq.push(num1 + num2);
	}

	ll ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}