#include <iostream>
#include <string>
using namespace std;

string rawdata;
int sz;

void operate() {
	int sz_rawdata = rawdata.length();
	int curNum;

	//À­º¯ Ã³¸®
	for (int j = 0; j < sz_rawdata; j++) {
		curNum = rawdata[j] - '0';
		cout << ' ';
		for (int i = 0; i < sz; i++) {
			if (curNum == 2 || curNum == 3 || curNum == 5 || curNum == 6 || curNum == 7 || curNum == 8 || curNum == 9 || curNum == 0) {
				cout << '-';
			}
			else cout << ' ';
		}
		cout << "  ";
	}
	cout << endl;

	//À­ Áß°£º¯ Ã³¸®
	for (int iter = 0; iter < sz; iter++) {
		for (int j = 0; j < sz_rawdata; j++) {
			curNum = rawdata[j] - '0';
			if (curNum == 4 || curNum == 5 || curNum == 6 || curNum == 8 || curNum == 9 || curNum == 0)
				cout << '|';
			else cout << ' ';
			for (int i = 0; i < sz; i++) cout << ' ';
			if (curNum == 1 || curNum == 2 || curNum == 3 || curNum == 4 || curNum == 7 || curNum == 8 || curNum == 9 || curNum == 0)
				cout << '|';
			else cout << ' ';
			cout << ' ';
		}
		cout << endl;
	}

	//Áß°£º¯ Ã³¸®
	for (int j = 0; j < sz_rawdata; j++) {
		curNum = rawdata[j] - '0';
		cout << ' ';
		for (int i = 0; i < sz; i++) {
			if (curNum == 2 || curNum == 3 || curNum == 5 || curNum == 6 || curNum == 4 || curNum == 8 || curNum == 9) {
				cout << '-';
			}
			else cout << ' ';
		}
		cout << "  ";
	}
	cout << endl;

	//¾Æ·§ Áß°£º¯ Ã³¸®
	for (int iter = 0; iter < sz; iter++) {
		for (int j = 0; j < sz_rawdata; j++) {
			curNum = rawdata[j] - '0';
			if (curNum == 2 || curNum == 6 || curNum == 8 || curNum == 0)
				cout << '|';
			else cout << ' ';
			for (int i = 0; i < sz; i++) cout << ' ';
			if (curNum == 1 || curNum == 3 || curNum == 4 || curNum == 5 || curNum == 6 || curNum == 7 || curNum == 8 || curNum == 9 || curNum == 0)
				cout << '|';
			else cout << ' ';
			cout << ' ';
		}
		cout << endl;
	}

	//¾Æ·§º¯ Ã³¸®
	for (int j = 0; j < sz_rawdata; j++) {
		curNum = rawdata[j] - '0';
		cout << ' ';
		for (int i = 0; i < sz; i++) {
			if (curNum == 2 || curNum == 3 || curNum == 5 || curNum == 6 || curNum == 0 || curNum == 8 || curNum == 9) {
				cout << '-';
			}
			else cout << ' ';
		}
		cout << "  ";
	}
	cout << endl;
}

void initialize() {
	cin >> sz >> rawdata;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}