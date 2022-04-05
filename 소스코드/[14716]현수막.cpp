#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class banner {
private:
	char banner[252][252];
	int row, col;
	pair<int, int> mov[8] = { {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };
	int letters = 0;

public:
	void initialize() {
		cin >> row >> col; cin.get();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> banner[i][j]; cin.get();
			}
		}
	}

	void operate() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (banner[i][j] == '1') {
					dfs(i, j);
					letters++;
				} 
			}
		}
		cout << letters << endl;
	}

	void dfs(int row_idx, int col_idx) {
		banner[row_idx][col_idx] = '0'; //방문함을 표시
		int next_row, next_col;

		for (int i = 0; i < 8; i++) {
			next_row = row_idx + mov[i].first;
			next_col = col_idx + mov[i].second;

			if (next_row < 0 || next_col < 0 || next_row >= row || next_col >= col) continue;
			if (banner[next_row][next_col] == '1') {
				dfs(next_row, next_col);
			}
		}
	}
};

int main() {
	banner op;
	op.initialize();
	op.operate();
	return 0;
}