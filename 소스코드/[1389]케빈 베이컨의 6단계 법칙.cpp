#include <iostream>
#include <algorithm>
#define endl "\n"
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;

int dat[102][102];
int friends, rels;

void initialize() {
	cin >> friends >> rels;

	for (int i = 1; i <= friends; i++) {
		for (int j = 1; j <= friends; j++) {
			dat[i][j] = INF;
		}
	}
	for (int i = 1; i <= friends; i++) {
		dat[i][i] = 0;
	}
}

void operate() {
	int fr1, fr2;
	for (int i = 0; i < rels; i++) {
		cin >> fr1 >> fr2;
		dat[fr1][fr2] = 1;
		dat[fr2][fr1] = 1;
	}

	for (int k = 1; k <= friends; k++) {
		for (int i = 1; i <= friends; i++) {
			if (dat[i][k] == INF) continue;
			for (int j = i + 1; j <= friends; j++) {
				if (dat[i][k] + dat[k][j] < dat[i][j]) {
					dat[i][j] = dat[j][i] = dat[i][k] + dat[k][j];
				}
			}
		}
	}

	int sum_temp, min = INF, ans;
	for (int i = 1; i <= friends; i++) {
		sum_temp = 0;
		for (int j = 1; j <= friends; j++) {
			sum_temp += dat[i][j];
		}

		if (sum_temp < min) {
			ans = i;
			min = sum_temp;
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}