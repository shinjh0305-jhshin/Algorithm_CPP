#include <iostream>
#include <algorithm>
#define	endl "\n"
#pragma warning (disable:4996)
using namespace std;

class tetromino {
private:
	int paper[502][502];
	int row, col;
	int sum_max = 0;
	pair<int, int> mov[4] = { {1,0}, {0,-1}, {-1,0}, {0,1} };

public:
	void initialize() {
		cin >> row >> col;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> paper[i][j];
			}
		}
	}

	void operate() {
		int cur_row, cur_col;
		for (cur_row = 0; cur_row < row; cur_row++) { //ㅗ 모양을 제외한 나머지 모양에 대한 작업
			for (cur_col = 0; cur_col < col; cur_col++) {
				dfs(cur_row, cur_col, 0, 0);
			}
		}

		int sum;
		cur_row = 1, cur_col; //                               ▦
		while (cur_row < row) { //						     ▦▦▦
			for (cur_col = 2; cur_col < col; cur_col++) {
				sum = paper[cur_row - 1][cur_col - 1] + paper[cur_row][cur_col - 2] + paper[cur_row][cur_col - 1] + paper[cur_row][cur_col];
				sum_max = max(sum_max, sum);
			}
			cur_row++;
		}

		cur_row = 2, cur_col; //                               ▦
		while (cur_row < row) { //						     ▦▦
			for (cur_col = 1; cur_col < col; cur_col++) { //   ▦
				sum = paper[cur_row - 2][cur_col] + paper[cur_row - 1][cur_col - 1] + paper[cur_row - 1][cur_col] + paper[cur_row][cur_col];
				sum_max = max(sum_max, sum);
			}
			cur_row++;
		}

		cur_row = 1, cur_col; //                              ▦▦▦
		while (cur_row < row) { //						        ▦
			for (cur_col = 2; cur_col < col; cur_col++) {
				sum = paper[cur_row - 1][cur_col - 2] + paper[cur_row - 1][cur_col - 1] + paper[cur_row - 1][cur_col] + paper[cur_row][cur_col - 1];
				sum_max = max(sum_max, sum);
			}
			cur_row++;
		}

		cur_row = 2, cur_col; //                              ▦
		while (cur_row < row) { //						      ▦▦
			for (cur_col = 1; cur_col < col; cur_col++) {//   ▦
				sum = paper[cur_row - 2][cur_col - 1] + paper[cur_row - 1][cur_col - 1] + paper[cur_row - 1][cur_col] + paper[cur_row][cur_col - 1];
				sum_max = max(sum_max, sum);
			}
			cur_row++;
		}

		cout << sum_max << endl;
	}

	void dfs(int cur_row, int cur_col, int depth, int sum) {
		sum += paper[cur_row][cur_col];
		if (depth == 3) {
			sum_max = max(sum, sum_max);
		}
		else {
			int next_row, next_col, temp;
			for (int i = 0; i < 4; i++) {
				next_row = cur_row + mov[i].first; next_col = cur_col + mov[i].second;

				if (next_row < 0 || next_col < 0 || next_row >= row || next_col >= col || paper[next_row][next_col] == 0) continue;
				else {
					temp = paper[cur_row][cur_col];
					
					paper[cur_row][cur_col] = 0;
					dfs(next_row, next_col, depth + 1, sum);
					paper[cur_row][cur_col] = temp;
				}
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	tetromino op;
	op.initialize();
	op.operate();
	return 0;
}