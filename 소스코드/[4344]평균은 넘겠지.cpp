#include <iostream>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;

int rawdata[1003];

int main() {
	int cases, students;
	double average, cnt;
	cin >> cases; cin.get();

	for (int k = 0; k < cases; k++) {
		average = cnt = 0;
		cin >> students; cin.get();

		for (int i = 0; i < students; i++) {
			cin >> rawdata[i]; cin.get();
			average += rawdata[i];
		}

		average /= students;

		for (int i = 0; i < students; i++) {
			if (rawdata[i] > average) cnt++;
		}

		cnt = cnt / students * 100;
		cnt = round(cnt * 1000) / 1000;
		printf("%.3lf%%\n", cnt);
	}

	return 0;
}