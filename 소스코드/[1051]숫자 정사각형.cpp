#include <iostream>
#include <algorithm>
using namespace std;

int rawdata[52][52];
int rows, cols;

void initialize() {
	cin >> rows >> cols; cin.get();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			rawdata[i][j] = cin.get() - '0';
		}
		cin.get();
	}
}

bool checksquare(int size) {
	int inc = size - 1, target;
	for (int row = 0; row < rows - size + 1; row++) {
		for (int col = 0; col < cols - size + 1; col++) {
			target = rawdata[row][col];
			if (target == rawdata[row][col + inc] && target == rawdata[row + inc][col] && target == rawdata[row + inc][col + inc]) {
				return true;
			}
		}
	}

	return false;
}

void operate() {
	int minNum = min(rows, cols);

	for (int i = minNum; i >= 1; i--) {
		if (checksquare(i)) {
			cout << i * i << endl;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}