#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 2134567890
#define BLANK	0
#define WALL 1
#define VIRUS 2

using namespace std;

int sz_map, virus, emptySpace = 0, virusPlace = 0, ans = INF;
int map[52][52];
pair<pair<int, int>, bool> virusPos[12]; //viruspos, virusactivated
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> sz_map >> virus;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
			if (map[i][j] == VIRUS) {
				virusPos[virusPlace++].first = { i, j };
			}
			else if (map[i][j] == BLANK) {
				emptySpace++;
			}
		}
	}
}

int spreadVirus() {
	queue<pair<int, int>> qu; //row, col
	bool visited[52][52] = { false };
	int leftBlank = emptySpace;

	for (int i = 0; i < virusPlace; i++) {
		if (virusPos[i].second) {
			const pair<int, int>& pos = virusPos[i].first;
			qu.push(pos);
			visited[pos.first][pos.second] = true;
		}
	}

	int sz_queue, currow, curcol, nrow, ncol, time = 0;
	while (!qu.empty()) {
		if (leftBlank == 0) {
			return time;
		}
		sz_queue = qu.size();
		while (sz_queue--) {
			currow = qu.front().first; curcol = qu.front().second;
			qu.pop();

			for (int k = 0; k < 4; k++) {
				nrow = currow + drow[k]; ncol = curcol + dcol[k];
				if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map || visited[nrow][ncol] || map[nrow][ncol] == WALL) continue;

				if (map[nrow][ncol] == BLANK) {
					leftBlank--;
				}
				visited[nrow][ncol] = true;
				qu.push({ nrow, ncol });
			}
		}
		time++;
	}

	return INF;
}

void activateVirus(int activated = 0, int idx = 0) {
	if (activated == virus) {
		ans = min(ans, spreadVirus());
		return;
	}
	if (idx == virusPlace) return;

	virusPos[idx].second = true;
	activateVirus(activated + 1, idx + 1);
	
	virusPos[idx].second = false;
	activateVirus(activated, idx + 1);
}

void operate() {
	activateVirus();
	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}