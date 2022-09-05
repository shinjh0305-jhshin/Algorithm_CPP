#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> map[1000003];
int nodes;
bool visited[1000003];
pair<int, int> dp[10000003]; //얼리어탑터일 때, 아닐 때

void initialize() {
	cin >> nodes;

	int from, to;
	for (int i = 0; i < nodes - 1; i++) {
		cin >> from >> to;
		map[from].push_back(to);
		map[to].push_back(from);
	}
}

void DFS(int node = 1) {
	visited[node] = true;

	int ea = 1, notea = 0; //ea : early adapter
	for (const auto& nextNode : map[node]) {
		if (!visited[nextNode]) {
			DFS(nextNode);
			ea += min(dp[nextNode].first, dp[nextNode].second);
			notea += dp[nextNode].first;
		}
	}

	dp[node] = { ea, notea };
} 

void operate() {
	DFS();
	cout << min(dp[1].first, dp[1].second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}