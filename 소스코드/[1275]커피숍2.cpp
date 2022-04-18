#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long
using namespace std;

vector<ll> rawdata, segTree;
int sz_rawdata, turns;

ll makeSegtree(int front, int end, int idx) {
	if (front == end) return segTree[idx] = rawdata[front];
	
	int mid = (front + end) / 2;
	return segTree[idx] = makeSegtree(front, mid, idx * 2) + makeSegtree(mid + 1, end, idx * 2 + 1);
}

ll getSum(int front, int back, int start, int end, int idx) { //start, end : 구하려는 구간
	if (back < start || end < front) return 0;
	if (start <= front && back <= end) return segTree[idx];

	int mid = (front + back) / 2;
	return getSum(front, mid, start, end, idx * 2) + getSum(mid + 1, back, start, end, idx * 2 + 1);
}

void changeNum(int front, int back, int target, ll chg, int idx) {
	segTree[idx] += chg;

	if (front < back) {
		int mid = (front + back) / 2;
		if (target <= mid)
			changeNum(front, mid, target, chg, idx * 2);
		else
			changeNum(mid + 1, back, target, chg, idx * 2 + 1);
	}
}

void initialize() {
	cin >> sz_rawdata >> turns;

	rawdata.resize(sz_rawdata);
	segTree.resize(sz_rawdata * 4);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	makeSegtree(0, sz_rawdata - 1, 1);
}

void operate() {
	int from, to, targetidx;
	ll targetNum;

	for (int i = 0; i < turns; i++) {
		cin >> from >> to >> targetidx >> targetNum;

		if (from > to) swap(from, to);

		//합 구하기
		cout << getSum(0, sz_rawdata - 1, from - 1, to - 1, 1) << endl;

		//숫자 바꾸기
		ll inc = targetNum - rawdata[targetidx - 1];
		rawdata[targetidx - 1] = targetNum;

		changeNum(0, sz_rawdata - 1, targetidx - 1, inc, 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
10 10
1 2 3 4 5 6 7 8 9 10

*/