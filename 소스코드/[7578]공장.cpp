// https://justicehui.github.io/koi/2018/11/20/BOJ7578/
// 세그트리 이용해서 다시 풀기!

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sz_rawdata;
long long result = 0;
vector<int> rawdata, temp;
unordered_map<int, int> sorted;

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);
	temp.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	int temp;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> temp;
		sorted.insert({ temp, i });
	}
}

void make_sort(int left, int right) {
	if (left == right) return;
	
	int mid = (left + right) / 2;
	make_sort(left, mid);
	make_sort(mid + 1, right);

	int left_mov = left, right_mov = mid + 1, idx = left;
	long long from_right = 0;

	while (left_mov <= mid && right_mov <= right) {
		if (sorted[rawdata[left_mov]] < sorted[rawdata[right_mov]]) {
			result += from_right;
			temp[idx++] = rawdata[left_mov++];
		}
		else {
			from_right++;
			temp[idx++] = rawdata[right_mov++];
		}
	}
	
	while (left_mov <= mid) {
		result += from_right;
		temp[idx++] = rawdata[left_mov++];
	}
	while (right_mov <= right) {
		temp[idx++] = rawdata[right_mov++];
	}

	for (int i = left; i <= right; i++) {
		rawdata[i] = temp[i];
	}
}

void operate() {
	make_sort(0, sz_rawdata - 1);
	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
/*
8
121 852 45 128 456 129 7896 123
456 852 121 129 7896 128 123 45
*/