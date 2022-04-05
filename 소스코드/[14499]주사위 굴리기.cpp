#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

enum pos {
	top=1, north, east, west, south, bottom
};
struct info {
	int row, col;
};
int curDice[7] = { 0,1,2,3,4,5,6 }; //현재 주사위가 향하고 있는 방향
int numDice[7] = { 0 }; //각 방향에 적혀 있는 숫자
info mov[5] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };

int map[21][21];
int rows, cols, currow, curcol, opers;
vector<int> op;

void initialize() {
	cin >> rows >> cols >> currow >> curcol >> opers;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> map[i][j];
		}
	}

	op.resize(opers);
	for (int i = 0; i < opers; i++) {
		cin >> op[i];
	}
}

void rollDice(int dir) {
	switch (dir) {
		case 1: //오른쪽으로 굴린다
			swap(curDice[top], curDice[east]);
			swap(curDice[top], curDice[west]);
			swap(curDice[bottom], curDice[west]);
			break;
		case 2:
			swap(curDice[top], curDice[west]);
			swap(curDice[top], curDice[east]);
			swap(curDice[bottom], curDice[east]);
			break;
		case 3:
			swap(curDice[top], curDice[north]);
			swap(curDice[top], curDice[south]);
			swap(curDice[bottom], curDice[south]);
			break;
		case 4:
			swap(curDice[top], curDice[south]);
			swap(curDice[top], curDice[north]);
			swap(curDice[bottom], curDice[north]);
			break;
	}
}

void operate() {
	int nrow, ncol;

	for (int i = 0; i < opers; i++) {
		nrow = currow + mov[op[i]].row; ncol = curcol + mov[op[i]].col;

		if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols) continue;

		rollDice(op[i]);
		if (map[nrow][ncol] == 0) map[nrow][ncol] = numDice[curDice[bottom]];
		else {
			numDice[curDice[bottom]] = map[nrow][ncol];
			map[nrow][ncol] = 0;
		}
		currow = nrow; curcol = ncol;
		
		cout << numDice[curDice[top]] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}