#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#define BLANK '.'
#define MINERAL 'x'
using namespace std;

int rows, cols;
int clusterIdx[103][103];
vector<string> map;
int drow[5] = { 0,1,0,-1,0 };
int dcol[5] = { 0,0,-1,0,1 };
int minCol, maxCol;

void initialize() {
	cin >> rows >> cols;
	map.resize(rows + 1);

	string st;

	for (int i = rows; i >= 1; i--) {
		cin >> st;
		st = '.' + st;
		map[i] = st;
	}
}

void getClusterDown(int idx) {
	int blankIdx = 1, maxDown = 1234567890; //������ �� �ִ� ĭ�� �ִ� ����
	int temprow, dist;

	for (int col = minCol; col <= maxCol; col++) {
		for (int row = rows; row >= 1; row--) {
			if (map[row][col] == MINERAL && clusterIdx[row][col] == idx) { //���� Ŭ�����Ϳ� ���Ե� �̳׶� ã��
				for (temprow = row - 1; temprow >= 1; temprow--) { //���� Ŭ������ �ٷ� �Ʒ� �̳׶����� Ž�� ����(temprow)
					if (map[temprow][col] == MINERAL || temprow == 1) { //���ٴ��̵� �̳׶��̵� ���� ���θ��� �庮 �߰�
						if (clusterIdx[temprow][col] == idx) { //���� ���� Ŭ�����Ϳ� �Ҽӵ� �̳׶��̸�, �� �̳׶����� Ž�� ����
							row = temprow;
						}
						else { //row ���� temprow ���� �Ÿ���ŭ�� ������ ��, row�� temprow�� �缳��
							if (map[temprow][col] == BLANK) dist = row - temprow;
							else dist = row - temprow - 1;

							maxDown = min(maxDown, dist);
							row = temprow;
							break;
						}
					}
				}
			}
		}
	}

	for (int col = minCol; col <= maxCol; col++) {
		for (int row = 1; row <= rows; row++) {
			if (clusterIdx[row][col] == idx) {
				map[row - maxDown][col] = MINERAL;
				map[row][col] = BLANK;
			}
		}
	}

}

bool DFS(int row, int col, int idx) { //idx : Ŭ������ ��ȣ
	clusterIdx[row][col] = idx;
	minCol = min(minCol, col);
	maxCol = max(maxCol, col);

	int nrow, ncol;
	bool isGrounded = row == 1 ? true : false; //���� ��� �ִ°�?

	for (int i = 1; i <= 4; i++) {
		nrow = row + drow[i];
		ncol = col + dcol[i];

		if (nrow <= 0 || nrow > rows || ncol < 0 || ncol > cols || map[nrow][ncol] == BLANK || clusterIdx[nrow][ncol]) continue;

		bool temp = DFS(nrow, ncol, idx);

		isGrounded = temp == true ? true : isGrounded;
	}

	return isGrounded;
}

void findCluster(int row, int col) {
	memset(clusterIdx, 0, sizeof(clusterIdx));

	int nrow, ncol, targetCluster = 0;
	for (int i = 1; i <= 4; i++) {
		nrow = row + drow[i]; ncol = col + dcol[i];

		if (nrow <= 0 || nrow > rows || ncol < 0 || ncol > cols || map[nrow][ncol] == BLANK || clusterIdx[nrow][ncol]/*visited*/) continue;

		minCol = 2134567890; maxCol = -1;
		if (!DFS(nrow, ncol, i)) { //�ı� Ŭ������ �߰�!
			targetCluster = i;
			break;
		}
	}

	if (targetCluster) getClusterDown(targetCluster);
}

void operate() {
	int shots, row, col;
	bool found;
	cin >> shots;

	for (int i = 0; i < shots; i++) {
		cin >> row;
		found = false;

		if (i % 2 == 0) { //¦�� ȸ������ ���ʿ��� ���
			for (col = 1; col <= cols; col++) {
				if (map[row][col] == MINERAL) {
					map[row][col] = BLANK;
					found = true;
					break;
				}
			}
		}
		else { //Ȧ�� ȸ������ �����ʿ��� ���
			for (col = cols; col >= 1; col--) {
				if (map[row][col] == MINERAL) {
					map[row][col] = BLANK;
					found = true;
					break;
				}
			}
		}

		if (found) findCluster(row, col);
	}

	for (int i = rows; i >= 1; i--) {
		for (int j = 1; j <= cols; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}