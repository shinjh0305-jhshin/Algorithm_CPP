#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<long long> rawdata; //여기에는 높이가 들어와야 한다
vector<int> segTree; //여기에는 최솟값의 index가 들어와야 한다
int sz_rawdata;

int make_min(int start, int end, int idx) {
	if (start == end) return segTree[idx] = start;

	int mid = (start + end) / 2;
	int temp1 = make_min(start, mid, idx * 2);
	int temp2 = make_min(mid + 1, end, idx * 2 + 1);

	if (rawdata[temp1] <= rawdata[temp2]) return segTree[idx] = temp1;
	else return	segTree[idx] = temp2;
}

int get_min(int start, int end, int front, int back, int idx) { //start, end : idx가 포함하는 구간 front, back : 우리가 관심있는 구간(불변)
	if (end<front || start>back) return -1;
	if (front <= start && back >= end) return segTree[idx];
	
	int mid = (start + end) / 2;
	int idx1 = get_min(start, mid, front, back, idx * 2);
	int idx2 = get_min(mid + 1, end, front, back, idx * 2 + 1);

	if (idx1 == -1) return idx2;
	else if (idx2 == -1) return idx1;
	else {
		if (rawdata[idx1] <= rawdata[idx2]) return idx1;
		else return idx2;
	}
}

bool initialize() {
	rawdata.clear(); segTree.clear();

	cin >> sz_rawdata;

	if (sz_rawdata == 0) return false;

	rawdata.resize(sz_rawdata);
	segTree.resize(sz_rawdata * 4);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	make_min(0, sz_rawdata - 1, 1);

	return true;
}

long long get_area(int start, int end) {
	if (start == end)
		return rawdata[start];

	long long left_size, right_size, total_size;

	int mid = get_min(0, sz_rawdata - 1, start, end, 1);
	
	if (start == mid) 
		left_size = rawdata[start];
	else 
		left_size = get_area(start, mid - 1);

	if (end == mid)
		right_size = rawdata[end];
	else
		right_size = get_area(mid + 1, end);

	total_size = rawdata[mid] * (end - start + 1);

	long long ret = max(left_size, right_size);
	ret = max(ret, total_size);

	return ret;
}

void operate() {
	cout << get_area(0, sz_rawdata - 1) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (initialize()) {
		operate();
	}

	return 0;
}