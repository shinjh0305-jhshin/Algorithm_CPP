#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct info {
	int mass, speed, dir;
};
stack<info> status[2][52][52];
int sz_map, balls, opers;
int current = 0, previous = 1;
int drow[8] = { -1,-1,0,1,1,1,0,-1 };
int dcol[8] = { 0,1,1,1,0,-1,-1,-1 };

void initialize() {
	cin >> sz_map >> balls >> opers;

	int row, col, mass, speed, dir;
	for (int i = 0; i < balls; i++) {
		cin >> row >> col >> mass >> speed >> dir;
		status[current][row][col].push({ mass, speed, dir });
	}

	swap(previous, current);
}

pair<int, int> nextPos(int currow, int curcol, int speed, int dir) {
	int mov = speed % sz_map;

	int nrow, ncol;

	for (int i = 0; i < mov; i++) {		
		nrow = currow + drow[dir]; ncol = curcol + dcol[dir];
		if (nrow == 0) nrow = sz_map;
		else if (nrow == sz_map + 1) nrow = 1;
		
		if (ncol == 0) ncol = sz_map;
		else if (ncol == sz_map + 1) ncol = 1;

		currow = nrow; curcol = ncol;
	}

	return { currow, curcol };
}

void mergeBalls() {
	int massSum, speedSum, sz_stack;
	int dir;
	bool sameDir;
	
	for (int i = 1; i <= sz_map; i++) {
		for (int j = 1; j <= sz_map; j++) {
			stack<info>& curStack = status[current][i][j];
			sz_stack = curStack.size();

			if (sz_stack >= 2) {
				massSum = speedSum = 0;
				sameDir = true;
				dir = curStack.top().dir % 2;

				while (!curStack.empty()) {
					massSum += curStack.top().mass;
					speedSum += curStack.top().speed;

					if (dir != curStack.top().dir % 2) sameDir = false;

					curStack.pop();
				}
				
				massSum /= 5;
				speedSum /= sz_stack;

				if (massSum == 0) continue; //파이어볼이 소멸된다.

				int curDir = sameDir ? 0 : 1;

				for (int k = 0; k < 4; k++) {
					curStack.push({ massSum, speedSum, curDir });
					curDir += 2;
				}
			}
		}
	}
}

void moveBalls() {
	int num_balls;
	pair<int, int> npos;

	for (int i = 1; i <= sz_map; i++) {
		for (int j = 1; j <= sz_map; j++) {
			num_balls = status[previous][i][j].size();

			while (num_balls--) {
				info& curBall = status[previous][i][j].top();
				npos = nextPos(i, j, curBall.speed, curBall.dir);
				status[current][npos.first][npos.second].push({ curBall.mass, curBall.speed, curBall.dir });
				status[previous][i][j].pop();
			}
		}
	}
}

void operate() {
	for (int i = 0; i < opers; i++) {
		moveBalls();
		mergeBalls();
		swap(current, previous);
	}

	int ans = 0;
	for (int i = 1; i <= sz_map; i++) {
		for (int j = 1; j <= sz_map; j++) {
			while (!status[previous][i][j].empty()) {
				ans += status[previous][i][j].top().mass;
				status[previous][i][j].pop();
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