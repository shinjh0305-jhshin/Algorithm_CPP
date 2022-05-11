#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

struct info {
	int stat, order;
};
bool sortInStat(const info& a, const info& b) {
	return a.stat > b.stat;
}
bool sortInOrder(const info& a, const info& b) {
	return a.order < b.order;
}

info rawdata[500003];
int fenWickTree[500003] = { 0 };
int sz_data;

int getSum(int idx) {
	int ans = 0;
	while (idx > 0) {
		ans += fenWickTree[idx];
		idx -= (idx&-idx);
	}
	return ans;
}

void update(int idx) {
	while (idx <= sz_data) {
		fenWickTree[idx]++;
		idx += (idx&-idx);
	}
}

void initialize() {
	cin >> sz_data;
	for (int i = 1; i <= sz_data; i++) {
		cin >> rawdata[i].stat;
		rawdata[i].order = i;
	}

	sort(rawdata + 1, rawdata + 1 + sz_data, sortInStat);

	for (int i = 1; i <= sz_data; i++) {
		rawdata[i].stat = i;
	}
	
	sort(rawdata + 1, rawdata + 1 + sz_data, sortInOrder);
}

void operate() {
	for (int i = 1; i <= sz_data; i++) {
		cout << getSum(rawdata[i].stat) + 1 << endl;
		update(rawdata[i].stat);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}