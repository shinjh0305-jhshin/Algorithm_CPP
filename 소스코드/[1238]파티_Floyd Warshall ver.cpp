#include <iostream>
#include <algorithm>
#define endl "\n"
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;

int nodes, edges, destination;
int dist[1002][1002];

void initialize() {
	cin >> nodes >> edges >> destination;

	for (int i = 1; i <= nodes; i++) {
		for (int j = 1; j <= nodes; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	int row, col, cost;
	for (int i = 0; i < edges; i++) {
		cin >> row >> col >> cost;
		dist[row][col] = cost;
	}
}

void operate() {
	for (int k = 1; k <= nodes; k++) {
		for (int i = 1; i <= nodes; i++) {
			if (dist[i][k] != INF) {
				for (int j = 1; j <= nodes; j++) {
					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= nodes; i++) {
		ans = max(ans, dist[i][destination] + dist[destination][i]);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}