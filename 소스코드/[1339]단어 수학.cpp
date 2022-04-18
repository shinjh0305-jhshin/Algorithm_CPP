#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define idx(a) ((a)-'A')
using namespace std;

struct info {
	char key;
	int num;
};

bool compare(const info& a, const info& b) {
	if (a.num > b.num) return true;
	return false;
}

vector<string> rawdata;
info localSum[26];
int sz_rawdata;

void operate() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	for (int i = 0; i < 26; i++) {
		localSum[i].key = 'A' + i;
		localSum[i].num = 0;
	}

	int len_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		len_rawdata = rawdata[i].length();
		for (int j = 0; j < len_rawdata; j++) {
			localSum[idx(rawdata[i][j])].num += (int)pow(10, len_rawdata - j - 1);
		}
	}

	sort(localSum, localSum + 26, compare);

	int resultNum = 0, assignNum = 9;
	for (int i = 0;; i++) {
		if (localSum[i].num) {
			resultNum += assignNum * (localSum[i].num);
			assignNum--;
		}
		else break;
	}

	cout << resultNum << endl;


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}