#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;
#pragma warning (disable:4996)

string st[20003];
int sz_st;

bool compare(const string& a, const string& b) {
	if (a.length() < b.length()) return true;
	else if (a.length() == b.length()) {
		if (a < b) return true;
	}
	return false;
}

void operate() {
	cin >> sz_st; cin.get();

	for (int i = 0; i < sz_st; i++) {
		getline(cin, st[i]);
	}

	sort(st, st + sz_st, compare);

	cout << st[0] << endl;
	for (int i = 1; i < sz_st; i++) {
		if (st[i] == st[i - 1]) continue;
		cout << st[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	operate();

	return 0;
}