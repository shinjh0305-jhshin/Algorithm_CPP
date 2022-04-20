#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[40001];
int lis[40001];

int binarySearch(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (lis[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int j = 0;
	lis[0] = arr[0];
		int i = 1;
	while (i < n) {
		if (lis[j] < arr[i]) {
			lis[j + 1] = arr[i];
			j += 1;
		}
		else {
			int pos = binarySearch(0, j, arr[i]);
			lis[pos] = arr[i];
		}
		i += 1;
	}
	cout << j + 1;
	return 0;
}

//int sz_rawdata, idx = 0;
//vector<int> rawdata, dp;
//
//void initialize() {
//	cin >> sz_rawdata;
//	rawdata.resize(sz_rawdata);
//	dp.resize(sz_rawdata);
//
//	for (int i = 0; i < sz_rawdata; i++) {
//		cin >> rawdata[i];
//	}
//}
//
//void makedp(int left, int right, int target) {
//	int mid;
//
//	while (left < right) {
//		mid = (left + right) / 2;
//
//		if (dp[mid] == target) return;
//
//		if (dp[mid] < target) {
//			left = mid + 1;
//		}
//		else {
//			right = mid;
//		}
//	}
//	dp[left] = target;
//}
//
//void operate() {
//	dp[0] = rawdata[0];
//
//	for (int i = 1; i < sz_rawdata; i++) {
//		if (rawdata[i] > dp[idx]) {
//			dp[++idx] = rawdata[i];
//		}
//		else {
//			makedp(0, idx, rawdata[i]);
//		}
//	}
//
//	cout << idx + 1 << endl;
//	for (int i = 0; i <= idx; i++) {
//		cout << dp[i] << ' ';
//	}
//	cout << endl;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	initialize();
//	operate();
//
//	return 0;
//}

/*
6
10 5 20 10 15 14

9
3 1 4 6 2 2 0 3 6
*/