#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sz, maxScore = -1;
vector<int> rawdata(1005);

void initialize() {
	cin >> sz;
	for (int i = 0; i < sz; i++) {
		cin >> rawdata[i];
		maxScore = max(maxScore, rawdata[i]);
	}
}

void operate() {
	double newScoreSum = 0;
	for (const int& a : rawdata) {
		newScoreSum += (double)a / maxScore * 100;
	}

	cout << newScoreSum / sz;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	operate();

	return 0;
}