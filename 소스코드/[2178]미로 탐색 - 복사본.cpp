#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;



class maze {
private:
	int rows, cols, nrow, ncol;
	int drow[4] = { 1,0,-1,0 };
	int dcol[4] = { 0,-1,0,1 };
	int** map, **visited;

public:
	void initialize() {
		cin >> rows >> cols; cin.get();
		map = new int*[rows];
		visited = new int*[rows];
		for (int i = 0; i < rows; i++) {
			map[i] = new int[cols];
			visited[i] = new int[cols];
			memset(visited[i], 0, sizeof(int)*cols);
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				map[i][j] = cin.get() - '0';
			}
			cin.get();
		}
	}

	void DFS() {
		int result = doDFS(0, 0, 1);
		cout << result << endl;
	}

	int doDFS(int row, int col, int history) { //history : 그 동안 거쳐간 칸의 개수
		int result = 1000000;
		visited[row][col] = 1;
		for (int i = 0; i < 4; i++) {
			nrow = row + drow[i];
			ncol = col + dcol[i];

			if (nrow < 0 || ncol < 0 || nrow >= rows || ncol >= cols || visited[nrow][ncol] || !map[nrow][ncol]) continue;
			if (nrow == rows - 1 && ncol == cols - 1) return history + 1;

			result = min(result, doDFS(nrow, ncol, history + 1));
		}
		return result;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	maze op;
	op.initialize();
	op.DFS();
	return 0;
}