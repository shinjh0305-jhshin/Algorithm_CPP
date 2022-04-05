#include <iostream>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int nodes, edges;
bool visited[1003] = { false };
vector<int> graph[1003];

void initialize() {
	cin >> nodes >> edges; cin.get();

	int front, back;
	for (int i = 0; i < edges; i++) {
		cin >> front >> back; cin.get();
		graph[front].push_back(back);
		graph[back].push_back(front);
	}
}

void DFS(int node) {
	visited[node] = true;

	int szEdge = graph[node].size(), mov; //szEdge : node에 연결된 edge 개수,  mov : node에 연결된 다른 node

	for (int i = 0; i < szEdge; i++) {
		mov = graph[node][i];
		if (!visited[mov]) DFS(mov);
	}
}

void operate() {
	int ans = 0;

	for (int i = 1; i <= nodes; i++) {
		if (!visited[i]) {
			DFS(i);
			ans++;
		}
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