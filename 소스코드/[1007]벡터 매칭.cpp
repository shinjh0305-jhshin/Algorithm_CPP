#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> rawdata[25];
vector<pair<int, int>> leftPoint, rightPoint;
double ans;
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i].first >> rawdata[i].second;
	}

	ans = 2134567890;
}

void getResult() {
	pair<double, double> result = { 0,0 };

	for (int i = 0; i < sz_rawdata / 2; i++) {
		result.first += rightPoint[i].first - leftPoint[i].first;
		result.second += rightPoint[i].second - leftPoint[i].second;
	}

	double temp = sqrt(pow(result.first, 2) + pow(result.second, 2));

	ans = min(ans, temp);
}

void makeCombination(int idx = 0) {
	if (idx == sz_rawdata) {
		getResult();
		return;
	}

	if (leftPoint.size() < sz_rawdata / 2) {
		leftPoint.push_back(rawdata[idx]);
		makeCombination(idx + 1);
		leftPoint.pop_back();
	}
	if (rightPoint.size() < sz_rawdata / 2) {
		rightPoint.push_back(rawdata[idx]);
		makeCombination(idx + 1);
		rightPoint.pop_back();
	}
}

void operate() {
	makeCombination();
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(8);

	int cases;
	cin >> cases;

	while (cases--) {
		initialize();
		operate();
	}
}