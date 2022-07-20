//오답 코드 버젼

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 2134567890
using namespace std;

int sz_map;
int map[22][22];
int dm[22][22];
int divided[6];
int ans = INF;

void initialize() {
	cin >> sz_map;
	for (int i = 1; i <= sz_map; i++) {
		for (int j = 1; j <= sz_map; j++) {
			cin >> map[i][j];
		}
	}
}

void calcCity(int x, int y, int d1, int d2) {
	memset(divided, 0, sizeof(divided));
	for (int row = 1; row < x + d1; row++) {
		for (int col = 1; col <= y; col++) {
			if (row >= x && col >= y - row + x) {
				//dm[row][col] = 5;
				divided[5] += map[row][col];
			}
			else //dm[row][col] = 1;
				divided[1] += map[row][col];
		}
	}

	for (int row = 1; row <= x + d2; row++) {
		for (int col = y + 1; col <= sz_map; col++) {
			if (row >= x && col <= y + row - x) {
				//dm[row][col] = 5;
				divided[5] += map[row][col];
			}
			else //dm[row][col] = 2;
				divided[2] += map[row][col];
		}
	}

	for (int row = x + d1; row <= sz_map; row++) {
		for (int col = 1; col < y - d1 + d2; col++) {
			if (row <= x + d1 + d2 && col >= y - 2 * d1 - x + row) {
				//dm[row][col] = 5;
				divided[5] += map[row][col];
			}
			else //dm[row][col] = 3;
				divided[3] += map[row][col];
		}
	}

	for (int row = x + d2 + 1; row <= sz_map; row++) {
		for (int col = y - d1 + d2; col <= sz_map; col++) {
			if (row <= x + d1 + d2 && col <= y + 2 * d2 + x - row) {
				//dm[row][col] = 5;
				divided[5] += map[row][col];
			}
			else //dm[row][col] = 4;
				divided[4] += map[row][col];
		}
	}

	int localmax = -1, localmin = INF;
	for (int i = 1; i <= 5; i++) {
		localmax = max(localmax, divided[i]);
		localmin = min(localmin, divided[i]);
	}

	ans = min(ans, abs(localmax - localmin));
}

void divideCity() {
	for (int x = 1; x <= sz_map - 2; x++) {
		for (int y = 2; y <= sz_map - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= sz_map - x - 1; d1++) {
				for (int d2 = 1; d2 <= sz_map - y && d2 <= sz_map - x - 1; d2++) {
					//if (x + d1 + d2 > sz_map) break;
					calcCity(x, y, d1, d2);
				}
			}
		}
	}
}

void operate() {
	divideCity();
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}