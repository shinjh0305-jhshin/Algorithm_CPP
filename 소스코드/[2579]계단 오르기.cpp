#include <iostream>
#include <algorithm>
#define st(a) (stairs - 1 - (a))
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

enum index { adj, sep };
int rawdata[300][2];
int scores[300];
int stairs;

void initialize() {
	cin >> stairs;
	for (int i = 0; i < stairs; i++) {
		cin >> scores[i];
	}
	rawdata[st(0)][adj] = scores[st(0)]; rawdata[st(0)][sep] = 0;
	rawdata[st(1)][adj] = scores[st(0)] + scores[st(1)]; rawdata[st(1)][sep] = 0;
	rawdata[st(2)][sep] = scores[st(0)] + scores[st(2)]; rawdata[st(2)][adj] = 0;
}

void operate() {
	for (int i = 3; i < stairs; i++) {
		rawdata[st(i)][adj] = rawdata[st(i - 1)][sep] + scores[st(i)];
		rawdata[st(i)][sep] = scores[st(i)] + max(rawdata[st(i - 2)][adj], rawdata[st(i - 2)][sep]);
	}

	int answer = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			answer = max(answer, rawdata[i][j]);
		}
	}
	
	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();
	return 0;
}