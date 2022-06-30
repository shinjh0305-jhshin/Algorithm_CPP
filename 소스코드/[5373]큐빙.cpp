#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

enum a {U, F, L, B, R, D}; //¿ß æ’ øﬁ µﬁ ø¿ æ∆
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
	for (int i = 0; i < 3; i++) temp[i] = cube[R][idxOne][i]; //ø¿∏•¬  ∏È ≈∞«Œ!
	

	if (dir == '+') { //Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[R][idxOne][i] = cube[B][idxOne][i]; //µﬁ -> ø¿
		for (int i = 0; i < 3; i++) cube[B][idxOne][i] = cube[L][idxOne][i]; //øﬁ -> µﬁ
		for (int i = 0; i < 3; i++) cube[L][idxOne][i] = cube[F][idxOne][i]; //æ’ -> øﬁ
		for (int i = 0; i < 3; i++) cube[F][idxOne][i] = temp[i]; //ø¿ -> æ’
	}
	else if (dir == '-') { //π›Ω√∞ËπÊ«‚ 
		for (int i = 0; i < 3; i++) cube[R][idxOne][i] = cube[F][idxOne][i]; //ø¿ <- æ’
		for (int i = 0; i < 3; i++) cube[F][idxOne][i] = cube[L][idxOne][i]; //æ’ <- øﬁ
		for (int i = 0; i < 3; i++) cube[L][idxOne][i] = cube[B][idxOne][i]; //øﬁ <- µﬁ
		for (int i = 0; i < 3; i++) cube[B][idxOne][i] = temp[i]; //µﬁ <- ø¿
	}
}

void rotateRightLeft(char side, char dir) {
	int idxOne = 2, idxTwo = 0;
	if (side == 'L') swap(idxOne, idxTwo);

	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = cube[F][i][idxOne]; //æ’ ∏È ≈∞«Œ!

	if (dir == '+') { //Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[F][i][idxOne] = cube[D][i][idxOne]; //æ∆ -> æ’
		for (int i = 0; i < 3; i++) cube[D][i][idxOne] = cube[B][2 - i][idxTwo]; //µﬁ -> æ∆
		for (int i = 0; i < 3; i++) cube[B][i][idxTwo] = cube[U][2 - i][idxOne]; //¿≠ -> µﬁ
		for (int i = 0; i < 3; i++) cube[U][i][idxOne] = temp[i]; //æ’ -> ¿≠
	}
	else if (dir == '-') { //π›Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[F][i][idxOne] = cube[U][i][idxOne]; //¿≠ -> æ’
		for (int i = 0; i < 3; i++) cube[U][i][idxOne] = cube[B][2 - i][idxTwo]; //µﬁ -> ¿≠
		for (int i = 0; i < 3; i++) cube[B][i][idxTwo] = cube[D][2 - i][idxOne];//æ∆ -> µﬁ
		for (int i = 0; i < 3; i++) cube[D][i][idxOne] = temp[i]; //æ’ -> æ∆
	}
}

void rotateFrontBack(char side, char dir) {
	int idxOne = 2, idxTwo = 0;
	if (side == 'B') swap(idxOne, idxTwo);

	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = cube[U][idxOne][i]; //¿≠ ∏È ≈∞«Œ!

	if (dir == '+') { //Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[U][idxOne][i] = cube[L][2 - i][idxOne]; //øﬁ -> ¿≠
		for (int i = 0; i < 3; i++) cube[L][i][idxOne] = cube[D][idxTwo][i]; //æ∆ -> øﬁ
		for (int i = 0; i < 3; i++) cube[D][idxTwo][i] = cube[R][idxTwo][2 - i]; //ø¿ -> æ∆
		for (int i = 0; i < 3; i++) cube[R][idxTwo][i] = temp[i]; //¿≠ -> ø¿
	}
	else if (dir == '-') { //π›Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[U][idxOne][i] = cube[R][i][idxTwo]; //ø¿ -> ¿≠
		for (int i = 0; i < 3; i++) cube[R][i][idxTwo] = cube[D][idxTwo][2 - i]; //æ∆ -> ø¿
		for (int i = 0; i < 3; i++) cube[D][idxTwo][i] = cube[L][i][idxOne];//øﬁ -> æ∆
		for (int i = 0; i < 3; i++) cube[L][i][idxOne] = temp[2 - i];//¿≠ -> øﬁ
	}

}
void operate() {
	int op;
	string opers;

	cin >> op >> opers;

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
	cin >> cases;
	
	while (cases--) {
		initialize();
		operate();
	}

	return 0;
}