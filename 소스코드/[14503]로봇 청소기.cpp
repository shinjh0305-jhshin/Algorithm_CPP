#include <iostream>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> map[53];
int rows, cols;
int currow, curcol, curdir;
int drow[4] = { -1,0,1,0 };
int dcol[4] = { 0,1,0,-1 };

void initialize() {
	cin >> rows >> cols;
	cin >> currow >> curcol >> curdir;

	for (int i = 0; i < rows; i++) {
		map[i].resize(cols);
		for (int j = 0; j < cols; j++) {
			cin >> map[i][j];
		}
	}
}

void operate() {
	int ans = 1, ndir, tempdir, i;
	int nrow, ncol;

	while (1) {
		map[currow][curcol] = -1; //청소 완료
		tempdir = curdir + 4;

		for (i = 0; i < 4; i++) {
			ndir = (--tempdir) % 4;
			nrow = currow + drow[ndir]; ncol = curcol + dcol[ndir];

			if (map[nrow][ncol] == 0) {
				currow = nrow; curcol = ncol; curdir = ndir;
				ans++;
				break;
			}
		}
		if (i == 4) {
			nrow = currow - drow[curdir]; ncol = curcol - dcol[curdir];
			if (map[nrow][ncol] == 1) break;
			else {
				currow = nrow; curcol = ncol;
			}
		}
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

