#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int rawdata[2][100][100];
int previous = 0, current = 1;

int rows, cols, queries; //rows, cols는 실제 개수보다 1개 적다. indexing 편리하게 하기 위함.

void initialize() {
	cin >> rows >> cols >> queries;
	
	rows--; cols--; //index를 위해서 편리하게 바꾼다.

	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			cin >> rawdata[0][i][j];
		}
	}
}

void oper1_inverseUpDown() {
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			rawdata[current][i][j] = rawdata[previous][rows - i][j];
		}
	}

	swap(previous, current);
}

void oper2_inverseLeftRight() {
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			rawdata[current][i][j] = rawdata[previous][i][cols - j];
		}
	}

	swap(previous, current);
}

void oper3_rotateRight() {
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			rawdata[current][j][rows - i] = rawdata[previous][i][j];
		}
	}

	swap(previous, current);
	swap(rows, cols);
}

void oper4_rotateLeft() {
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			rawdata[current][cols - j][i] = rawdata[previous][i][j];
		}
	}

	swap(previous, current);
	swap(rows, cols);
}

void oper5_forward() {
	int middleRow = rows / 2 + 1, middleCol = cols / 2 + 1;

	//1 to 2
	for (int row = 0; row < middleRow; row++) {
		for (int col = 0; col < middleCol; col++) {
			rawdata[current][row][col + middleCol] = rawdata[previous][row][col];
		}
	}

	//2 to 3
	for (int row = 0; row < middleRow; row++) {
		for (int col = middleCol; col <= cols; col++) {
			rawdata[current][row + middleRow][col] = rawdata[previous][row][col];
		}
	}

	//3 to 4
	for (int row = middleRow; row <= rows; row++) {
		for (int col = middleCol; col <= cols; col++) {
			rawdata[current][row][col - middleCol] = rawdata[previous][row][col];
		}
	}

	//4 to 1
	for (int row = middleRow; row <= rows; row++) {
		for (int col = 0; col < middleCol; col++) {
			rawdata[current][row - middleRow][col] = rawdata[previous][row][col];
		}
	}

	swap(current, previous);
}

void oper6_backward() {
	int middleRow = rows / 2 + 1, middleCol = cols / 2 + 1;

	//1 to 4
	for (int row = 0; row < middleRow; row++) {
		for (int col = 0; col < middleCol; col++) {
			rawdata[current][row + middleRow][col] = rawdata[previous][row][col];
		}
	}

	//2 to 1
	for (int row = 0; row < middleRow; row++) {
		for (int col = middleCol; col <= cols; col++) {
			rawdata[current][row][col - middleCol] = rawdata[previous][row][col];
		}
	}

	//3 to 2
	for (int row = middleRow; row <= rows; row++) {
		for (int col = middleCol; col <= cols; col++) {
			rawdata[current][row - middleRow][col] = rawdata[previous][row][col];
		}
	}

	//4 to 3
	for (int row = middleRow; row <= rows; row++) {
		for (int col = 0; col < middleCol; col++) {
			rawdata[current][row][col + middleCol] = rawdata[previous][row][col];
		}
	}

	swap(current, previous);
}

void operate() {
	int op;
	for (int i = 0; i < queries; i++) {
		cin >> op;
		if (op == 1) oper1_inverseUpDown();
		else if (op == 2) oper2_inverseLeftRight();
		else if (op == 3) oper3_rotateRight();
		else if (op == 4) oper4_rotateLeft();
		else if (op == 5) oper5_forward();
		else oper6_backward();
	}

	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			cout << rawdata[previous][i][j] << ' ';
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