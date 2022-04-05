#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl "\n"
#define INF 987654321
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
vector<info> goParty[1002];
vector<info> goHome[1002];
int goParty_result[1002];
int goHome_result[1002];
int nodes, edges, destination;

void initialize() {
	cin >> nodes >> edges >> destination;

	int node1, node2, cost;

	for (int i = 0; i < edges; i++) {
		cin >> node1 >> node2 >> cost;
		goHome[node1].push_back({ node2, cost });
		goParty[node2].push_back({ node1, cost });
	}

	for (int i = 1; i <= nodes; i++) {
		goParty_result[i] = INF;
		goHome_result[i] = INF;
	}
}

void operate(vector<info> (&move)[1002], int (&result)[1002]) {
	priority_queue<info, vector<info>, compare> pq;

	pq.push({ destination, 0 });
	result[destination] = 0;
	
	int curLoc, curSum, sz_curLoc;
	int tempLoc, tempSum;
	while (!pq.empty()) {
		curLoc = pq.top().node; curSum = pq.top().cost; pq.pop();

		if (curSum > result[curLoc]) continue;

		sz_curLoc = move[curLoc].size();

		for (int i = 0; i < sz_curLoc; i++) {
			tempLoc = move[curLoc][i].node; 
			tempSum = curSum + move[curLoc][i].cost;

			if (tempSum < result[tempLoc]) {
				pq.push({ tempLoc, tempSum });
				result[tempLoc] = tempSum;
			}
		}
	}
	return;
}

void evaluate() {
	int ans = 0;
	
	for (int i = 1; i <= nodes; i++) {
		ans = max(ans, goParty_result[i] + goHome_result[i]);
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate(goParty, goParty_result);
	operate(goHome, goHome_result);
	evaluate();

	return 0;
}