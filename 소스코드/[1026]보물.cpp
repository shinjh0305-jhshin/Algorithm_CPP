#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> a, b;

int main() {
	int nums, temp;
	cin >> nums; cin.get();

	for (int i = 0; i < nums; i++) {
		cin >> temp; cin.get();
		a.push_back(temp);
	}

	for (int i = 0; i < nums; i++) {
		cin >> temp; cin.get();
		b.push_back(temp);
	}

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), less<int>());

	int result = 0;
	for (int i = 0; i < nums; i++) {
		result += a[i] * b[i];
	}

	cout << result << endl;
	return 0;
}