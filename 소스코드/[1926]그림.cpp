#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int rows, cols;
int painting[502][502];
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> rows >> cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> painting[i][j];
		}
	}
}

int DFS(int row, int col) {
	painting[row][col] = 0;

	int nrow, ncol;
	int answer = 1;
	for (int i = 0; i < 4; i++) {
		nrow = row + drow[i];
		ncol = col + dcol[i];

		if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || !painting[nrow][ncol]) continue;

		answer += DFS(nrow, ncol);
	}

	return answer;
}

void operate() {
	int maxArea = -1, areas = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (painting[i][j]) {
				areas++;
				maxArea = max(maxArea, DFS(i, j));
			}
		}
	}
	
	if (areas == 0) maxArea = 0;

	cout << areas << endl;
	cout << maxArea << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}