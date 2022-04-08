#include <iostream>
#include <queue>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct node {
	int row, col;
};
struct compare {
	bool operator()(const node& a, const node& b) {
		if (a.row > b.row) return true;
		else if (a.row == b.row) {
			if (a.col > b.col) return true;
		}
		return false;
	}
};
node curShark;
node mov[4] = { {-1,0},{0,-1},{1,0},{0,1} };
int map[21][21];
int sz_map, sz_shark = 2;

bool eat_fish(int& duration, int& num_fish_eaten) {
	priority_queue<node, vector<node>, compare> pq;
	queue<node> next;
	int duration_inc = 0; //마지막에 duration의 증분
	int currow, curcol, nrow, ncol, sz_next;
	bool found = false;
	bool visited[21][21] = { false };

	next.push(curShark);
	visited[curShark.row][curShark.col] = true;

	while (!next.empty()) {
		duration_inc++;
		sz_next = next.size();

		for (int iter = 0; iter < sz_next; iter++) {
			currow = next.front().row; curcol = next.front().col; next.pop();

			for (int i = 0; i < 4; i++) {
				nrow = currow + mov[i].row; ncol = curcol + mov[i].col;
				
				if (nrow<0 || nrow>=sz_map || ncol<0 || ncol>=sz_map || map[nrow][ncol] > sz_shark || visited[nrow][ncol]) continue;

				if (map[nrow][ncol] > 0 && map[nrow][ncol] < sz_shark) {
					pq.push({ nrow, ncol });
					found = true;
				}
				else if (!found) {
					next.push({ nrow, ncol });
					visited[nrow][ncol] = true;
				}
			}
		}

		if (!pq.empty()) {
			currow = pq.top().row; curcol = pq.top().col;
			curShark.row = currow; curShark.col = curcol;

			duration += duration_inc;
			num_fish_eaten++;
			
			if (sz_shark == num_fish_eaten) {
				sz_shark++;
				num_fish_eaten = 0;
			}
			map[currow][curcol] = 0;
			return true;
		}
	}

	return false;
	//0. 시작 전, 최초 상어 위치를 next에 넣고, duration 증분을 저장 할 변수를 선언한다.
	//1. 현재 위치에서 움직일 수 있는 공간을 살펴본다. (for loop 4 iter). 이 때,최초의 pq size를 누군가는 갖고 있어야 한다.
	//1-1. 그 공간에 먹을 수 있는 물고기가 있으면, pq에 넣는다.
	//1-2. 그 공간에 먹을 수 있는 물고기가 없으면, 그 공간 좌표를 next에 넣는다.

	//2. pq가 empty가 아니라면, pq의 top을 먹고, duration에 증분을 더한 뒤 true를 리턴한다.
	//3. 그렇지 않다면, 1로 돌아간다

}

void initialize() {
	cin >> sz_map;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				curShark.row = i;
				curShark.col = j;
				map[i][j] = 0;
			}
		}
	}
}

void operate() {
	int duration = 0, num_fish_eaten = 0;

	while (eat_fish(duration, num_fish_eaten));

	cout << duration << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}