#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 2134567890
using namespace std;

struct info {
	int start, finish, cost;
};
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };
int map[12][12] = { 0 };
int landDist[8][8] = { 0 };
int root[8];
int rows, cols, lands; //lands : 땅 개수
vector<info> edge;

bool compare(const info& a, const info& b) {
	return a.cost < b.cost;
}

int getRoot(int num) {
	if (root[num] < 0) return num;
	else return root[num] = getRoot(root[num]);
}

bool mergeRoot(int num1, int num2) {
	int root1 = getRoot(num1);
	int root2 = getRoot(num2);

	if (root1 == root2) return false;

	if (root[root1] > root[root2]) swap(root1, root2);

	root[root1] += root[root2];
	root[root2] = root1;

	return true;
}

void mergeAdjLand(int row, int col, int curLand) {
	queue<pair<int, int>> qu;

	qu.push({ row, col });
	map[row][col] = curLand;

	int currow, curcol, nrow, ncol;
	while (!qu.empty()) {
		currow = qu.front().first; curcol = qu.front().second;

		qu.pop();
		for (int i = 0; i < 4; i++) {
			nrow = currow + drow[i]; ncol = curcol + dcol[i];
			if (map[nrow][ncol] == -1) {
				qu.push({ nrow, ncol });
				map[nrow][ncol] = curLand;
			}
		}
	}

}

void initialize() {
	cin >> rows >> cols;

	lands = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> map[i][j];
			map[i][j] *= -1; //땅의 index를 위해 음수로 받아서 나중에 1번 땅을 이용하기 편하게 만듬
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (map[i][j] == -1) {
				mergeAdjLand(i, j, ++lands);
			}
		}
	}

	for (int i = 1; i <= lands; i++) {
		for (int j = 1; j <= lands; j++) {
			landDist[i][j] = INF;
		}
		root[i] = -1;
	}
}

void getLandDist(int row, int col) {
	int nrow, ncol, tempDistance;
	int curLand, nextLand;

	for (int dir = 0; dir < 4; dir++) {
		nrow = row; ncol = col; tempDistance = 0;
		curLand = map[row][col];

		while (1) {
			nrow += drow[dir]; ncol += dcol[dir];
			
			if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols) break;
			if (map[nrow][ncol]) { //땅 발견!!
				nextLand = map[nrow][ncol];
				if (tempDistance == 1 || curLand == nextLand) break; //땅 사이 거리가 1이거나, 같은 땅일 경우

				if (curLand > nextLand) swap(curLand, nextLand);
				landDist[curLand][nextLand] = min(landDist[curLand][nextLand], tempDistance);
				break;
			}
			tempDistance++;
		}
	}
}

void makeLandDist() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (map[i][j]) getLandDist(i, j);
		}
	}

	for (int i = 1; i <= lands; i++) {
		for (int j = i; j <= lands; j++) {
			if (landDist[i][j] != INF) edge.push_back({ i, j, landDist[i][j] });
		}
	}
	sort(edge.begin(), edge.end(), compare);
}

void getMinBridge() {
	int result = 0;
	for (auto it : edge) {
		if (mergeRoot(it.start, it.finish)) {
			result += it.cost;
		}
	}

	int targetRoot = getRoot(1); //1번 땅의 root를 기준으로 삼는다
	for (int i = 2; i <= lands; i++) {
		if (getRoot(i) != targetRoot) {
			cout << -1 << endl;
			return;
		}
	}
	cout << result << endl;
}

void operate() {
	makeLandDist();
	getMinBridge();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}