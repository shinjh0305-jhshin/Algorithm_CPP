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
			parent[ADDR(i, j)] = ADDR(i, j); height[ADDR(i, j)] = 1; //호수에 대한 분리집합 밑밥 깔기

			if (map[i][j] == 'X') continue; //빙판이면 지나친다.

			if (map[i][j] == '.') { //자신의 상하좌우를 살펴본 뒤, 호수면 합친다. 약간의 중복에 따른 오버헤드는 무시.
				if (i > 0 && (map[i - 1][j] == '.' || map[i - 1][j] == 'L')) merge_root(ADDR(i - 1, j), ADDR(i, j)); //백조가 있는 곳도 호수임.
				if (j > 0 && (map[i][j - 1] == '.' || map[i][j - 1] == 'L')) merge_root(ADDR(i, j - 1), ADDR(i, j));
			}
			else { //백조 위치 저장한다.
				swan_pos[swans] = { i,j };
				swans++;
			}
			qu.push({ i,j }); //호수거나, 백조가 있는 곳이면, 이 곳을 시작해서 녹이기에 큐에다가 위치를 저장한다.
		}
		cin.get();
	}
}

void operate() {
	int currow, curcol, nrow, ncol, qu_size, days;

	for (days = 0;; days++) {
		if (get_root(ADDR(swan_pos[0].row, swan_pos[0].col)) == get_root(ADDR(swan_pos[1].row, swan_pos[1].col))) {
			cout << days << endl; //두 백조가 만난 경우, 만난 날짜를 리턴한다.
			return;
		}

		qu_size = qu.size();

		for (int iter = 0; iter < qu_size; iter++) { //물이 있는 위치를 모두 평가한다
			currow = qu.front().row; curcol = qu.front().col; qu.pop();

			for (int i = 0; i < 4; i++) {
				nrow = currow + mov[i].row; ncol = curcol + mov[i].col;

				if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] == '.') continue;

				//1. 인접한 얼음을 녹이는 작업.
				map[nrow][ncol] = '.'; //다음 위치를 녹일 수 있다.
				merge_root(ADDR(currow, curcol), ADDR(nrow, ncol)); //호수에 편입시킨다.

				//2.호수-얼음-호수 구조일 때, 앞 호수와 얼음은 하나가 되었고, 뒷 호수와 앞 호수를 하나로 만들어야 한다.
				for (int j = 0; j < 4; j++) {
					if (map[nrow + mov[j].row][ncol + mov[j].col] == '.') { //녹인 위치가 다른 호수가 인접해 있다면, 그곳도 하나의 호수로 합친다.
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