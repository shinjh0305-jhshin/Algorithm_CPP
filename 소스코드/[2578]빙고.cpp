#include <iostream>
#include <vector>
#include <algorithm>
#define IDX(a) find(rawdata.begin(), rawdata.end(), (a)) - rawdata.begin()
using namespace std;

vector<int> rawdata(25);
vector<int> rows_left(5, 5), cols_left(5, 5), diag_left(2, 5); //diag : 왼쪽(0) 오른쪽(1)

void initialize() {
	for (int i = 0; i < 25; i++) {
		cin >> rawdata[i];
	}
}

void operate() {
	int target, idx, row, col, bingos = 0;
	for (int i = 1; i <= 25; i++) {
		cin >> target;
		idx = IDX(target);

		//row 처리
		row = idx / 5;
		rows_left[row]--;
		if (rows_left[row] == 0) bingos++;

		//col 처리
		col = idx % 5;
		cols_left[col]--;
		if (cols_left[col] == 0) bingos++;

		if (row == col) { //왼쪽 대각선
			if (--diag_left[0] == 0) bingos++;
		} 
		if (row + col == 4) { //오른쪽 대각선
			if (--diag_left[1] == 0) bingos++;
		}

		if (bingos >= 3) {
			cout << i << endl;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}