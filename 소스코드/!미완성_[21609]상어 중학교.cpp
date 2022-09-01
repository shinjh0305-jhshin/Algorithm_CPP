#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#define black -1
#define rainbow 0
#define INF -2134567890
using namespace std;

stack<pair<int, int>> mem, temp;
/*
1. 크기가 가장 큰 블록 그룹
2. 무지개 블록의 개수가 가장 큰 블록 그룹
3. 기준 블록의 행이 큰것, 행이 같을 경우 열이 큰 것.
*/
int sz_mem, sz_rainbow;

bool visited[22][22]; //무지개 블록은 방문으로 표시하지 않는다.
int map[22][22];
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };
int sz_map, colors;

void initialize() {
	cin >> sz_map >> colors;

	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
		}
	}
}

int DFS(int color, int row, int col) {
	visited[row][col] = true;

	int nrow, ncol, ret = 0;
	for (int k = 0; k < 4; k++) {
		nrow = row + drow[k]; ncol = col + dcol[k];

		if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map || map[nrow][ncol] == black) continue;
		if (map[nrow][ncol] > 0 && visited[nrow][ncol]) continue; //일반 블록이며, 방문 한 경우. 무지개 블록은 방문했어도 또 방문 가능.
		if (map[nrow][ncol] == rainbow) ret++;

		temp.push({ nrow, ncol });
		DFS(color, nrow, ncol);
	}

}

void operate() {

}