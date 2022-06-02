#include <iostream>
#include <stack>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
#define blank 0
#define enemy 1
using namespace std;

struct pos { int row, col; };
int ground[16][16]; //전쟁터
int rows, cols, dist, enemies = 0;
pos archers[3]; //궁수의 좌표

void initialize() {
	cin >> rows >> cols >> dist;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> ground[i][j];
			if (ground[i][j] == enemy) enemies++;
		}
	}
}

int killEnemy() {
	set<pair<int, int>> killIdx;

	int row, col, nrow, ncol;
	for (int player = 0; player < 3; player++) { //player : 궁수의 index
		row = archers[player].row; col = archers[player].col; //궁수의 현재 위치

		for (int len = 1; len <= dist; len++) { //len : 사정거리
			for (int dcol = -len; dcol <= len; dcol++) { //col 방향 움직임
				int drow = len - abs(dcol);  //row 방향 움직임

				nrow = row - drow; ncol = col + dcol;
				if (nrow < 0 || ncol < 0 || ncol >= cols || ground[nrow][ncol] == blank) continue;

				killIdx.insert({ nrow, ncol });
				goto next;
			}
		}
	next:;
	}

	for (auto it : killIdx) {
		ground[it.first][it.second] = blank;
	}
	return killIdx.size();
}

int moveDown() {
	int deleted = 0;
	
	for (int col = 0; col < cols; col++) {
		if (ground[rows - 1][col] == enemy) deleted++; //마지막 줄 적은 전부 사라진다.
	}
	for (int row = rows - 2; row >= 0; row--) {
		for (int col = 0; col < cols; col++) {
			ground[row + 1][col] = ground[row][col];
		}
	}
	for (int col = 0; col < cols; col++) {
		ground[0][col] = blank; //첫 번째 줄은 아무것도 없는 상태로 바뀐다.
	}

	return deleted;
}

int playGame() {
	int leftEnemies = enemies, killedEnemies = 0, temp;

	while (leftEnemies) {
		temp = killEnemy(); //죽일 수 있는 적부터 죽인다
		leftEnemies -= temp;
		killedEnemies += temp;

		temp = moveDown(); //내려오는 적들을 보고 제외시킬 적들 수를 구한다.
		leftEnemies -= temp;
	}

	return killedEnemies;
}

void operate() {
	int killedEnemies = -1;
	int copyGround[16][16];

	for (int first = 0; first <= cols - 3; first++) {
		archers[0] = { rows, first };
		for (int second = first + 1; second <= cols - 2; second++) {
			archers[1] = { rows, second };
			for (int third = second + 1; third <= cols - 1; third++) {
				archers[2] = { rows, third };

				memcpy(copyGround, ground, sizeof(ground)); //전쟁터의 원본을 대피시킨다.
				killedEnemies = max(killedEnemies, playGame());
				memcpy(ground, copyGround, sizeof(ground)); //전쟁터 원본을 다시 복귀시킨다.
			}
		}
	}

	cout << killedEnemies << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}