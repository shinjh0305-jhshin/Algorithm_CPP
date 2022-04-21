#include <iostream>
#include <queue>
#define INF 1234567890
#define endl "\n"
using namespace std;

struct info {
	int row, col, cost;
};
struct compare {
	bool operator() (const info& a, const info& b) {
		if (a.cost > b.cost) return true;
		return false;
	}
};
int rawdata[126][126], history[126][126];
int sz_rawdata, test_case = 0;
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };

bool initialize() {
	cin >> sz_rawdata;
	if (sz_rawdata == 0) return false;

	test_case++;
	for (int i = 0; i < sz_rawdata; i++) {
		for (int j = 0; j < sz_rawdata; j++) {
			cin >> rawdata[i][j];
			history[i][j] = INF;
		}
	}
	return true;
}

void dijkstra() {
	priority_queue<info, vector<info>, compare> pq;
	pq.push({ 0,0,rawdata[0][0] });
	history[0][0] = rawdata[0][0];

	int currow, curcol, curcost, nrow, ncol, ncost;
	while (!pq.empty()) {
		currow = pq.top().row; curcol = pq.top().col; curcost = pq.top().cost;
		pq.pop();

		if (curcost > history[currow][curcol]) continue;

		for (int i = 0; i < 4; i++) {
			nrow = currow + drow[i]; ncol = curcol + dcol[i];
			if (nrow < 0 || nrow >= sz_rawdata || ncol < 0 || ncol >= sz_rawdata) continue; //index out of bound

			ncost = curcost + rawdata[nrow][ncol];

			if (ncost < history[nrow][ncol]) {
				pq.push({ nrow, ncol, ncost });
				history[nrow][ncol] = ncost;
			}

		}
	}
}

void operate() {
	dijkstra();
	cout << "Problem " << test_case << ": " << history[sz_rawdata - 1][sz_rawdata - 1] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (initialize()) {
		operate();
	}
}
