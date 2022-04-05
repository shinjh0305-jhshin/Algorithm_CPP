#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct pos {
	int row;
	int col;
	int ndir; //left,down,right,up
};

int sz;
int graph[26][26];
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,1,0,-1 };
stack<pos> st;
queue<pos> qu;
vector<int> house;

void initialize();
void operate();
//void DFS(int row, int col);
void BFS(int row, int col);

void initialize() {
	cin >> sz; cin.get();

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			graph[i][j] = cin.get() - '0';
		}
		cin.get();
	}
}

void operate() { //BFS
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (graph[i][j]) BFS(i, j);
		}
	}

	sort(house.begin(), house.end());

	cout << house.size() << endl;
	for (int i = 0; i < house.size(); i++) {
		cout << house[i] << endl;
	}
}

void BFS(int row, int col) {
	int houses = 1;
	int currow, curcol, nrow, ncol;

	currow = row; curcol = col;

	qu.push({ row,col,0 });
	graph[row][col] = 0;

	while (!qu.empty()) {
		currow = qu.front().row; curcol = qu.front().col;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			nrow = currow + drow[i];
			ncol = curcol + dcol[i];

			if (nrow < 0 || nrow >= sz || ncol < 0 || ncol >= sz || !graph[nrow][ncol]) continue;

			graph[nrow][ncol] = 0;
			qu.push({ nrow, ncol, 0 });
			houses++;
		}
	}

	house.push_back(houses);
}


//void operate() { //DFS
//	for (int i = 0; i < sz; i++) {
//		for (int j = 0; j < sz; j++) {
//			if (graph[i][j] == 1) DFS(i, j);
//		}
//	}
//	sort(house.begin(), house.end());
//
//	cout << house.size() << endl;
//	for (int i = 0; i < house.size(); i++) {
//		cout << house[i] << endl;
//	}
//}
//
//void DFS(int row, int col) {
//	int houses = 1;
//	int currow, curcol, curdir, nrow, ncol, i;
//
//	currow = row; curcol = col; curdir = 0;
//	graph[row][col] = 0;
//
//	while (1) {
//		for (i = curdir; i < 4; i++) {
//			nrow = currow + drow[i];
//			ncol = curcol + dcol[i];
//
//			if (nrow < 0 || nrow >= sz || ncol < 0 || ncol >= sz || !graph[nrow][ncol]) continue;
//
//			st.push({ currow,curcol,i + 1 }); //자취를 남긴다.
//
//			currow = nrow;
//			curcol = ncol;
//			graph[currow][curcol] = 0;
//			i = -1;
//		}
//
//		if (i >= 4) {
//			if (st.empty()) goto end;
//			currow = st.top().row;
//			curcol = st.top().col;
//			curdir = st.top().ndir;
//
//			st.pop();
//			houses++;
//		}
//	}
//
//end : house.push_back(houses);
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();
	return 0;
}