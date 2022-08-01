#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

struct info {
	int dest, cost;
};
vector<info> map[403];
int visited[403][403];
int nodes, edges;

void initialize() {
	cin >> nodes >> edges;

	for (int i = 1; i <= nodes; i++) {
		for (int j = 1; j <= nodes; j++) {
			visited[i][j] = INF;
		}
	}

	int from, to, cost;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to >> cost;
		map[from].push_back({ to, cost });
		visited[from][to] = cost;
	}
}

void operate() {
	int costTemp, ans = INF;

	for (int k = 1; k <= nodes; k++) {
		for (int i = 1; i <= nodes; i++) {
			if (visited[i][k] == INF) continue;
			for (int j = 1; j <= nodes; j++) {
				costTemp = visited[i][k] + visited[k][j];

				if (costTemp < visited[i][j]) {
					visited[i][j] = costTemp;
				}
				if (i == j) ans = min(ans, visited[i][j]);
			}
		}
	}

	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}