#include <iostream>
using namespace std;

bool visited[30][30];
int currow = 14, curcol = 14, mov;
int drow[4] = { 0,0,1,-1 }, dcol[4] = { 1,-1,0,0 };
double rate[4], ans = 0;

void initialize() {
	double temp;
	cin >> mov;
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		rate[i] = temp / 100;
	}
}

void DFS(int row = currow, int col = curcol, int depth = 0, double possibility = 1) {
	if (depth == mov) {
		ans += possibility;
		return;
	}

	visited[row][col] = true;

	int nrow, ncol;
	for (int i = 0; i < 4; i++) {
		nrow = row + drow[i]; ncol = col + dcol[i];
		if (visited[nrow][ncol]) continue;
		DFS(nrow, ncol, depth + 1, possibility * rate[i]);
	}

	visited[row][col] = false;
}


void operate() {
	DFS();
	cout.precision(10);
	cout << fixed<< ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}