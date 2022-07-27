#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define BLANK '.'
#define WALL '*'
#define	COW 'C'
#define INF 2134567890
using namespace std;

struct info {
	int row, col, dir, rot;
};

struct compare {
	bool operator() (const info& a, const info& b) {
		return a.rot > b.rot;
	}
};

int rows, cols;
vector<string> map;
priority_queue<info, vector<info>, compare> pq;
int visited[103][103] = { 0 };
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

bool initialize() {
	cin >> cols >> rows;

	map.resize(rows);
	for (int i = 0; i < rows; i++) {
		cin >> map[i];
		for (int j = 0; j < cols; j++) visited[i][j] = INF;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (map[i][j] == COW) {
				visited[i][j] = 0;
				int nrow, ncol;
				for (int k = 0; k < 4; k++) {
					nrow = i + drow[k]; ncol = j + dcol[k];

					if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] == WALL) continue;
					if (map[nrow][ncol] == COW) return true;

					pq.push({ nrow, ncol, k, 0 });
					visited[nrow][ncol] = 0;
				}
				return false;
			}
		}
	}
}

void operate() {
	info current;
	int nrow, ncol, nrot, ans = INF;
	
	while (!pq.empty()) {
		current = pq.top(); pq.pop();

		if (visited[current.row][current.col] < current.rot) continue;

		for (int i = 0; i < 4; i++) {
			nrow = current.row + drow[i]; ncol = current.col + dcol[i];
			nrot = (current.dir == i ? current.rot : current.rot + 1);
			if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] == WALL || visited[nrow][ncol] < nrot) continue;
			visited[nrow][ncol] = nrot;

			if (map[nrow][ncol] == COW) {
				ans = min(ans, nrot);
			}
			else {
				pq.push({ nrow, ncol, i, nrot });
			}
		}
	}

	cout << ans << endl;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	if (initialize()) {
		cout << 0 << endl;
	}
	else operate();

	return 0;
}