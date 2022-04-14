#include <iostream>
#include <vector>
using namespace std;

int nodes;
vector<int> tree[51];
vector<int> parent(51);

void initialize() {
	cin >> nodes;

	int temp;
	for (int i = 0; i < nodes; i++) {
		cin >> temp;
		if (temp == -1) continue;
		tree[temp].push_back(i);
		parent[i] = temp;
	}
}

int get_leaves(int node) {
	int sz_node = tree[node].size();

	if (sz_node == 0) return 1;

	int leaves = 0;
	for (int i = 0; i < sz_node; i++) {
		leaves += get_leaves(tree[node][i]);
	}

	return leaves;
}

void operate() {
	int leaves = 0, target;

	cin >> target;

	for (int i = 0; i < nodes; i++) {
		if (tree[i].empty()) leaves++;
	}

	int ans = leaves - get_leaves(target);
	
	if (tree[parent[target]].size() == 1) ans++;

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;	
}

/*
4
-1 0 1 2
2

ans : 1

*/