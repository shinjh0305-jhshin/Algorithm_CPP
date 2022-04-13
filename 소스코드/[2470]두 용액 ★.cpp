//2467·Î ¿¬½À

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int sz_rawdata;
vector<int> rawdata;

struct answer{
	int num1, num2, sum = 2100000000;
};
answer ans;

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);
	
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata.begin(), rawdata.end(), less<int>());
}

void operate() {
	int front = 0, end = sz_rawdata - 1, temp;

	while (front < end) {
		temp = rawdata[front] + rawdata[end];

		if (abs(temp) < ans.sum) {
			ans.num1 = rawdata[front];
			ans.num2 = rawdata[end];
			ans.sum = abs(temp);
		}

		if (temp == 0) return;

		if (temp > 0) end--;
		else front++;
	}
}

void print_result() {
	cout << ans.num1 << ' ' << ans.num2 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	operate();
	print_result();

	return 0;
}

/*
5
-2 4 -99 -1 98
ans : -99 98

5
-101 -100 9999 10000 10001
ans : -101 -100

5
-101 -100 102 10000 10001
ans : -101 102

3
-100 100 105

2
-99 9998
ans : -99 9998

10
-12 -24 52 18 19 -4 16 20 77 -40
ans : -24 20

5
-110 -109 1 1 4
ans : 1 1

*/