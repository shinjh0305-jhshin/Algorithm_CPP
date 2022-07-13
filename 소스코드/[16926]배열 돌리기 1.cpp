#include <iostream>
#include <algorithm>
using namespace std;

int rawdata[2][303][303];
int rows, cols, rotas; //rows, cols 는 실제 개수보다 1개 적다

void initialize() {
	cin >> rows >> cols >> rotas;

	rows--; cols--; //indexing 을 위해서 쉽게 바꾼다

	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			cin >> rawdata[0][i][j];
		}
	}
}

void doRotate(int idx) {
	int mrow = idx, Mrow = rows - idx; //m : 시작, M : 종료
	int mcol = idx, Mcol = cols - idx; 

	int sizeSquare = (Mrow - mrow + 1) * (Mcol - mcol + 1);
	int Rotas = rotas % sizeSquare; //온전한 n 바퀴는 제거한다.

	int currow, curcol, leftRotas;
	for (int row = mrow; row <= Mrow; row++) {
		for (int col = mcol; col <= Mcol;) {
			currow = row; curcol = col; leftRotas = Rotas;

			while (1) {
				if ((currow == Mrow && curcol != Mcol) || curcol == mcol) { //좌변, 아랫변에 있을 경우
					if ((Mrow - currow) + (Mcol - curcol) < leftRotas) { //우상변까지 갈 수 있다
						leftRotas -= (Mrow - currow) + (Mcol - curcol);
						currow = Mrow; curcol = Mcol;
					}
					else { //우하단까지 못 간다	
						if ((Mrow - currow) <= leftRotas) { //아랫변까지는 갈 수 있다
							leftRotas -= Mrow - currow;
							currow = Mrow;
							curcol += leftRotas;
						}
						else {
							currow += leftRotas;
						}
						break;
					}
				}
				else { //우변, 윗변에 있을 경우
					if ((currow - mrow) + (curcol - mcol) < leftRotas) { //좌상단까지 갈 수 있다
						leftRotas -= (currow - mrow) + (curcol - mcol);
						currow = mrow; curcol = mcol;
					}
					else { //좌상단까지 못 간다
						if (currow - mrow <= leftRotas) { //윗변까지는 갈 수 있다
							leftRotas -= currow - mrow;
							currow = mrow;
							curcol -= leftRotas;
						}
						else {
							currow -= leftRotas;
						}
						break;
					}
				}
			}

			rawdata[1][currow][curcol] = rawdata[0][row][col];

			if (row == mrow || row == Mrow) col++;
			else col += Mcol - mcol;
		}
	}
}


void operate() {
	int iter = min(rows, cols) / 2;

	for (int i = 0; i <= iter; i++) {
		doRotate(i);
	}

	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			cout << rawdata[1][i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}