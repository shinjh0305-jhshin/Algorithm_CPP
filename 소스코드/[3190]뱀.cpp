#include <iostream>
#include <vector>
#include <deque>
#define endl "\n"
#define apple 'A'
#define snake 'S'
#define nothing ' '
#define left 'L'
#define right 'D'
#define TURN_LEFT(a) ((a) = (((a) + 3) % 4))
#define TURN_RIGHT(a) ((a) = (((a) + 1) % 4))
#pragma warning (disable:4996)
using namespace std;

struct pos {
	int row, col;
};
pos direction[4] = { {0,1},{1,0},{0,-1},{-1,0} };
vector<int> map[103];
vector<pair<int, char>> rota;
deque<pos> pos_snake;
int sz_map, sz_rota;

void initialize() {
	int num_apple;
	int row, col;

	cin >> sz_map >> num_apple;
	for (int i = 1; i <= sz_map; i++) {
		map[i].resize(sz_map + 2);
		for (int j = 1; j <= sz_map; j++) {
			map[i][j] = nothing;
		}
	}

	for (int i = 0; i < num_apple; i++) {
		cin >> row >> col;
		map[row][col] = apple;
	}

	cin >> sz_rota;
	rota.resize(sz_rota);

	for (int i = 0; i < sz_rota; i++) {
		cin >> rota[i].first >> rota[i].second;
	}
	
	map[1][1] = snake;
	pos_snake.push_back({ 1,1 });
}

void operate() {
	int curdir = 0; //현재 뱀 머리 방향
	int currow = 1, curcol = 1; //현재 뱀 머리 위치
	int nrow, ncol, delrow, delcol, time_elapsed = 0, rota_idx = 0;

	while (1) {
		nrow = currow + direction[curdir].row;
		ncol = curcol + direction[curdir].col;

		if (nrow<1 || nrow>sz_map || ncol<1 || ncol>sz_map || map[nrow][ncol] == snake) break;

		if (map[nrow][ncol] == nothing) {
			delrow = pos_snake.front().row; delcol = pos_snake.front().col; pos_snake.pop_front();
			map[delrow][delcol] = nothing;
		}

		map[nrow][ncol] = snake;
		pos_snake.push_back({ nrow, ncol });
		currow = nrow; curcol = ncol;
		
		time_elapsed++;

		if (rota_idx < sz_rota && rota[rota_idx].first == time_elapsed) {
			if (rota[rota_idx].second == left) TURN_LEFT(curdir);
			else TURN_RIGHT(curdir);
			rota_idx++;
		}
	}

	cout << time_elapsed + 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}