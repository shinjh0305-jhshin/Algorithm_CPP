#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int inSet, testing;

void operate() {
	unordered_set<string> rawdata;

	cin >> inSet >> testing;

	string st;
	for (int i = 0; i < inSet; i++) {
		cin >> st;
		rawdata.insert(st);
	}

	int cnt = 0;
	for (int i = 0; i < testing; i++) {
		cin >> st;
		if (rawdata.find(st) != rawdata.end()) {
			cnt++;
		}
	}

	cout << cnt << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}