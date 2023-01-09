#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int sz, iter;
vector<int> dp(100005);

void initialize() {
	cin >> sz >> iter;

	int sum = 0;
	int inNum;

	dp[0] = 0;
	for (int i = 1; i <= sz; i++) {
		cin >> inNum;
		sum += inNum;
		dp[i] = sum;
	}
}

void operate() {
	int start, end;
	while (iter--) {
		cin >> start >> end;
		cout << dp[end] - dp[start - 1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
