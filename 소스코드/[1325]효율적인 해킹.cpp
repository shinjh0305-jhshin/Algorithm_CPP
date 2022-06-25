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
		map[from].push_back(to); //from은 to를 신뢰한다.
	}	
}

void DFS(int node) { //node와 연결된 모든 노드한테 신뢰를 받는 컴퓨터가 1개 더 생겼다고 알린다.
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
	for (int i = 1; i <= nodes; i++) { //각각의 컴퓨터에 대해서 자신이 신뢰하는 모든 컴퓨터에게 신뢰한다는 것을 알려야 한다.
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