#include <iostream>
#include <algorithm>
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
int rows, cols, lands; //lands : ¶¥ °³¼ö
vector<info> edge;

int getRoot(int num) {
	if (root[num] < 0) return num;
	else return root[num] = getRoot(root[num]);
}

void mergeRoot(int num1, int num2) {
	int root1 = getRoot(num1);
	int root2 = getRoot(num2);

	if (root1 == root2) return;

	if (root1 > root2) swap(root1, root2);

	root1 += root2;
	root[root2] = root1;
}

void initialize() {
	cin >> rows >> cols;

	int temp, nrow, ncol;
	lands = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> temp;

			if (temp) {
				for (int k = 0; k < 4; k++) {
					nrow = i + drow[k]; ncol = j + dcol[k]; //ÇöÀç ¶¥ÀÌ ÀÌ¹Ì Å½»öÇÏ°í ÀÖ´Â ¾î¶² ¶¥ÀÇ ÀÏºÎÀÎ°¡?
					if (nrow<0 || nrow>rows || ncol<0 || ncol>cols || map[nrow][ncol] == 0) continue;
					map[i][j] = map[nrow][ncol];
					break;
				}
				if (map[i][j] == 0) map[i][j] = ++lands;
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
			if (map[nrow][ncol]) { //¶¥ ¹ß°ß!!
				nextLand = map[nrow][ncol];
				if (tempDistance == 1 || curLand == nextLand) break; //¶¥ »çÀÌ °Å¸®°¡ 1ÀÌ°Å³ª, °°Àº ¶¥ÀÏ °æ¿ì

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
}

void operate() {
	makeLandDist();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}