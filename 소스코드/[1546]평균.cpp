#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<double> original;
	vector<double> modified;

	int datas;
	double sum = 0, maxdata = 0;

	cin >> datas;
	original.resize(datas);
	modified.resize(datas);

	for (int i = 0; i < datas; i++) {
		cin >> original[i];
		maxdata = max(maxdata, original[i]);
	}

	for (int i = 0; i < datas; i++) {
		modified[i] = original[i] / maxdata * 100;
		sum += modified[i];
	}

	cout << sum / datas << endl;

	return 0;
}