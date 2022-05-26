#include <iostream>
#include <unordered_map>
#define endl "\n"
#define A_SUM(a, b) (sum_a[(b)] - sum_a[(a)-1]) //a이상 b이하의 합
#define B_SUM(a, b) (sum_b[(b)] - sum_b[(a)-1])
using namespace std;

unordered_map<int, long long> allSumA, allSumB; //B의 가능 한 모든 Sum 넣는다.

int target;
int a[1003], b[1003];
int sum_a[1003], sum_b[1003];
int sz_a, sz_b;

void initialize() {
	cin >> target;
	cin >> sz_a;
	for (int i = 1; i <= sz_a; i++) cin >> a[i];
	cin >> sz_b;
	for (int i = 1; i <= sz_b; i++) cin >> b[i];

	sum_a[0] = sum_b[0] = 0;
	for (int i = 1; i <= sz_a; i++) {
		sum_a[i] = sum_a[i - 1] + a[i];
	}
	for (int i = 1; i <= sz_b; i++) {
		sum_b[i] = sum_b[i - 1] + b[i];
	}

	int curSum;
	for (int left = 1; left <= sz_a; left++) {
		for (int right = left; right <= sz_a; right++) {
			allSumA[A_SUM(left, right)]++;
		}
	}
	for (int left = 1; left <= sz_b; left++) {
		for (int right = left; right <= sz_b; right++) {
			allSumB[B_SUM(left, right)]++;
		}
	}
}

void operate() {
	long long ans = 0;

	int toGo;
	for (auto it : allSumA) {
		toGo = target - it.first;
		ans += allSumB[toGo] * it.second;
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