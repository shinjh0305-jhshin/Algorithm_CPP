#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> parent, height;
int sz_city, sz_travel;

void initialize() {
	cin >> sz_city >> sz_travel;
	parent.resize(sz_city + 1);
	height.resize(sz_city + 1);

	for (int i = 1; i <= sz_city; i++) {
		parent[i] = i;
		height[i] = 1;
	}
}

int find_root(int num) {
	if (parent[num] == num) return num;
	return parent[num] = find_root(parent[num]);
}

void merge_root(int num1, int num2) {
	int root1 = find_root(num1);
	int root2 = find_root(num2);

	if (root1 == root2) return;
	
	if (height[root1] < height[root2]) swap(root1, root2);

	parent[root2] = root1;
	
	if (height[root1] == height[root2]) height[root1]++;	
}

void operate() {
	int isConnected;
	for (int i = 1; i <= sz_city; i++) {
		for (int j = 1; j <= i; j++) cin >> isConnected; //좌측 하단 대칭 부분은 날려버린다.
		for (int j = i + 1; j <= sz_city; j++) {
			cin >> isConnected;
			if (isConnected) {
				merge_root(i, j);
			}
		}
	}

	int control, target;
	cin >> control; //맨 처음 나오는 여행 도시. 이 도시를 기준으로 연결 여부를 탐색한다.

	for (int i = 0; i < sz_travel - 1; i++) {
		cin >> target;
		if (find_root(control) == find_root(target)) continue;
		else {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}