#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int node;
	int dist;
};

vector<info> map[100005];
bool visited[100005] = { false };
int nodes;

void initialize() {
	cin >> nodes;
	int start_node, end_node, dist;

	for (int i = 0; i < nodes; i++) {
		cin >> start_node;

		while (1) {
			cin >> end_node;
			if (end_node != -1) {
				cin >> dist;
				map[start_node].push_back({ end_node, dist });
			}
			else break;
		}
	}
}

info DFS(int num) {
	visited[num] = true;

	int sz_num = map[num].size();
	int tempNode, tempDist;
	int ansNode = num, ansDist = 0;
	int temp = 0;

	for (int i = 0; i < sz_num; i++) {
		tempNode = map[num][i].node; tempDist = map[num][i].dist;
		if (!visited[tempNode]) {
			info result = DFS(tempNode);
			temp = tempDist + result.dist;
			if (temp > ansDist) {
				ansDist = temp;
				ansNode = result.node;
			}
		}
	}

	return { ansNode, ansDist };
}

void operate() {
	info temp = DFS(1);
	memset(visited, false, sizeof(visited));
	temp = DFS(temp.node);
	cout << temp.dist << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}