#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#define BLANK '.'
#define DIRTY '*'
#define BLOCK 'x'
#define CLEANER 'o'
using namespace std;

struct info {
	int row, col, cleaned;
};

bool visited[(1 << 10) + 5][22][22];
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };
int rows, cols, num_dirty;
pair<int, int> dirtyIndex[12]; //row, col
pair<int, int> robotIndex;
vector<string> map;

bool initialize() {
	cin >> cols >> rows;
	if (rows == 0 || cols == 0) {
		return false;
	}

	map.resize(rows);
	string st;

	for (int i = 0; i < rows; i++) {
		cin >> map[i];
	}

	num_dirty = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (map[i][j] == BLANK || map[i][j] == BLOCK) continue;

			if (map[i][j] == DIRTY) {
				dirtyIndex[num_dirty++] = { i, j };
			} else if (map[i][j] == CLEANER) {
				map[i][j] = BLANK;
				robotIndex = { i, j };
			}
		}
	}

	memset(visited, false, sizeof(visited));

	return true;
}

void operate() {
	queue<info> qu;
	qu.push({ robotIndex.first, robotIndex.second, 0 });
	visited[0][robotIndex.first][robotIndex.second] = true;

	int currow, curcol, curclean, nclean, nrow, ncol, mov = 1, sz_queue;

	while (1) {
		if (qu.empty()) {
			cout << -1 << endl;
			return;
		}

		sz_queue = qu.size();
		while (sz_queue--) {
			currow = qu.front().row; curcol = qu.front().col; curclean = qu.front().cleaned;
			qu.pop();

			for (int k = 0; k < 4; k++) {
				nrow = currow + drow[k]; ncol = curcol + dcol[k];
				if ( nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] == BLOCK || visited[curclean][nrow][ncol]) continue;
				nclean = curclean;	

				if (map[nrow][ncol] == DIRTY) {
					for (int i = 0; i < num_dirty; i++) {
						if (dirtyIndex[i] == make_pair(nrow, ncol)) {
							nclean |= (1 << i);

							if (nclean == ((1 << num_dirty) - 1)) {
								cout << mov << endl;
								return;
							}
							break;
						}
					}
				}

				if (!visited[nclean][nrow][ncol]) {
					visited[nclean][nrow][ncol] = true;
					qu.push({ nrow, ncol, nclean });
				}
			}
		}
		mov++;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (initialize()) {
		operate();
	}

	return 0;
}