#include <iostream>
#define block 'x'
#define made '-'
#define avail '.'
using namespace std;

char map[10003][503];
int rows, cols, cnt = 0;

void initialize() {
	cin >> rows >> cols; cin.get();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = cin.get();
		}
		cin.get();
	}
}

bool DFS(int row, int col) {
	if (col == cols - 1) { //원웅이네 빵집까지 도달한 경우
		map[row][col] = made;
		cnt++;
		return true;
	}

	int nrow, ncol = col + 1;

	for (int i = -1; i <= 1; i++) {
		nrow = row + i;
		if (nrow < 0 || nrow >= rows || map[nrow][ncol] == block || map[nrow][ncol] == made) continue;

		bool found = DFS(nrow, ncol);
		if (found) {
			map[row][col] = made;
			return true;
		} 
	}

	map[row][col] = block; //나중에 다시 여기로 와도 별 가망 없다.
	return false;
}

void operate() {
	for (int i = 0; i < rows; i++) {
		DFS(i, 0);
	}
	cout << cnt << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
5 7
.x...x.
.x...x.
.x.....
.......
.......
ans : 2
*/