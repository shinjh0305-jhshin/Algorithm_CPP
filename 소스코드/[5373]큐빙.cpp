#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

enum a {U, F, L, B, R, D}; //위 앞 왼 뒷 오 아
char color[6] = { 'w', 'r', 'g', 'o', 'b', 'y' };
char cube[6][3][3];

void initialize() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = color[i];
			}
		}
	}
}

void rotateUpDown(char side, char dir) {
	int idxOne = 0;
	if (side == 'D') idxOne = 2;

	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = cube[R][idxOne][i]; //오른쪽 면 키핑!
	

	if ((side == 'U' && dir == '+') || (side == 'D' && dir == '-')) { //시계방향
		for (int i = 0; i < 3; i++) cube[R][idxOne][i] = cube[B][idxOne][i]; //뒷 -> 오
		for (int i = 0; i < 3; i++) cube[B][idxOne][i] = cube[L][idxOne][i]; //왼 -> 뒷
		for (int i = 0; i < 3; i++) cube[L][idxOne][i] = cube[F][idxOne][i]; //앞 -> 왼
		for (int i = 0; i < 3; i++) cube[F][idxOne][i] = temp[i]; //오 -> 앞
	}
	else if ((side == 'U' && dir == '-') || (side == 'D' && dir == '+')) { //반시계방향 
		for (int i = 0; i < 3; i++) cube[R][idxOne][i] = cube[F][idxOne][i]; //오 <- 앞
		for (int i = 0; i < 3; i++) cube[F][idxOne][i] = cube[L][idxOne][i]; //앞 <- 왼
		for (int i = 0; i < 3; i++) cube[L][idxOne][i] = cube[B][idxOne][i]; //왼 <- 뒷
		for (int i = 0; i < 3; i++) cube[B][idxOne][i] = temp[i]; //뒷 <- 오
	}

	char targetSide[3][3]; //회전하는 면도 같이 회전시켜준다.
	int sideIdx = side == 'U' ? 0 : 5;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			targetSide[row][col] = cube[sideIdx][row][col];
		}
	}

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (dir == '+') cube[sideIdx][row][col] = targetSide[2 - col][row]; //시계방향 회전
			else cube[sideIdx][row][col] = targetSide[col][2 - row]; //반시계방향 회전
		}
	}
}

void rotateRightLeft(char side, char dir) {
	int idxOne = 2, idxTwo = 0;
	if (side == 'L') swap(idxOne, idxTwo);

	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = cube[F][i][idxOne]; //앞 면 키핑!

	if ((side == 'R' && dir == '+') || (side == 'L' && dir == '-')) { //시계방향
		for (int i = 0; i < 3; i++) cube[F][i][idxOne] = cube[D][2 - i][idxTwo]; //아 -> 앞
		for (int i = 0; i < 3; i++) cube[D][i][idxTwo] = cube[B][i][idxTwo]; //뒷 -> 아
		for (int i = 0; i < 3; i++) cube[B][i][idxTwo] = cube[U][2 - i][idxOne]; //윗 -> 뒷
		for (int i = 0; i < 3; i++) cube[U][i][idxOne] = temp[i]; //앞 -> 윗
	}
	else if ((side == 'R' && dir == '-') || (side == 'L' && dir == '+')) { //반시계방향
		for (int i = 0; i < 3; i++) cube[F][i][idxOne] = cube[U][i][idxOne]; //윗 -> 앞
		for (int i = 0; i < 3; i++) cube[U][i][idxOne] = cube[B][2 - i][idxTwo]; //뒷 -> 윗
		for (int i = 0; i < 3; i++) cube[B][i][idxTwo] = cube[D][i][idxTwo];//아 -> 뒷
		for (int i = 0; i < 3; i++) cube[D][i][idxTwo] = temp[2 - i]; //앞 -> 아
	}

	char targetSide[3][3]; //회전하는 면도 같이 회전시켜준다.
	int sideIdx = side == 'R' ? 4 : 2;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			targetSide[row][col] = cube[sideIdx][row][col];
		}
	}

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (dir == '+') cube[sideIdx][row][col] = targetSide[2 - col][row]; //시계방향 회전
			else cube[sideIdx][row][col] = targetSide[col][2 - row]; //반시계방향 회전
		}
	}
}

void rotateFrontBack(char side, char dir) {
	int idxOne = 2, idxTwo = 0;
	if (side == 'B') swap(idxOne, idxTwo);

	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = cube[U][idxOne][i]; //윗 면 키핑!

	if ((side == 'F' && dir == '+') || (side == 'B' && dir == '-')) { //시계방향
		for (int i = 0; i < 3; i++) cube[U][idxOne][i] = cube[L][2 - i][idxOne]; //왼 -> 윗
		for (int i = 0; i < 3; i++) cube[L][i][idxOne] = cube[D][idxOne][2 - i]; //아 -> 왼
		for (int i = 0; i < 3; i++) cube[D][idxOne][i] = cube[R][i][idxTwo]; //오 -> 아
		for (int i = 0; i < 3; i++) cube[R][i][idxTwo] = temp[i]; //윗 -> 오
	}
	else if ((side == 'F' && dir == '-') || (side == 'B' && dir == '+')) { //반시계방향
		for (int i = 0; i < 3; i++) cube[U][idxOne][i] = cube[R][i][idxTwo]; //오 -> 윗
		for (int i = 0; i < 3; i++) cube[R][i][idxTwo] = cube[D][idxOne][i]; //아 -> 오
		for (int i = 0; i < 3; i++) cube[D][idxOne][i] = cube[L][2 - i][idxOne];//왼 -> 아
		for (int i = 0; i < 3; i++) cube[L][i][idxOne] = temp[2 - i];//윗 -> 왼
	}

	char targetSide[3][3]; //회전하는 면도 같이 회전시켜준다.
	int sideIdx = side == 'F' ? 1 : 3;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			targetSide[row][col] = cube[sideIdx][row][col];
		}
	}

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (dir == '+') cube[sideIdx][row][col] = targetSide[2 - col][row]; //시계방향 회전
			else cube[sideIdx][row][col] = targetSide[col][2 - row]; //반시계방향 회전
		}
	}

}
void operate() {
	int op;
	string opers;

	cin >> op; cin.get();
	getline(cin, opers); 

	char curop, curdir;
	for (int i = 0; i < opers.length(); i += 3) {
		curop = opers[i];
		curdir = opers[i + 1];

		if (curop == 'U' || curop == 'D') {
			rotateUpDown(curop, curdir);
		}
		else if (curop == 'R' || curop == 'L') {
			rotateRightLeft(curop, curdir);
		}
		else {
			rotateFrontBack(curop, curdir);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[U][i][j];
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases;
	cin >> cases; cin.get();
	
	while (cases--) {
		initialize();
		operate();
	}

	return 0;
}