#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nodes;
int order[40002];

void initialize() {
	cin >> nodes;
	for (int i = 0; i < nodes; i++) {
		cin >> order[i];
	}
}

void operate() {
	int upBound = 0;
	vector<int> rawdata;

	rawdata.push_back(order[0]);
	
	for (int i = 1; i < nodes; i++) {
		if (order[i] > rawdata.back()) {
			rawdata.push_back(order[i]);
		}
		else {
			*lower_bound(rawdata.begin(), rawdata.end(), order[i]) = order[i];
		}
	}

	cout << rawdata.size() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}