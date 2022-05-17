#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

struct info {
	int row, col, key = 0;
};
queue<info> qu;
char map[51][51];
bool visited[1 << 6][51][51] = { false };
int rows, cols, startRow, startCol;
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void operate() {
	qu.push({ startRow, startCol, 0 });

	char target;
	int currow, curcol, curkey, nrow, ncol, nkey, sz_queue;
	int mov = 1; //총 이동 횟수
	while (!qu.empty()) {
		sz_queue = qu.size();
		
		for (int iter = 0; iter < sz_queue; iter++) {
			currow = qu.front().row; curcol = qu.front().col; curkey = qu.front().key;
			qu.pop();

			for (int i = 0; i < 4; i++) {
				nrow = currow + drow[i]; ncol = curcol + dcol[i];
				if (nrow<0 || nrow>=rows || ncol<0 || ncol>=cols || map[nrow][ncol] == '#' || visited[curkey][nrow][ncol]) continue;
				if (map[nrow][ncol] == '1') { //출구 발견!
					cout << mov << endl;
					return;
				}

				target = map[nrow][ncol];
				if (target >= 'a' && target <= 'f') { //열쇠!
					nkey = curkey | (1 << (target - 'a'));
					if (!visited[nkey][nrow][ncol]) {
						visited[nkey][nrow][ncol] = true;
						qu.push({ nrow, ncol, nkey });
					} 
				}
				else if (target >= 'A' && target <= 'F') { //문
					if (curkey & (1 << (target - 'A'))) {
						visited[curkey][nrow][ncol] = true;
						qu.push({ nrow, ncol, curkey });
					}
				}
				else { //아무것도 없는 곳
					visited[curkey][nrow][ncol] = true;
					qu.push({ nrow, ncol, curkey });
				}
			}
		}

		mov++;
	}
	cout << -1 << endl;
}

void initialize() {
	cin >> rows >> cols; cin.get();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = cin.get();
			if (map[i][j] == '0') {
				startRow = i; startCol = j;
			}
		}
		cin.get();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}