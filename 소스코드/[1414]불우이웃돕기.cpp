#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

struct info {
	int cost, row, col;
};

vector<info> rawdata;
int sz_rawdata, totalLength = 0;
int root[2500];

bool compare(const info& a, const info& b) {
	return a.cost < b.cost;
}

void initialize() {
	cin >> sz_rawdata;

	string st;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> st;
		for (int j = 0; j < sz_rawdata; j++) {
			if (st[j] == '0') continue;
			else if ('a' <= st[j] && st[j] <= 'z') {
				if (i != j) rawdata.push_back({ st[j] - 'a' + 1, i, j });
				totalLength += st[j] - 'a' + 1;
			}
			else {
				if (i != j) rawdata.push_back({ st[j] - 'A' + 27, i, j });
				totalLength += st[j] - 'A' + 27;
			}
		}
	}

	for (int i = 0; i < sz_rawdata; i++) {
		root[i] = -1;
	}

	sort(rawdata.begin(), rawdata.end(), compare);
}

int getRoot(int num) {
	if (root[num] < 0) return num;
	return root[num] = getRoot(root[num]);
}

void mergeRoot(int root1, int root2) {
	//int root1 = getRoot(num1);
	//int root2 = getRoot(num2);

	//if (root1 == root2) return; //operate 함수에서 이미 확인함

	if (root[root1] > root[root2]) swap(root1, root2);

	root[root1] += root[root2];
	root[root2] = root1;
}

void operate() {
	int root1, root2;
	for (const auto curLan : rawdata) {
		root1 = getRoot(curLan.row); 
		root2 = getRoot(curLan.col);

		if (root1 != root2) { //갖고 있어야 하는 랜선
			totalLength -= curLan.cost; //전체 랜선 길이에서 보관할 랜선 길이를 뺀다
			mergeRoot(root1, root2);
		}
	}

	root1 = getRoot(0);
	for (int i = 1; i < sz_rawdata; i++) {
		root2 = getRoot(i);
		if (root1 != root2) {
			cout << -1 << endl;
			return;
		}
	}

	cout << totalLength << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}