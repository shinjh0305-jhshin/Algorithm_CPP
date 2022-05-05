#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2134567890
#define endl "\n"
using namespace std;

struct info {
	int start, cost;
};
vector<int> map[300003];
vector<int> answer;
int totalCost[300003];
int nodes, edges, target, start;

struct compare {
	bool operator() (const info &a, const info &b) {
		if (a.cost > b.cost) return true;
		return false;
	}
};

void initialize() {
	cin >> nodes >> edges >> target >> start;

	int from, to;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		map[from].push_back(to);
	}

	for (int i = 1; i <= nodes; i++) {
		totalCost[i] = INF;
	}
}

void dijkstra() {
	priority_queue<info, vector<info>, compare> pq; //{start, cost}
	pq.push({ start, 0 });
	totalCost[start] = 0;

	int curNode, curCost, nextNode, nextCost, iter;
	while (!pq.empty()) {
		curNode = pq.top().start; curCost = pq.top().cost; pq.pop();

		if (curCost >= target) break;
		if (curCost > totalCost[curNode]) continue;

		iter = map[curNode].size();
		for (int i = 0; i < iter; i++) {
			nextNode = map[curNode][i];
			nextCost = curCost + 1;

			if (nextCost < totalCost[nextNode]) {
				totalCost[nextNode] = nextCost;
				pq.push({ nextNode, nextCost });

				if (nextCost == target) answer.push_back(nextNode);
			}
		}
	}

	if (answer.empty()) cout << -1 << endl;
	else {
		sort(answer.begin(), answer.end());
		for (auto it : answer) {
			cout << it << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	dijkstra();

	return 0;
}