#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> map[10003];
int result[10003] = { 0 };
bool visited[10003];
int nodes, edges;

void initialize() {
	cin >> nodes >> edges;

	int from, to;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		map[from].push_back(to);
	}	
}

void DFS(int node) {
	visited[node] = true;
	int sz_node = map[node].size(), nextNode;

	for (int i = 0; i < sz_node; i++) {
		nextNode = map[node][i];

		if (!visited[nextNode]) {
			result[nextNode]++;
			DFS(nextNode);
		}
	}
}

void operate() {
	for (int i = 1; i <= nodes; i++) {
		memset(visited, false, sizeof(visited));
		DFS(i);
	}

	int maxNum = -1;
	for (int i = 1; i <= nodes; i++) {
		maxNum = max(maxNum, result[i]);
	}

	for (int i = 1; i <= nodes; i++) {
		if (result[i] == maxNum) cout << i << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}