#include <iostream>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

char rawdata[3072][6143];
int level;

void make_triangle(int len, int row, int col) {
	if (len == 3) {
		rawdata[row][col] = '*';
		rawdata[row + 1][col - 1] = rawdata[row + 1][col + 1] = '*';
		for (int i = row + 2, j = col - 2; j <= col + 2; j++) rawdata[i][j] = '*';
		return;
	}
	
	make_triangle(len / 2, row, col);
	make_triangle(len / 2, row + len / 2, col - len / 2);
	make_triangle(len / 2, row + len / 2, col + len / 2);
}

void operate() {
	cin >> level;

	for (int i = 0; i < level; i++) {
		for (int j = 0; j < 2 * level - 1; j++) {
			rawdata[i][j] = ' ';
		}
	}

	make_triangle(level, 0, level - 1);

	for (int i = 0; i < level; i++) {
		for (int j = 0; j < 2 * level - 1; j++) {
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
