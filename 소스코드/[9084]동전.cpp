#include <iostream>
#include <cstring>
#include <vector>
#define endl "\n"
using namespace std;

int dp[23][10005];
vector<int> types;
int sz_types, target;

void initialize() {
	memset(dp, 0, sizeof(dp));
	types.clear();

	cin >> sz_types;
	types.resize(sz_types);

	for (auto& it : types) {
		cin >> it;
	}
	cin >> target;
}

void operate() {
	int curValue;

	for (int i = 1; i <= sz_types; i++) {
		curValue = types[i - 1];

		for (int j = 0; j <= target; j++) {
			dp[i][j] = dp[i - 1][j];
			
			if (j == curValue) dp[i][j]++;
			if (j >= curValue) {
				dp[i][j] += dp[i][j - curValue];
			}
		}
	}

	cout << dp[sz_types][target] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--) {
		initialize();
		operate();
	}

	return 0;
}