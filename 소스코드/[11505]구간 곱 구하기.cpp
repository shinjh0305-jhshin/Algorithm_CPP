#include <iostream>
#include <vector>
#define endl "\n"
#define ll long long
#define mod 1000000007
#pragma warning (disable:4996)
using namespace std;

int nums, opers = 0;
vector<ll> rawdata;
vector<ll> segTree;

ll make_tree(int start, int end, int idx) {
	if (start == end) return segTree[idx] = rawdata[start];

	int mid = (start + end) / 2;
	return segTree[idx] = (make_tree(start, mid, idx * 2)*make_tree(mid + 1, end, idx * 2 + 1)) % mod;
}

ll get_mul(int start, int end, int left, int right, int idx) { //right, left : 구하려는 범위
	if (left <= start && end <= right) return segTree[idx];
	if (right < start || end < left) return 1;

	int mid = (start + end) / 2;
	return (get_mul(start, mid, left, right, idx * 2)*get_mul(mid + 1, end, left, right, idx * 2 + 1)) % mod;
}

ll change_Tree(ll from, ll to, int start, int end, int target_idx, int idx) { //start--target_idx--end
	if (target_idx < start || end < target_idx) return segTree[idx];
	if (start == end) {
		segTree[idx] = to;
		return segTree[idx];
	}

	int mid = (start + end) / 2;
	return segTree[idx] = (change_Tree(from, to, start, mid, target_idx, idx * 2) * change_Tree(from, to, mid + 1, end, target_idx, idx * 2 + 1)) % mod;
}

void initialize() {
	int temp;
	cin >> nums;

	cin >> temp; opers += temp;
	cin >> temp; opers += temp;

	rawdata.resize(nums);
	segTree.resize(nums * 4);

	for (int i = 0; i < nums; i++) {
		cin >> rawdata[i];
	}

	make_tree(0, nums - 1, 1);
}

void operate() {
	int op, from;
	ll target, to;

	for (int i = 0; i < opers; i++) {
		cin >> op >> from >> to;

		if (op == 1) { //from번째 수를 to로 바꾼다
			target = rawdata[from - 1];
			rawdata[from - 1] = to;
			change_Tree(target, to, 0, nums - 1, from - 1, 1);
		} 
		else {
			cout << get_mul(0, nums - 1, from - 1, to - 1, 1) << endl;
		}
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

5 3 3

1
2
3
4
5
1 3 0
2 2 5
1 3 6
2 2 5
1 4 0
2 4 5
ans : 0 240 0

8 4 4

0
0
0
0
0
0
0
0
1 3 3
2 3 3
1 4 4
2 3 4
1 5 5
2 1 5
1 3 8
2 3 5

ans : 3 12 0 160


*/