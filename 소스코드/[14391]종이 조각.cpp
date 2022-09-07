#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int map[5][5];
int rows, cols, ans = -1;

void initialize() {
	string st;
	cin >> rows >> cols;
	
	for (int i = 0; i < rows; i++) {
		cin >> st;
		for (int j = 0; j < cols; j++) {
			map[i][j] = st[j] - '0';
		}
	}
}

void operate() {
	int curSum, ans = -1, temp, curIdx;

	for (int target = 0; target < (1 << rows * cols); target++) { //0 : 가로, 1 : 세로
		curSum = 0;

		for (int row = 0; row < rows; row++) {
			temp = 0;
			for (int col = 0; col < cols; col++) {
				curIdx = row * cols + col;
				if ((target & (1 << curIdx)) == 0) {
					temp *= 10;
					temp += map[row][col];
				}
				else {
					curSum += temp;
					temp = 0;
				}
			}
			curSum += temp;
		}

		for (int col = 0; col < cols; col++) {
			temp = 0;
			for (int row = 0; row < rows; row++) {
				curIdx = row * cols + col;
				if ((target & (1 << curIdx)) != 0) {
					temp *= 10;
					temp += map[row][col];
				}
				else {
					curSum += temp;
					temp = 0;
				}
			}
			curSum += temp;
		}

		ans = max(ans, curSum);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}