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
	

	if ((side == 'U' && dir == '+') || (side == 'D' && dir == '-')) { //Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[R][idxOne][i] = cube[B][idxOne][i]; //µﬁ -> ø¿
		for (int i = 0; i < 3; i++) cube[B][idxOne][i] = cube[L][idxOne][i]; //øﬁ -> µﬁ
		for (int i = 0; i < 3; i++) cube[L][idxOne][i] = cube[F][idxOne][i]; //æ’ -> øﬁ
		for (int i = 0; i < 3; i++) cube[F][idxOne][i] = temp[i]; //ø¿ -> æ’
	}
	else if ((side == 'U' && dir == '-') || (side == 'D' && dir == '+')) { //π›Ω√∞ËπÊ«‚ 
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

	if ((side == 'R' && dir == '+') || (side == 'L' && dir == '-')) { //Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[F][i][idxOne] = cube[D][2 - i][idxTwo]; //æ∆ -> æ’
		for (int i = 0; i < 3; i++) cube[D][i][idxTwo] = cube[B][i][idxTwo]; //µﬁ -> æ∆
		for (int i = 0; i < 3; i++) cube[B][i][idxTwo] = cube[U][2 - i][idxOne]; //¿≠ -> µﬁ
		for (int i = 0; i < 3; i++) cube[U][i][idxOne] = temp[i]; //æ’ -> ¿≠
	}
	else if ((side == 'R' && dir == '-') || (side == 'L' && dir == '+')) { //π›Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[F][i][idxOne] = cube[U][i][idxOne]; //¿≠ -> æ’
		for (int i = 0; i < 3; i++) cube[U][i][idxOne] = cube[B][2 - i][idxTwo]; //µﬁ -> ¿≠
		for (int i = 0; i < 3; i++) cube[B][i][idxTwo] = cube[D][i][idxTwo];//æ∆ -> µﬁ
		for (int i = 0; i < 3; i++) cube[D][i][idxTwo] = temp[2 - i]; //æ’ -> æ∆
	}
}

void rotateFrontBack(char side, char dir) {
	int idxOne = 2, idxTwo = 0;
	if (side == 'B') swap(idxOne, idxTwo);

	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = cube[U][idxOne][i]; //¿≠ ∏È ≈∞«Œ!

	if ((side == 'F' && dir == '+') || (side == 'B' && dir == '-')) { //Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[U][idxOne][i] = cube[L][2 - i][idxOne]; //øﬁ -> ¿≠
		for (int i = 0; i < 3; i++) cube[L][i][idxOne] = cube[D][idxOne][2 - i]; //æ∆ -> øﬁ
		for (int i = 0; i < 3; i++) cube[D][idxOne][i] = cube[R][idxTwo][i]; //ø¿ -> æ∆
		for (int i = 0; i < 3; i++) cube[R][i][idxTwo] = temp[i]; //¿≠ -> ø¿
	}
	else if ((side == 'F' && dir == '-') || (side == 'B' && dir == '+')) { //π›Ω√∞ËπÊ«‚
		for (int i = 0; i < 3; i++) cube[U][idxOne][i] = cube[R][i][idxTwo]; //ø¿ -> ¿≠
		for (int i = 0; i < 3; i++) cube[R][i][idxTwo] = cube[D][idxOne][i]; //æ∆ -> ø¿
		for (int i = 0; i < 3; i++) cube[D][idxOne][i] = cube[L][2 - i][idxOne];//øﬁ -> æ∆
		for (int i = 0; i < 3; i++) cube[L][i][idxOne] = temp[2 - i];//¿≠ -> øﬁ
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