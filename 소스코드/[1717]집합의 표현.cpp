#include <iostream>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int root[1000003];
int height[1000003];
int sz_data, num_op;

int find_root(int num) {
	if (root[num] == num) return num;
	return root[num] = find_root(root[num]);
}

void merge(int num1, int num2) {
	int root1 = find_root(num1);
	int root2 = find_root(num2);

	if (root1 == root2) return;

	if (height[root1] < height[root2]) swap(root1, root2);
	
	root[root2] = root1;

	if (height[root1] == height[root2]) height[root1]++;
}

void operate() {
	cin >> sz_data >> num_op;

	for (int i = 0; i <= sz_data; i++) {
		root[i] = i;
		height[i] = 1;
	}

	int op, a, b, root1, root2;
	for (int i = 0; i < num_op; i++) {
		cin >> op >> a >> b;

		if (op == 0) merge(a, b);
		if (op == 1) {
			root1 = find_root(a);
			root2 = find_root(b);

			if (root1 == root2) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	operate();

	return 0;
}