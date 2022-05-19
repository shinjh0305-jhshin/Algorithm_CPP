#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1234567890
using namespace std;

vector<int> rawdata;
int dp[10003];
int types, target;

void initialize() {
	cin >> types >> target;
	rawdata.resize(types);

	for (int i = 0; i < types; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata.begin(), rawdata.end());
	rawdata.erase(unique(rawdata.begin(), rawdata.end()), rawdata.end());
	types = rawdata.size();
}

void operate() {
	int val;
	
	dp[0] = 0;
	for (int i = 1; i <= target; i++) {
		dp[i] = INF;
		for (int j = 0; j < types; j++) {
			val = rawdata[j];
			if (val > i) break; //현재 동전의 가치가 현재 타깃 금액보다 더 클 때
			if (dp[i - val] == INF) continue; //이전 단계 금액이 만들 수 없는 금액일 때

			dp[i] = min(dp[i], dp[i - val] + 1);
		}
	}

	if (dp[target] == INF) cout << -1 << endl;
	else cout << dp[target] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
4 15
1
5
12
5
*/