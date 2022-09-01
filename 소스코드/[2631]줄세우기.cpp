#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

void operate() {
	int nums, temp;
	cin >> nums;

	int idx;
	for (int i = 0; i < nums; i++) {
		cin >> temp;

		if (vec.empty() || temp > vec.back()) {
			vec.push_back(temp);
		}
		else {
			idx = upper_bound(vec.begin(), vec.end(), temp) - vec.begin();
			vec[idx] = temp;
		}
	}

	cout << nums - vec.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}