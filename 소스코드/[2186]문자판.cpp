#include <iostream>
#include <vector>
#include <string>
#define IDX(a) ((a) - 'A')
#define INF 2134567890
using namespace std;

vector<string> map;
vector<pair<int, int>> letterPos; //row, col �����ϴ� ���ڰ� �ִ� pos
int rows, cols, mov;
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };
int routes[105][105][83];//map[row][col]���� target�� idx��° ���ڷ� �� �� �ִ� ����� ��
string target;

void initialize() {
	cin >> rows >> cols >> mov;
	map.resize(rows);

	for (int i = 0; i < rows; i++) {
		cin >> map[i];
	}
	cin >> target;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (map[i][j] == target[0]) letterPos.push_back({ i, j });
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = 0; k < 83; k++) {
				routes[i][j][k] = INF;
			}
		}
	}
}

int DFS(int row, int col, int idx) {
	if (idx == target.length()) return 1;

	if (routes[row][col][idx + 1] != INF) return routes[row][col][idx + 1];

	int nrow, ncol, ret = 0;
	for (int k = 0; k < 4; k++) { //�ش� index�� �߽����� ������� �����鼭 �˻�
		for (int l = 1; l <= mov; l++) { //���� ����
			nrow = row + drow[k] * l; ncol = col + dcol[k] * l;
			if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] != target[idx]) continue;
			ret += DFS(nrow, ncol, idx + 1);
		}
	}
	return routes[row][col][idx + 1] = ret;
}

void operate() {
	int ans = 0;
	for (const auto& pos : letterPos) {
		ans += DFS(pos.first, pos.second, 1);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}