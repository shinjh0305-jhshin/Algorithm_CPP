#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> original;
long long target, sz_original;

long long operate(long long start, long long end) {
	if (start == end) return start;

	long long mid = (start + end) / 2;

	long long temp = 0;
	for (int i = 0; i < sz_original; i++) {
		temp += original[i] / mid;
	}

	if (temp < target) return operate(start, mid - 1);
	else if (mid == start) {
		temp = 0;
		for (int i = 0; i < sz_original; i++) {
			temp += original[i] / end;
		}

		if (temp < target) return start;
		else return end;
	}
	else return operate(mid, end);
}

void initialize() {
	int temp;
	cin >> sz_original >> target;
	for (int i = 0; i < sz_original; i++) {
		cin >> temp;
		original.push_back(temp);
	}

	int maxima = 0;
	for (int i = 0; i < sz_original; i++) {
		maxima = max(maxima, original[i]);
	}

	cout << operate(1, maxima) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();

	return 0;
}