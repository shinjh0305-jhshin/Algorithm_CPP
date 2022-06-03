
#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

long long rawdata[1000004];
long long tree[4000016];
int nums, xchgs, sums;

long long make_sum(int start, int end, int index) {
	if (start == end) return tree[index] = rawdata[start];
	
	int mid = (start + end) / 2;

	//start>end인 경우는 절대 발생하지 않는다.
	return tree[index] = make_sum(start, mid, index * 2) + make_sum(mid + 1, end, index * 2 + 1);
}

void initialize() {
	cin >> nums >> xchgs >> sums;

	for (int i = 0; i < nums; i++) {
		cin >> rawdata[i];
	}

	make_sum(0, nums - 1, 1);
}


void change_num(int start, int end, int index, int node, long long diff) {
	if (node<start || node>end) return;
	
	tree[index] += diff;

	if (start == end) return;

	int mid = (start + end) / 2;
	change_num(start, mid, index * 2, node, diff);
	change_num(mid + 1, end, index * 2 + 1, node, diff);
}

long long get_sum(int start, int end, int left, int right, int index) { //start, end : 현재 노드의 정보, left, right : 구하는 구간

	if (start >= left && end <= right) return tree[index];
	if (right < start || left > end) return 0;

	int mid = (start + end) / 2;

	return get_sum(start, mid, left, right, index * 2) + get_sum(mid + 1, end, left, right, index * 2 + 1);
}

void operate() {
	int operations, t1;
	long long t2;
	for (int i = 0; i < xchgs + sums; i++) {
		cin >> operations >> t1 >> t2;

		if (operations == 1) {
			change_num(0, nums - 1, 1, t1 - 1, t2 - rawdata[t1 - 1]);
			rawdata[t1 - 1] = t2;
		}
		else cout << get_sum(0, nums - 1, t1 - 1, t2 - 1, 1) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}