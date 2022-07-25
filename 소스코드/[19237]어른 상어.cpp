/*
0. 1�� ��ȣ�� ���� � ���� ���� �����ؼ� ������ ��θ� �ѾƳ� �� �ִ�.
1. ���� ������ ĭ �� �ƹ� ������ ���� ĭ�� �������� ��´�
2. �׷� ĭ�� ������ �ڽ��� ������ �ִ� ĭ�� �������� ��´�.
3. ������ ĭ�� ���� ���϶��� Ư���� �켱������ ������
3-1. �켱������ ���� �ٸ� �� �ְ�, ���� ���� ���� �� ���� �ִ� ���⿡ ���� �� �ٸ� �� �ִ�
4. �̵� �� ����� ������ ��� �̵��� �������� �ٲ��.
5. �ڽ��� ������ �̵��� ĭ�� �Ѹ���. ������ �� k�� �̵��ϰ� ���� �������.
6. �� ĭ�� ���� ������ �� ���� ������, ���� ���� ��ȣ�� ���� �� ���� �������� �״´�.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define EMPTY 0
#define INF 10
using namespace std;

int drow[5] = { 0,-1,1,0,0 }; //�� �� �� �� ����
int dcol[5] = { 0,0,0,-1,1 };

struct info {
	pair<int, int> pos;
	int dir;
};

pair<int, int> smell[22][22]; //����� index, �� �Ѹ� ������ ��ȿ�Ⱓ
int priority[403][6][6]; //���index, ������, �켱��������
info shark[403];
int map[2][22][22]; //�� ��ǥ�� �ִ� ��� index
int sz_map, sharks, leftshark, valid;
int current = 0, after = 1;


void initialize() {
	cin >> sz_map >> sharks >> valid;
	leftshark = sharks;

	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[current][i][j];
			if (map[current][i][j] != EMPTY) {
				shark[map[current][i][j]].pos = { i, j };
				smell[i][j] = { map[current][i][j], valid };
			}
		}
	}
	swap(current, after);

	for (int i = 1; i <= sharks; i++) {
		cin >> shark[i].dir;
	}

	for (int i = 1; i <= sharks; i++) {
		for (int dir = 1; dir <= 4; dir++) {
			for (int pdir = 0; pdir < 4; pdir++) {
				cin >> priority[i][dir][pdir];
			}
		}
	}
}

void operate() {
	int clk = 0;
	int currow, curcol, nrow, ncol, curdir;

	while (leftshark > 1 && clk <= 1000) {
		clk++;
		memset(map[current], 0, sizeof(map[current]));

		for (int i = 1; i <= sharks; i++) {
			if (shark[i].dir == INF) continue;

			const info& curShark = shark[i];
			currow = curShark.pos.first; curcol = curShark.pos.second; curdir = curShark.dir;

			bool foundEmptySpace = false;
			for (int k = 0; k < 4; k++) {
				nrow = currow + drow[priority[i][curdir][k]]; ncol = curcol + dcol[priority[i][curdir][k]];

				if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map) continue;

				if (smell[nrow][ncol].second < clk) { //�� ĭ Ȥ�� ������ ������ ĭ Ȥ�� ���� ������ �� �ѾƳ� �� �ִ�.
					foundEmptySpace = true;
					if (map[current][nrow][ncol]) { //�̹� ������ ����� ��ȣ�� �� �۴�. ���� �� �Ѱܳ���.
						shark[i].dir = INF;
						leftshark--;
						break;
					}					
					
					smell[nrow][ncol].second = 0; //�ش� ĭ�� ������ �ʱ�ȭ�ϰ�
					map[current][nrow][ncol] = i; //���� �� ��ġ�� ������ ǥ���Ѵ�.

					shark[i].pos = { nrow, ncol }; //���� ����� ������ ������Ʈ�Ѵ�
					shark[i].dir = priority[i][curdir][k];

					break;
				}
			}

			if (!foundEmptySpace) { //�� ĭ�� �� ã�Ƽ� �� ������ ���� ĭ�� ã�ƾ� �Ѵ�.
				for (int k = 0; k < 4; k++) {
					nrow = currow + drow[priority[i][curdir][k]]; ncol = curcol + dcol[priority[i][curdir][k]];

					if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map) continue;

					if (smell[nrow][ncol].first == i) { //�� ������ ���� ĭ ã��
						map[current][nrow][ncol] = i; //���� �� ��ġ�� ������ ǥ���Ѵ�.

						shark[i].pos = { nrow, ncol }; //���� ����� ������ ������Ʈ�Ѵ�
						shark[i].dir = priority[i][curdir][k];
						break;
					}
				}
			}
		}

		for (int i = 1; i <= sharks; i++) { //���� �Ѹ���
			if (shark[i].dir == INF) continue; //������ ���!
			const info& curShark = shark[i];
			currow = curShark.pos.first; curcol = curShark.pos.second;

			smell[currow][curcol] = { i, clk + valid };
		}

		swap(current, after);
	}
	
	if (clk > 1000) cout << -1 << endl;
	else cout << clk << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}