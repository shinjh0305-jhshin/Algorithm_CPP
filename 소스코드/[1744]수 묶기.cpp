#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

vector<int> rawdata;
int sz_rawdata, negative, positive;

void initialize() {
	int temp;
	cin >> sz_rawdata;
	negative = positive = 0;

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> temp;

		rawdata.push_back(temp);
		if (temp > 0) positive++;
		else if (temp <= 0) negative++;
	}

	sort(rawdata.begin(), rawdata.end());
}

void operate() {
	int answer = 0, mov = 0;
	for (; mov < negative - 1; mov += 2) {
		answer += (rawdata[mov] * rawdata[mov + 1]);
	}
	if (negative % 2) {
		answer += rawdata[mov];
	}

	mov = sz_rawdata - 1;
	for (; mov > negative; mov -= 2) {
		if (rawdata[mov - 1] == 1) answer += (rawdata[mov] + rawdata[mov - 1]);
		else answer += (rawdata[mov] * rawdata[mov - 1]);
	}
	if (positive % 2) {
		answer += rawdata[mov];
	}

	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
8 -8 -7 -6 0 1 2 3 4
ans : 71
9 -8 -7 -6 0 1 2 3 4 7
ans : 91
7 -1 -1 0 0 1 1 2
ans : 5
*/