#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

vector<int> map[100003];
int parent[100003] = { 0 };
int nodes;

void initialize() {
	cin >> nodes;
	
	int from, to;
	for (int i = 0; i < nodes - 1; i++) {
		cin >> from >> to;
		map[from].push_back(to);
		map[to].push_back(from);
	}

	parent[1] = -1; //루트노드 초기화
}

void traverse(int node) {
	for (const auto nextnode : map[node]) {
		if (!parent[nextnode]) { //방문한 노드인지 확인.
			parent[nextnode] = node;
			traverse(nextnode);
		}
	}
}

void operate() {
	traverse(1);

	for (int i = 2; i <= nodes; i++) {
		cout << parent[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}