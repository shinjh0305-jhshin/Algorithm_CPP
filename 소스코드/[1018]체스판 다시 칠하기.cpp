#include <iostream>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

char map[52][52];
int rows, cols;

void initialize() {
	cin >> rows >> cols; cin.get();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = cin.get();
		}
		cin.get();
	}
}

int check(int row, int col) {
	int flag, temp, ans1 = 0, ans2 = 0; //flag : 시작점이 W면 0, 시작점이 B면 1

	if (map[row][col] == 'W') flag = 0;
	else flag = 1;

	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			temp = (i + j + flag) % 2;

			//case 1 : 첫 시작점을 유지한다.
			if (temp == 0 && map[i][j] == 'B') ans1++;  //W자리에 B가 있는 경우
			else if (temp == 1 && map[i][j] == 'W') ans1++; //B자리에 W가 있는 경우

			//case 2 : 첫 시작점을 변경한다.
			if (temp == 0 && map[i][j] == 'W') ans2++; //B자리에 W가 있는 경우
			else if (temp == 1 && map[i][j] == 'B') ans2++; //W자리에 B가 있는 경우
		}
	}

	return min(ans1, ans2);
}

void operate() {
	int maxrow = rows - 8, maxcol = cols - 8, result = 987654321, temp;

	for (int i = 0; i <= maxrow; i++) {
		for (int j = 0; j <= maxcol; j++) {
			temp = check(i, j);
			result = min(result, temp);
		}
	}

	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}