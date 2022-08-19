#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define pii pair<int, pair<int, int>> //black, pos(row, col)
using namespace std;

bool visited[53][53];
int map[53][53];
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };
int sz_map;
priority_queue<pii, vector<pii>, greater<pii>> pq;


void initialize() {
	string st;

	cin >> sz_map;
	for (int i = 0; i < sz_map; i++) {
		cin >> st;
		for (int j = 0; j < sz_map; j++) {
			map[i][j] = st[j] - '0';
		}
	}

	pq.push({ 0, {0, 0} });
	visited[0][0] = true;
}

void dijkstra() {
	int currow, curcol, curblack, nrow, ncol;
	while (!pq.empty()) {
		curblack = pq.top().first;
		currow = pq.top().second.first; curcol = pq.top().second.second;
		pq.pop();

		if (currow == sz_map - 1 && curcol == sz_map - 1) {
			cout << curblack << endl;
			return;
		}		

		for (int k = 0; k < 4; k++) {
			nrow = currow + drow[k];
			ncol = curcol + dcol[k];

			if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map || visited[nrow][ncol]) continue;

			if (map[nrow][ncol] == 0) pq.push({ curblack + 1, {nrow, ncol} });
			else pq.push({ curblack, {nrow, ncol} });

			visited[nrow][ncol] = true;
		}
	}
}

void operate() {
	dijkstra();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
