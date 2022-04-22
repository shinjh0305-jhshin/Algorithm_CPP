#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, query;
int gates, planes;

int get_parent(int num) {
	if (parent[num] == num) return num;
	return parent[num] = get_parent(parent[num]);
}

void initialize() {
	cin >> gates >> planes;
	parent.resize(gates + 1);
	query.resize(planes);

	for (int i = 0; i <= gates; i++) parent[i] = i;
	for (int i = 0; i < planes; i++) cin >> query[i];
}

void operate() {
	int plane, i, queryParent;
	for (i = 0; i < planes; i++) {
		plane = query[i];
		queryParent = get_parent(plane);

		if (queryParent == 0) break;
		parent[queryParent] = get_parent(queryParent - 1);
	}
	cout << i << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
6
7
2
1
6
4
3
3
5
ans : 5

6
7
2
1
6
4
3
5
6
ans : 5

7
6
1
2
3
4
5
6
ans : 6
*/