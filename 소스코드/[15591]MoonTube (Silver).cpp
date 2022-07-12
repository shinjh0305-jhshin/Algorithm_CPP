#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define endl "\n"
#define INF 2134567890
using namespace std;

struct info {
	int node, cost;
};

int usado[5003];
vector<info> map[5003];
bool visited[5003];
int video, query, answer;

void getInfo() {
	cin >> video >> query;

	int node1, node2, cost;
	for (int i = 0; i < video - 1; i++) {
		cin >> node1 >> node2 >> cost;
		map[node1].push_back({ node2, cost });
		map[node2].push_back({ node1, cost });
	}
}

void initialize() {
	memset(visited, false, sizeof(visited));
	answer = 0; //추천되는 비디오의 개수 초기화
}

void DFS(int node, int k) {
	visited[node] = true;

	for (const auto& it : map[node]) {
		if (visited[it.node]) continue;

		usado[it.node] = min(usado[node], it.cost);
		if (usado[it.node] >= k) answer++;

		DFS(it.node, k);
	}
}

void operate() {
	int startNode, k;

	cin >> k >> startNode;
	usado[startNode] = INF;

	DFS(startNode, k);

	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getInfo();
	
	for (int i = 0; i < query; i++) {
		initialize();
		operate();
	}

	return 0;
}