#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct info {
	int start, end, cost;
};
struct compare {
	bool operator() (const info& a, const info& b) {
		return a.cost > b.cost;
	}
};

priority_queue<info, vector<info>, compare> pq;
pair<int, int> point[2003];
int root[2003];
int fields, minCost;

int getRoot(int num) {
	if (root[num] < 0) return num;
	return root[num] = getRoot(root[num]);
}

bool mergeRoot(int num1, int num2) {
	int root1 = getRoot(num1);
	int root2 = getRoot(num2);

	if (root1 == root2) return false;

	if (root[root1] > root[root2]) swap(root1, root2);

	root[root1] += root[root2];
	root[root2] = root1;

	return true;
}

void initialize() {
	cin >> fields >> minCost;
	
	int x, y;
	for (int i = 0; i < fields; i++) {
		cin >> x >> y;
		point[i] = { x,y };
	}

	int dist;
	for (int i = 0; i < fields - 1; i++) {
		for (int j = i + 1; j < fields; j++) {
			dist = pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2);
			if (dist >= minCost) pq.push({ i, j, dist });
		}
	}

	for (int i = 0; i < fields; i++) root[i] = -1;
}

int operate() {
	if (pq.size() < fields - 1) return -1;

	int node1, node2, cost;
	int totalCost = 0, leftPipes = fields - 1;

	while (!pq.empty()) {
		node1 = pq.top().start; node2 = pq.top().end; cost = pq.top().cost;
		pq.pop();

		if (mergeRoot(node1, node2)) {
			totalCost += cost;
			leftPipes--;
		}
		
		if (leftPipes == 0) {
			return totalCost;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	cout << operate() << endl;

	return 0;
}