#include <iostream>
#include <queue>
#include <algorithm>
#define endl "\n"
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;

struct info {
	int currow, curcol, curcrack;
};
int rows, cols;
int map[102][102];
int history[102][102];
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,1,0,-1 };

struct compare {
	bool operator()(const info &a, const info &b) {
		if (a.curcrack > b.curcrack) return true;
		return false;
	}
};

void initialize() {
	cin >> cols >> rows; cin.get();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = cin.get() - '0';
			history[i][j] = INF;
		}
		cin.get();
	}
}

void operate() {
	priority_queue<info, vector<info>, compare> pq;

	//int ans = INF;
	pq.push({ 0,0,0 });
	history[0][0] = 0; //출발지에서는 파괴할 벽이 0개임

	while (!pq.empty()) {
		int currow, curcol, cursum, nrow, ncol, nsum;

		currow = pq.top().currow; curcol = pq.top().curcol; cursum = pq.top().curcrack; 
		pq.pop();

		if (currow == rows - 1 && curcol == cols - 1) {
			cout << cursum << endl;
			return;
		}

		if (map[currow][curcol] == -1) continue; //이미 최소 파괴로 방문했는지 확인

		map[currow][curcol] = -1; //이미 방문한 곳임을 의미

		for (int i = 0; i < 4; i++) {
			nrow = currow + drow[i]; ncol = curcol + dcol[i];
			
			if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] == -1) continue;

			nsum = cursum + map[nrow][ncol];
			if (nsum <= history[nrow][ncol]) {
				pq.push({ nrow, ncol, nsum });
				history[nrow][ncol] = nsum;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}
