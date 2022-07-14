#include <iostream>
#include <algorithm>
using namespace std;

int block[103][103];
int rows, cols;

void initialize() {
	cin >> rows >> cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> block[i][j];
		}
	}
}

void operate() {
	int ans = 0;
	int temp, area;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == 0) ans += block[i][j];
			else if (block[i][j] > block[i - 1][j])	ans += block[i][j] - block[i - 1][j];

			if (i == rows - 1) ans += block[i][j];
			else if (block[i][j] > block[i + 1][j]) ans += block[i][j] - block[i + 1][j];

			if (j == 0)	ans += block[i][j];
			else if (block[i][j] > block[i][j - 1]) ans += block[i][j] - block[i][j - 1];

			if (j == cols - 1) ans += block[i][j];
			else if (block[i][j] > block[i][j + 1]) ans += block[i][j] - block[i][j + 1];
		}
	}

	//À§ ¾Æ·¡
	ans += 2 * (rows * cols);

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}