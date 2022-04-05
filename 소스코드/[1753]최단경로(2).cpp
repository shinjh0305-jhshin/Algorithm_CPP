#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
#define INF 9876543
#pragma warning (disable:4996)
using namespace std;

struct info {
	int node;
	int cost;
};
struct compare {
	bool operator()(const info &a, const info &b) {
		if (a.cost > b.cost) return true;
		return false;
	}
};
vector<info> map[20003];
int nodes, edges, startingPoint;
int result[20003];

void dijkstra() {
	priority_queue<info, vector<info>, compare> pq;
	int sz = map[startingPoint].size();

	for (int i = 0; i < sz; i++) {
		pq.push({ map[startingPoint][i].node, map[startingPoint][i].cost });
	}

	int curNode, curCost, tempNode, tempCost;
	while (!pq.empty()) {
		curNode = pq.top().node; curCost = pq.top().cost;

		if (curCost <= result[curNode]) {
			result[curNode] = curCost;
			sz = map[curNode].size();

			for (int i = 0; i < sz; i++) {
				tempNode = map[curNode][i].node;
				tempCost = map[curNode][i].cost + curCost;

				if (tempCost <= result[tempNode]) {
					result[tempNode] = tempCost;
					pq.push({ tempNode, tempCost });
				}
			}
		}

		pq.pop();
	}

	for (int i = 1; i <= nodes; i++) {
		if (result[i] == INF) cout << "INF" << endl;
		else cout << result[i] << endl;
	}
}

void initialize() {
	int node1, node2, cost;

	cin >> nodes >> edges >> startingPoint; cin.get();

	for (int i = 0; i < edges; i++) {
		cin >> node1 >> node2 >> cost; cin.get();
		map[node1].push_back({ node2,cost });
	}

	for (int i = 1; i <= 20000; i++) result[i] = INF;
	result[startingPoint] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	dijkstra();

	return 0;

}