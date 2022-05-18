#include <iostream>
#define endl "\n"
using namespace std;

int rawdata[100003];
int fenWickTree[100003] = { 0 };
int sz_rawdata, query;

void makeFenWickTree(int idx) {
	int target = rawdata[idx];

	while (idx <= sz_rawdata) {
		fenWickTree[idx] += target;
		idx += (idx&-idx);
	}
}

int getNum(int idx) {
	int ans = 0;

	while (idx >= 1) {
		ans += fenWickTree[idx];
		idx -= (idx&-idx);
	}

	return ans;
}

void initialize() {
	cin >> sz_rawdata >> query;

	rawdata[0] = 0;
	for (int i = 1; i <= sz_rawdata; i++) cin >> rawdata[i];

	for (int i = 1; i <= sz_rawdata; i++) makeFenWickTree(i);
}

void operate() {
	int from, to;

	for (int i = 0; i < query; i++) {
		cin >> from >> to;
		cout << getNum(to) - getNum(from - 1) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}