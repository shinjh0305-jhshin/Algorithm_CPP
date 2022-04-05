#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int start, finish, cost;
};
vector<info> rawdata;
int nodes, edges;
int root[10003];
int depth[10003];

bool compare(const info& a, const info& b) {
	if (a.cost < b.cost) return true;
	return false;
}

void initialize() {
	cin >> nodes >> edges;

	rawdata.resize(edges);
	for (int i = 0; i < edges; i++) {
		cin >> rawdata[i].start >> rawdata[i].finish >> rawdata[i].cost;
	}

	for (int i = 1; i <= nodes; i++) {
		root[i] = i;
		depth[i] = 1;
	}

	sort(rawdata.begin(), rawdata.end(), compare);
}

int find_root(int num) {
	if (root[num] == num) return num;
	return root[num] = find_root(root[num]);
}

void merge(int num1, int num2) {
	int root1 = find_root(num1);
	int root2 = find_root(num2);
	
	if (root1 == root2) return;

	if (depth[root1] < depth[root2]) swap(root1, root2);

	root[root2] = root1;

	if (depth[root1] == depth[root2]) depth[root1]++;
}

void operate() {
	int node1, node2, root1, root2, ans = 0;
	for (int i = 0; i < edges; i++) {
		node1 = rawdata[i].start; node2 = rawdata[i].finish;
		root1 = find_root(node1); root2 = find_root(node2);
		
		if (root1 == root2) continue;
		else {
			merge(node1, node2);
			ans += rawdata[i].cost;
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