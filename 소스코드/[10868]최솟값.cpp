#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

vector<int> rawdata;
vector<int> segTree;
int sz_rawdata, queries;

int make_segTree(int start, int end, int idx) {
	if (start == end) {
		return segTree[idx] = rawdata[start];
	}
	
	int mid = (start + end) / 2;
	return segTree[idx] = min(make_segTree(start, mid, idx * 2), make_segTree(mid + 1, end, idx * 2 + 1));
}

int get_min(int left, int right, int quer_left, int quer_right, int idx) {
	if (right<quer_left || left>quer_right) return 1200000000;
	if (quer_left <= left && quer_right >= right) return segTree[idx];

	int mid = (left + right) / 2;
	return min(get_min(left, mid, quer_left, quer_right, idx * 2), get_min(mid + 1, right, quer_left, quer_right, idx * 2 + 1));
}

void initialize() {
	cin >> sz_rawdata >> queries;

	rawdata.resize(sz_rawdata);
	segTree.resize(sz_rawdata * 4);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	make_segTree(0, sz_rawdata - 1, 1);
}

void operate() {
	int from, to;
	for (int i = 0; i < queries; i++) {
		cin >> from >> to;
		cout << get_min(0, sz_rawdata - 1, from - 1, to - 1, 1) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}