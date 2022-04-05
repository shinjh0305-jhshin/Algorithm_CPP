#include <iostream>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

char rawdata[6563][6563];
int target;

void make_square(int len, int row, int col) {
	if (len == 3) {
		rawdata[row + 1][col + 1] = ' ';
		return;
	}
	
	int inc = len / 3;

	for (int i = row + inc; i < row + 2 * inc; i++) {
		for (int j = col + inc; j < col + 2 * inc; j++) {
			rawdata[i][j] = ' ';
		}
	}

	make_square(len / 3, row, col);
	make_square(len / 3, row, col + inc);
	make_square(len / 3, row, col + 2 * inc);
	make_square(len / 3, row + inc, col);
	make_square(len / 3, row + inc, col + 2 * inc);
	make_square(len / 3, row + 2 * inc, col);
	make_square(len / 3, row + 2 * inc, col + inc);
	make_square(len / 3, row + 2 * inc, col + 2 * inc);
}

void operate() {
	cin >> target;

	for (int i = 1; i <= target; i++) {
		for (int j = 1; j <= target; j++) {
			rawdata[i][j] = '*';
		}
	}

	make_square(target, 1, 1);

	for (int i = 1; i <= target; i++) {
		for (int j = 1; j <= target; j++) {
			cout << rawdata[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	operate();

	return 0;
}