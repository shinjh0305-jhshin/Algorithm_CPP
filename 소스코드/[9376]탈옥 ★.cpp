#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define BLANK '.'
#define WALL '*'
#define DOOR '#'
#define PRISONER '$'
#define INF 2134567890
using namespace std;

struct info {
	int row, col, walls; //walls : 부숴버린 벽의 개수
};

struct compare {
	bool operator() (const info& a, const info& b) {
		return a.walls > b.walls;
	}
};

char map[105][105];
int rows, cols;
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };
int mov[3][105][105];
pair<int, int> man[3]; //row, col


void initialize() {
	cin >> rows >> cols; 
	man[0] = { 0,0 };

	int mans = 1;
	char ch;
	for (int i = 0; i <= rows + 1; i++) {
		for (int j = 0; j <= cols + 1; j++) {
			if (i == 0 || i == rows + 1 || j == 0 || j == cols + 1) map[i][j] = BLANK;
			else {
				cin >> ch;
				map[i][j] = ch;
				if (ch == PRISONER) man[mans++] = { i,j };
			}

			for (int k = 0; k < 3; k++) mov[k][i][j] = INF;
		}
	}
}

void BFS(int ppl) {
	priority_queue<info, vector<info>, compare> pq;

	pq.push({ man[ppl].first, man[ppl].second, 0 });

	int currow, curcol, curbreak;
	int nrow, ncol, nbreak;

	while (!pq.empty()) {
		currow = pq.top().row; curcol = pq.top().col; curbreak = pq.top().walls;
		pq.pop();
		
		for (int i = 0; i < 4; i++) {
			nrow = currow + drow[i]; ncol = curcol + dcol[i]; nbreak = curbreak;
			if (nrow < 0 || nrow > rows + 1 || ncol < 0 || ncol > cols + 1 || map[nrow][ncol] == WALL) continue;
			if (map[nrow][ncol] == DOOR) nbreak++;

			if (mov[ppl][nrow][ncol] > nbreak) {
				mov[ppl][nrow][ncol] = nbreak;
				pq.push({ nrow, ncol, nbreak });
			}
		}
	}
}

void operate() {
	//밖에서, 1번죄수에서, 2번죄수에서 다익스트라를 진행한다
	//
	for (int i = 0; i < 3; i++) {
		BFS(i);
	}

	int ans = INF;

	for (int i = 0; i <= rows + 1; i++) {
		for (int j = 0; j <= cols + 1; j++) {
			if (map[i][j] == WALL) continue;
			for (int k = 0; k < 3; k++) if (mov[k][i][j] == INF) continue;

			int temp = 0;
			for (int k = 0; k < 3; k++) temp += mov[k][i][j];

			if (map[i][j] == DOOR) temp -= 2;
			ans = min(ans, temp);		
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--) {
		initialize();
		operate();
	}
	return 0;
}