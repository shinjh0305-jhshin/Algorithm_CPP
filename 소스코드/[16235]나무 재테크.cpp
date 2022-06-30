#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct info {
	int row, col, age;
};

deque<int> treeAlive[12][12];
vector<pair<int, int>> treeSpread; //row, col
vector<info> treeDead;

int szLand, szTree, targetYear;
int newsoil[12][12], cursoil[12][12];
int drow[8] = { 1,1,0,-1,-1,-1,0,1 }; //남쪽부터 시계방향
int dcol[8] = { 0,-1,-1,-1,0,1,1,1 };

void initialize() {
	cin >> szLand >> szTree >> targetYear;
	for (int i = 1; i <= szLand; i++) {
		for (int j = 1; j <= szLand; j++) {
			cin >> newsoil[i][j];
			cursoil[i][j] = 5;
		}
	}

	int row, col, age;
	for (int i = 0; i < szTree; i++) {
		cin >> row >> col >> age;
		treeAlive[row][col].push_back(age);
	}
}

void spring() {
	for (int i = 1; i <= szLand; i++) {
		for (int j = 1; j <= szLand; j++) {
			if (!treeAlive[i][j].empty()) {
				sort(treeAlive[i][j].begin(), treeAlive[i][j].end());

				size_t sz_treeAlive = treeAlive[i][j].size();
				while (sz_treeAlive--) { //현재 심어진 나무들 전부 검토
					int curTreeAge = treeAlive[i][j][0];
					treeAlive[i][j].pop_front();

					if (curTreeAge <= cursoil[i][j]) { //맨 앞에서 하나씩 빼가면서 검토한다.
						cursoil[i][j] -= curTreeAge;
						treeAlive[i][j].push_back(curTreeAge + 1);

						if ((curTreeAge + 1) % 5 == 0) { //가을에 번식할 수 있는 나무들 모아 놓는다.
							treeSpread.push_back({ i,j });
						}
					}
					else { //죽은 나무는 여름을 위해서 죽은 나무 칸에 넣는다.
						treeDead.push_back({ i, j, curTreeAge });
					}
				}

			}
		}
	}
}

void summer() {
	for (const auto& it : treeDead) {
		cursoil[it.row][it.col] += (it.age / 2);
	}
	treeDead.clear();
}

void autumn() {
	int currow, curcol, nrow, ncol;
	for (const auto& curTree : treeSpread) {
		currow = curTree.first; curcol = curTree.second;

		for (int k = 0; k < 8; k++) {
			nrow = currow + drow[k];
			ncol = curcol + dcol[k];

			if (nrow <= 0 || nrow > szLand || ncol <= 0 || ncol > szLand) continue;

			treeAlive[nrow][ncol].push_back(1);
		}
	}

	treeSpread.clear();
}

void winter() {
	for (int i = 1; i <= szLand; i++) {
		for (int j = 1; j <= szLand; j++) {
			cursoil[i][j] += newsoil[i][j];
		}
	}
}

void operate() {
	for (int year = 0; year < targetYear; year++) {
		spring(); summer(); autumn(); winter();
	}

	size_t answer = 0;
	for (int i = 1; i <= szLand; i++) {
		for (int j = 1; j <= szLand; j++) {
			answer += treeAlive[i][j].size();
		}
	}

	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}