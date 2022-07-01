#include <iostream>
#include <vector>
using namespace std;

#define SWAP(a, b, c) ((c)=(a), (a)=(b), (b)=(c))

int partition(vector<pair<int, int>>& vec, int left, int right) {
	pair<int, int> pivot, temp;
	int low, high;

	pivot = vec[left];

	do {
		for (low = left + 1; low <= right; low++) {
			if (vec[low].first < pivot.first) continue;
			else if (vec[low].first == pivot.first) {
				if (vec[low].second < pivot.second) continue;
			}
			break;
		}

		for (high = right; high >= left; high--) {
			if (vec[high].first > pivot.first) continue;
			else if (vec[high].first == pivot.first) {
				if (vec[high].second > pivot.second) continue;
			}
			break;
		}

		if (low < high) {
			SWAP(vec[low], vec[high], temp);
		}
	} while (low < high);

	SWAP(vec[left], vec[high], temp);

	return high;
}

void quick_sort(vector<pair<int, int>>& vec, int left, int right) {
	if (left < right) {
		int q = partition(vec, left, right);
		quick_sort(vec, left, q - 1);
		quick_sort(vec, q + 1, right);
	}
}

void main() {
	vector<pair<int, int>> vec;

	int sz_vec;
	cin >> sz_vec;

	int num1, num2;
	for (int i = 0; i < sz_vec; i++) {
		cin >> num1 >> num2;
		vec.push_back({ num1, num2 });
	}

	quick_sort(vec, 0, sz_vec - 1);

	for (int i = 0; i < sz_vec; i++) {
		cout << vec[i].first << "  " << vec[i].second << endl;
	}
}