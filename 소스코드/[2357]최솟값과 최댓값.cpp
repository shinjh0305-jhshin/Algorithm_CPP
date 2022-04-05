#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int maxnum;
	int minnum;
};
vector<int> rawdata;
vector<info> segTree;

int szdata, query;

info getQuery(int left, int right, int start, int end, int idx) { //left, right : 현재 idx가 포함하고 있는 숫자의 범위
	if (left > end || right < start) return { 0,2000000000 };
	else if (start <= left && end >= right) return segTree[idx];
	else {
		int mid = (left + right) / 2;
		info temp1 = getQuery(left, mid, start, end, idx * 2);
		info temp2 = getQuery(mid + 1, right, start, end, idx * 2 + 1);

		return { max(temp1.maxnum, temp2.maxnum), min(temp1.minnum, temp2.minnum) };
	}
}

void sendQuery() {
	int startIdx, endIdx;
	info ret;
	for (int i = 0; i < query; i++) {
		cin >> startIdx >> endIdx;
		ret = getQuery(1, szdata, startIdx, endIdx, 1);
		cout << ret.minnum << ' ' << ret.maxnum << endl;
	}
}

void makeTree(int start, int end, int idx) {
	if (start == end) segTree[idx] = { rawdata[start], rawdata[start] };
	else {
		int mid = (start + end) / 2;
		makeTree(start, mid, idx * 2);
		makeTree(mid + 1, end, idx * 2 + 1);

		segTree[idx].maxnum = max(segTree[idx * 2].maxnum, segTree[idx * 2 + 1].maxnum);
		segTree[idx].minnum = min(segTree[idx * 2].minnum, segTree[idx * 2 + 1].minnum);
	}
}

void initialize() {
	cin >> szdata >> query;
	
	rawdata.resize(szdata + 1);
	for (int i = 1; i <= szdata; i++) {
		cin >> rawdata[i];
	}

	segTree.resize(4 * szdata);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	makeTree(1, szdata, 1);
	sendQuery();

	return 0;
}
