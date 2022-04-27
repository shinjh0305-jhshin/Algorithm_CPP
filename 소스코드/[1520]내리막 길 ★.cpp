#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int map[502][502];
int dp[502][502];
int rows, cols;

int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,1,0,-1 };

void initialize() {
	cin >> rows >> cols;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> map[i][j];
			dp[i][j] = -1; //아직 탐색을 하지 않았음을 의미.
		}
	}	
}

int DFS(int row, int col) {
	int nrow, ncol, temp;

	if (row == rows - 1 && col == cols - 1) return 1; //도착 지점에 도달했다. 도착지점에서 루프를 돌아서 다시 도착지점으로 오는 것은 불가.(경우의 수 없음)
	if (dp[row][col] != -1) return dp[row][col]; //이미 한 번 방문한 곳이다. 즉, 이 곳에서 내리막 경로가 몇 개가 발생하는지 이미 구했다.

	dp[row][col] = 0; //초기화

	for (int i = 0; i < 4; i++) {
		nrow = row + drow[i]; ncol = col + dcol[i];

		//확인조건 : 다음 방문 후보지가 더 낮은 곳에 있는가?
		//방문 여부는 확인 안한다. 방문 했던 곳에서는 몇 갈래 길이 발생하는지 구해와야 하기 때문.
		//사실상 단방향 이동만 가능하기에 방문 여부를 체크하지 않는다.
		if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] >= map[row][col]) continue;

		dp[row][col] += DFS(nrow, ncol);
	}
	return dp[row][col];
}

void operate() {
	cout << DFS(0, 0) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}
