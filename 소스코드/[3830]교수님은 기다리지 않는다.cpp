#include <iostream>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define ll long long
using namespace std;

int root[100003];
ll value[100003];
int samples, queries;

void initialize() {
	for (int i = 1; i <= samples; i++) {
		root[i] = -1;
		value[i] = 0;
	}
}

int getRoot(int num) {
	if (root[num] < 0) return num;
	
	int rootNode = getRoot(root[num]);
	value[num] += value[root[num]];
	return root[num] = rootNode;
}

void mergeRoot(int num1, int num2, ll inc) { //num2가 num1보다 inc 만큼 더 무겁다
	int root1 = getRoot(num1);
	int root2 = getRoot(num2);

	if (root1 == root2) return;

	root[root1] += root[root2];
	value[root2] = value[num1] - value[num2] + inc;
	root[root2] = root1;
}

void operate() {
	char op;
	int num1, num2, root1, root2;
	ll inc;

	for (int i = 0; i < queries; i++) {
		cin >> op;
		if (op == '!') {
			cin >> num1 >> num2 >> inc;
			mergeRoot(num1, num2, inc);
		}
		else {
			cin >> num1 >> num2;
			root1 = getRoot(num1);
			root2 = getRoot(num2);

			if (root1 != root2) cout << "UNKNOWN" << endl;
			else cout << value[num2] - value[num1] << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> samples >> queries;
		if (samples == 0 && queries == 0) return 0;
		
		initialize();
		operate();
	}
}