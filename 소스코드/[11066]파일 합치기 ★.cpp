#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define INF 100000000
#pragma warning (disable:4996)
using namespace std;

vector<int> dp[502];
vector<int> cost;
vector<int> sum;
int test_cases, files;

void initilaize() {
	cin >> files;
	cost.clear(); cost.resize(files + 1);
	sum.clear(); sum.resize(files + 1);
	sum[0] = 0;

	for (int i = 1; i <= files; i++) {
		cin >> cost[i];
		dp[i].assign(files + 1, INF);
		sum[i] = sum[i - 1] + cost[i];
	}
}

int get_min(int start, int end) {
	if (start == end) return 0;
	else if (start + 1 == end) return dp[start][end] = cost[start] + cost[end];
	else if (dp[start][end] != INF) return dp[start][end];
	else {
		for (int mid = start; mid < end; mid++) {
			//이 과정에서는 지금 합치고 있는 파일 이전에 생성된 파일들을 합치는데 필요한 연산의 횟수가 나온다.
			dp[start][end] = min(dp[start][end], get_min(start, mid) + get_min(mid+1, end));
		}
	}
	//현재 합치고 있는 파일을 합치는 데 필요한 연산 횟수(즉, 마지막 연산의 횟수)를 더한다.
	return dp[start][end] += sum[end] - sum[start - 1];
}

void operate() {
	cout << get_min(1, files) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> test_cases;
	for (int i = 0; i < test_cases; i++) {
		initilaize();
		operate();
	}
}