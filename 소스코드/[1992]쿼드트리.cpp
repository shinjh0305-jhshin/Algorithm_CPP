#include <iostream>
#include <string>
using namespace std;

struct info {
	int row, col;
};

int rawdata[66][66];
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata; cin.get();
	for (int i = 0; i < sz_rawdata; i++) {
		for (int j = 0; j < sz_rawdata; j++) {
			rawdata[i][j] = cin.get() - '0';
		}
		cin.get();
	}
}

string make_zip(info leftTop, info rightBottom) {
	if ((leftTop.row + 1 == rightBottom.row) && (leftTop.col + 1 == rightBottom.col)) { //가장 작은 단위체
		int row = leftTop.row, col = leftTop.col;
		if (rawdata[row][col] == 1 && rawdata[row][col + 1] == 1 && rawdata[row + 1][col] == 1 && rawdata[row + 1][col + 1] == 1) {
			return "1";
		}
		else if (rawdata[row][col] == 0 && rawdata[row][col + 1] == 0 && rawdata[row + 1][col] == 0 && rawdata[row + 1][col + 1] == 0) {
			return "0";
		}
		else {
			string st;
			st += '(';
			st += rawdata[row][col] + '0';
			st += rawdata[row][col + 1] + '0';
			st += rawdata[row + 1][col] + '0';
			st += rawdata[row + 1][col + 1] + '0';
			st += ')';

			return st;
		}
	}

	else {
		int midRow = (leftTop.row + rightBottom.row) / 2;
		int	midCol = (leftTop.col + rightBottom.col) / 2;

		string st1 = make_zip({ leftTop.row, leftTop.col }, { midRow, midCol });
		string st2 = make_zip({ leftTop.row, midCol + 1 }, { midRow, rightBottom.col });
		string st3 = make_zip({ midRow + 1, leftTop.col }, { rightBottom.row, midCol });
		string st4 = make_zip({ midRow + 1, midCol + 1 }, { rightBottom.row, rightBottom.col });

		if (st1.length()==1 && !st1.compare(st2) && !st2.compare(st3) && !st3.compare(st4)) {
			return st1;
		}
		else {
			string st_result = '(' + st1 + st2 + st3 + st4 + ')';
			return st_result;
		}
	}
}

void operate() {
	cout << make_zip({ 0,0 }, { sz_rawdata - 1, sz_rawdata - 1 }) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	initialize();
	operate();

	return 0;
}

/*
8
00000000
00000000
00001111
00001111
00011111
00111111
00111111
00111111
ans : (0(0011)(0(0111)01)1)

4
1010
1010
1010
1010
*/