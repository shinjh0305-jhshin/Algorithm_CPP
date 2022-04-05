#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct pos {
	int row, col;
};

int dRow[4] = { 1,0,-1,0 };
int dCol[4] = { 0,-1,0,1 };

class cabbage {
private:
	int rows, cols, plants, cases;
	int farm[52][52];

public:
	void initialize() {
		cin >> cases; cin.get();
	}

	void operate() {
		for (int k = 0; k < cases; k++) {
			cin >> cols >> rows >> plants; cin.get();

			for (int i = 0; i < rows; i++) {
				memset(farm[i], 0, sizeof(int)*cols);
			}

			int row, col;
			for (int i = 0; i < plants; i++) {
				cin >> col >> row; cin.get();
				farm[row][col] = 1;
			}

			traverse();
		}
	}

	void traverse() {
		int worms = 0;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (farm[i][j] == 1) {
					Work(i, j);
					worms++;
				}
			}
		}

		cout << worms << endl;
	}

	void Work(int row, int col) { //BFS
		queue<pos> qu;
		qu.push({ row, col });
		farm[row][col] = 0;

		int curRow, curCol, nRow, nCol;
		while (!qu.empty()) {
			curRow = qu.front().row; curCol = qu.front().col; qu.pop();

			for (int i = 0; i < 4; i++) {
				nRow = curRow + dRow[i]; nCol = curCol + dCol[i];
				if (nRow < 0 || nRow >= rows || nCol < 0 || nCol >= cols || !farm[nRow][nCol]) continue;

				qu.push({ nRow, nCol });
				farm[nRow][nCol] = 0; //visited
			}
		}
	}

	//void Work(int row, int col) { //iterative DFS
	//	stack<pos> st;
	//	st.push({ row, col });

	//	int curRow, curCol, nRow, nCol;
	//	while (!st.empty()) {
	//		curRow = st.top().row; curCol = st.top().col; st.pop();
	//		farm[curRow][curCol] = 0; //visited

	//		for (int i = 0; i < 4; i++) {
	//			nRow = curRow + dRow[i]; nCol = curCol + dCol[i];
	//			if (nRow < 0 || nRow >= rows || nCol < 0 || nCol >= cols || !farm[nRow][nCol]) continue;
	//			st.push({ nRow, nCol });
	//		} 
	//	}
	//}

	//void Work(int row, int col) { //recursive DFS
	//	int nRow, nCol;

	//	farm[row][col] = 0; //visited

	//	for (int i = 0; i < 4; i++) {
	//		nRow = row + dRow[i]; nCol = col + dCol[i];
	//		if (nRow < 0 || nRow >= rows || nCol < 0 || nCol >= cols || !farm[nRow][nCol]) continue;
	//		Work(nRow, nCol);
	//	}
	//}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cabbage op;
	op.initialize();
	op.operate();
	return 0;
}