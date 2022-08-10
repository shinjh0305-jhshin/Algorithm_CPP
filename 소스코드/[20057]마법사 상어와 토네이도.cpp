#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int drow[4] = { 0,1,0,-1 };
int dcol[4] = { -1,0,1,0 };

double blow[5][5] = {
	{0, 0, 0.02, 0, 0},
	{0, 0.1, 0.07, 0.01, 0},
	{0.05, 1, 0, 0, 0},
	{0, 0.1, 0.07, 0.01, 0},
	{0, 0, 0.02, 0, 0}
};


int map[503][503];
int sz_map;
int ans = 0;

void initialize() {
	cin >> sz_map;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
		}
	}
}

void blowSand(int row, int col, int dir) {
	int oriSand = map[row][col], curSand = map[row][col], movSand;
	int nrow, ncol;


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!blow[i][j] || blow[i][j] == 1) continue;

			nrow = row + (i - 2); ncol = col + (j - 2);
			movSand = floor(oriSand * blow[i][j]);

			if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map) {
				ans += movSand;
			}
			else {
				map[nrow][ncol] += movSand;
			}

			curSand -= movSand;
		}
	}

	nrow = row + drow[dir]; ncol = col + dcol[dir];

	//알파 값 처리
	if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map) {
		ans += curSand;
	}
	else {
		map[nrow][ncol] += curSand;
	}
}

void rotateBlow() {
	double newBlow[5][5];
	memcpy(newBlow, blow, sizeof(blow));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			blow[i][j] = newBlow[j][4 - i];
		}
	}

}

void operate() {
	int dir = 0, mov = 1;
	int currow = sz_map / 2, curcol = sz_map / 2;

	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < mov; j++) {
				currow = currow + drow[dir]; curcol = curcol + dcol[dir];
				//cout << currow << ' ' << curcol << endl;
				blowSand(currow, curcol, dir);
				if (currow == 0 && curcol == 0) {
					cout << ans << endl;
					return;
				}
			}
			dir = dir == 3 ? 0 : dir + 1;
			rotateBlow();
		}
		mov++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}