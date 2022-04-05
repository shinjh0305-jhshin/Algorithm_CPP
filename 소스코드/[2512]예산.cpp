#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> query;
int sz_query, target;

void initialize() {
	cin >> sz_query;
	query.resize(sz_query);

	for (int i = 0; i < sz_query; i++) {
		cin >> query[i];
	}

	cin >> target;
}

void operate() {
	int left = 0, right = target, mid, sum = 0, max_query = 0, temp;

	for (int i = 0; i < sz_query; i++) {
		sum += query[i];
		if (sum > target) goto next;
		max_query = max(max_query, query[i]);
	}

	cout << max_query << endl;
	return;

next:;
	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;

		for (int i = 0; i < sz_query; i++) {
			if (query[i] > mid) sum += mid;
			else sum += query[i];
		}

		if (sum > target) right = mid - 1;
		else {
			temp = mid;
			left = mid + 1;
		}
	}

	cout << temp << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}