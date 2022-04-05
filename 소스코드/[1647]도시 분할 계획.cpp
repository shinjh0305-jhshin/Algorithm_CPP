#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

struct info {
	int start_node;
	int end_node;
	int dist;
};
vector<info> rawdata;

int root[100002];
int height[100002];
int houses, roads;

bool compare(const info &a, const info &b) {
	if (a.dist < b.dist) return true;
	return false;
}

void initialize() {
	cin >> houses >> roads;

	rawdata.resize(roads);
	for (int i = 0; i < roads; i++) {
		cin >> rawdata[i].start_node >> rawdata[i].end_node >> rawdata[i].dist;
	}

	sort(rawdata.begin(), rawdata.end(), compare);

	for (int i = 1; i <= houses; i++) {
		root[i] = i;
		height[i] = 1;
	}
}

int find_root(int num) {
	if (root[num] == num) return num;

	return root[num] = find_root(root[num]);
}

void merge_root(int num1, int num2, int& dist, int& remaining, int& ans) {
	int root1 = find_root(num1);
	int root2 = find_root(num2);

	if (root1 == root2) return;
	
	if (height[root1] < height[root2]) swap(root1, root2);

	root[root2] = root1;

	if (height[root1] == height[root2]) height[root1]++;

	remaining--;
	ans += dist;
}

void operate() {
	int remaining = houses; //서로 다른 root의 개수
	int ans = 0, idx = 0;

	while (remaining != 2) {
		merge_root(rawdata[idx].start_node, rawdata[idx].end_node, rawdata[idx].dist, remaining, ans);
		idx++;
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

/*
8 11
1 2 9
2 3 8
2 5 8
1 5 10
5 4 8
3 4 7
1 6 11
5 6 5
5 7 4
6 7 10
7 8 6

ans:38
*/