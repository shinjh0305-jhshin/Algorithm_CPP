#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

struct info {
	int row, col;
};
int map[52][52];
bool visited[52][52] = { false };
int sz_map, lowerBound, upperBound;
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> sz_map >> lowerBound >> upperBound;

	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
		}
	}
}

void operate() {
	queue<info> bfsqu, historyqu;
	int days = -1, currow, curcol, curppl, nrow, ncol, nppl, movppl, movcity, newppl;
	bool moved = true;

	while (moved) {
		moved = false; //오늘 인구 변화가 발생했는지
		days++;

		for (int i = 0; i < sz_map; i++) {
			for (int j = 0; j < sz_map; j++) {
				if (!visited[i][j]) {
					bfsqu.push({ i,j });
					historyqu.push({ i,j });

					movppl = movcity = 0; //연합을 이룬 인구 및 도시의 수
					visited[i][j] = true;

					while (!bfsqu.empty()) {
						currow = bfsqu.front().row; curcol = bfsqu.front().col; curppl = map[currow][curcol]; 
						bfsqu.pop();
						
						movppl += map[currow][curcol]; 
						movcity++; 

						for (int k = 0; k < 4; k++) {
							nrow = currow + drow[k]; ncol = curcol + dcol[k];
							nppl = abs(curppl - map[nrow][ncol]);

							if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map ||
								visited[nrow][ncol] || nppl < lowerBound || nppl > upperBound) continue;

							visited[nrow][ncol] = true;
							moved = true;

							bfsqu.push({ nrow, ncol });
							historyqu.push({ nrow,ncol });
						}
					}

					newppl = movppl / movcity;
					if (historyqu.size() >= 2) { //연합을 이룬 국가가 있을 때
						while (!historyqu.empty()) {
							map[historyqu.front().row][historyqu.front().col] = newppl;
							historyqu.pop();
						}
					}
					else if (historyqu.size() == 1) historyqu.pop(); //연합을 이룬 국가가 없을 때, historyqu를 비운다.
				}
			}
		}
		memset(visited, false, sizeof(visited)); //방문 이력 배열 초기화
	}
	cout << days << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
