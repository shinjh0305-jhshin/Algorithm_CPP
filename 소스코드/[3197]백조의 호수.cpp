#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
#define ADDR(row, col) ((row)*cols + (col))
#pragma warning (disable:4996)
using namespace std;

struct info {
	int row, col;
};
char map[1502][1502];
int rows, cols;
vector<int> parent, height;
queue<info> qu;
info mov[4] = { {0,1},{1,0},{0,-1},{-1,0} };
info swan_pos[2];

int get_root(int num) {
	if (parent[num] == num) return num;
	return parent[num] = get_root(parent[num]);
}

void merge_root(int num1, int num2) {
	int root1 = get_root(num1);
	int root2 = get_root(num2);

	if (root1 == root2) return;

	if (height[root2] > height[root1]) swap(root1, root2);
	parent[root2] = root1;

	if (height[root1] == height[root2]) height[root1]++;
}

void initialize() {
	int swans = 0;
	cin >> rows >> cols; cin.get();
	parent.resize(rows*cols + 3);
	height.resize(rows*cols + 3);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = cin.get();
			parent[ADDR(i, j)] = ADDR(i, j); height[ADDR(i, j)] = 1;

			if (map[i][j] == 'X') continue;

			if (map[i][j] == '.') {
				if (i > 0 && (map[i - 1][j] == '.' || map[i - 1][j] == 'L')) merge_root(ADDR(i - 1, j), ADDR(i, j));
				if (j > 0 && (map[i][j - 1] == '.' || map[i][j - 1] == 'L')) merge_root(ADDR(i, j - 1), ADDR(i, j));
			}
			else {
				swan_pos[swans] = { i,j };
				swans++;
			}
			qu.push({ i,j });
		}
		cin.get();
	}
}

void operate() {
	int currow, curcol, nrow, ncol, qu_size, days;

	for (days = 0;; days++) {
		if (get_root(ADDR(swan_pos[0].row, swan_pos[0].col)) == get_root(ADDR(swan_pos[1].row, swan_pos[1].col))) {
			cout << days << endl;
			return;
		}

		qu_size = qu.size();

		for (int iter = 0; iter < qu_size; iter++) {
			currow = qu.front().row; curcol = qu.front().col; qu.pop();

			for (int i = 0; i < 4; i++) {
				nrow = currow + mov[i].row; ncol = curcol + mov[i].col;

				if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] == '.') continue;

				map[nrow][ncol] = '.';
				merge_root(ADDR(currow, curcol), ADDR(nrow, ncol));

				for (int j = 0; j < 4; j++) {
					if (map[nrow + mov[j].row][ncol + mov[j].col] == '.') {
						merge_root(ADDR(nrow, ncol), ADDR(nrow + mov[j].row, ncol + mov[j].col));
					}
				}

				qu.push({ nrow,ncol });
			}
		}	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
4 5
XX...
.LXXL
XX...
X....

4 5
XX...
.L..L
XX...
X....
*/