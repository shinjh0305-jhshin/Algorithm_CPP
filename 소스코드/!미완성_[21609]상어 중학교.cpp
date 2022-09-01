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
1. ũ�Ⱑ ���� ū ��� �׷�
2. ������ ����� ������ ���� ū ��� �׷�
3. ���� ����� ���� ū��, ���� ���� ��� ���� ū ��.
*/
int sz_mem, sz_rainbow;

bool visited[22][22]; //������ ����� �湮���� ǥ������ �ʴ´�.
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
		if (map[nrow][ncol] > 0 && visited[nrow][ncol]) continue; //�Ϲ� ����̸�, �湮 �� ���. ������ ����� �湮�߾ �� �湮 ����.
		if (map[nrow][ncol] == rainbow) ret++;

		temp.push({ nrow, ncol });
		DFS(color, nrow, ncol);
	}

}

void operate() {

}