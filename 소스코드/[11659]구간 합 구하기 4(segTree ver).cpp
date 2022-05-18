#include <iostream>
#define endl "\n"
using namespace std;

int rawdata[100003];
int segTree[400012];
int sz_rawdata, query;

int makeSegTree(int left, int right, int idx) {
	if (left == right) return segTree[idx] = rawdata[left];

	int mid = (left + right) / 2;
	return segTree[idx] = makeSegTree(left, mid, idx * 2) + makeSegTree(mid + 1, right, idx * 2 + 1);
}

int getQuery(int curLeft, int curRight, int querLeft, int querRight, int idx) {
	if (querRight < curLeft || curRight < querLeft) return 0;
	if (querLeft <= curLeft && curRight <= querRight) return segTree[idx];

	int mid = (curLeft + curRight) / 2;
	return getQuery(curLeft, mid, querLeft, querRight, idx * 2) + getQuery(mid + 1, curRight, querLeft, querRight, idx * 2 + 1);
}

void initialize() {
	cin >> sz_rawdata >> query;

	for (int i = 0; i < sz_rawdata; i++) cin >> rawdata[i];

	makeSegTree(0, sz_rawdata - 1, 1);
}

void operate() {
	int from, to;

	for (int i = 0; i < query; i++) {
		cin >> from >> to;
		cout << getQuery(0, sz_rawdata - 1, from - 1, to - 1, 1) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}