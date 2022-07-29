#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define DOOR '#'
#define BLANK '.'
#define MIRROR '!'
#define WALL '*'
#define INF 2134567890
using namespace std;

struct info {
	int row, col, reflect, dir;
};
struct compare {
	bool operator() (const info& a, const info& b) {
		return a.reflect > b.reflect;
	}
};
vector<string> map;
int sz_map;
priority_queue<info, vector<info>, compare> pq;
int visited[55][55][4];
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };

int initialize() {
	cin >> sz_map;
	map.resize(sz_map);

	for (int i = 0; i < sz_map; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			for (int k = 0; k < 4; k++) {
				visited[i][j][k] = INF;
			}
		}
	}

	int nrow, ncol;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			if (map[i][j] == DOOR) {
				map[i][j] = WALL;
				for (int k = 0; k < 4; k++) {
					visited[i][j][k] = 0;
					nrow = i + drow[k]; ncol = j + dcol[k];
					if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map || map[nrow][ncol] == WALL) continue;
					if (map[nrow][ncol] == DOOR) return 1;

					visited[nrow][ncol][k] = 0;
					pq.push({ nrow, ncol, 0, k });
				}
				return 0;
			}
		}
	}
}

void operate() {
	int currow, curcol, curdir, nrow, ncol, ndir, curreflect, nreflect, iter;
	int ans = INF;

	while (!pq.empty()) {
		currow = pq.top().row; curcol = pq.top().col; curdir = pq.top().dir;  curreflect = pq.top().reflect;
		pq.pop();

		if (visited[currow][curcol][curdir] < curreflect) continue;

		if (map[currow][curcol] == MIRROR) iter = 3;
		else iter = 1;

		for (int i = 0; i < iter; i++) {
			if (i == 0) ndir = curdir;
			else if (i == 1) ndir = curdir + 1 == 4 ? 0 : curdir + 1;
			else if (i == 2) ndir = curdir - 1 == -1 ? 3 : curdir - 1;

			nrow = currow + drow[ndir]; ncol = curcol + dcol[ndir];
			if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map || map[nrow][ncol] == WALL) continue;

			nreflect = ndir == curdir ? curreflect : curreflect + 1;

			if (map[nrow][ncol] == DOOR) {
				ans = min(ans, nreflect);
				continue;
			}

			if (visited[nrow][ncol][ndir] <= nreflect) continue;
			
			visited[nrow][ncol][ndir] = nreflect;
			pq.push({ nrow, ncol, nreflect, ndir });

		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	if (initialize() == 1) {
		cout << 0 << endl;
	}
	else operate();

	return 0;
}