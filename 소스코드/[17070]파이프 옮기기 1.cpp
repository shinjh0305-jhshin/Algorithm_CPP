#include <iostream>
#include <vector>
using namespace std;

enum direction { horiz, vert, diag }; //가로 세로 대각선
enum status { avail = -1, wall = 1234567890 };
vector<int> movType[3] = { {0,2}, {1,2}, {0,1,2} };//가로 세로 대각선 각각 움직일 수 있는 경우의 수
int map[3][17][17];
int sz_map;
//파이프의 index는 오른쪽 끝을 기준으로 한다

void initialize() {
	cin >> sz_map;
	
	int temp;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> temp;
			if (temp == 0) map[horiz][i][j] = map[vert][i][j] = map[diag][i][j] = avail;
			else map[horiz][i][j] = map[vert][i][j] = map[diag][i][j] = wall;
			
		}
	}
}

bool horizPossible(int row, int col) {
	if (col + 1 < sz_map && map[horiz][row][col + 1] != wall) return true;
	return false;
}

bool vertPossible(int row, int col) {
	if (row + 1 < sz_map && map[vert][row + 1][col] != wall) return true;
	return false;
}

bool diagPossible(int row, int col) {
	if (col + 1 < sz_map && row + 1 < sz_map &&
		map[vert][row][col + 1] != wall && map[vert][row + 1][col] != wall && map[vert][row + 1][col + 1] != wall) return true;
	return false;
}

int DFS(int row, int col, int dir) { //row, col은 파이프의 오른쪽 끝을 따라간다
	if (row == sz_map - 1 && col == sz_map - 1) return 1; //종료 지점

	map[dir][row][col] = 0; //초기화
	for (int i = 0; i < movType[dir].size(); i++) {
		if (movType[dir][i] == horiz && horizPossible(row, col)) { //case horiz
			if (map[horiz][row][col + 1] == avail) { //미탐색 지역
				map[dir][row][col] += DFS(row, col + 1, horiz); //현재 dir에 다음 칸의 horiz 모양일 때의 결과값을 더한다
			}
			else map[dir][row][col] += map[horiz][row][col + 1]; //이미 탐색한 경우 그 결과를 가져다 쓴다
		}

		else if (movType[dir][i] == vert && vertPossible(row, col)) { //case vert
			if (map[vert][row + 1][col] == avail) { //미탐색 지역
				map[dir][row][col] += DFS(row + 1, col, vert); //현재 dir에 다음 칸의 vert 모양일 때의 결과값을 더한다
			}
			else map[dir][row][col] += map[vert][row + 1][col]; //이미 탐색한 경우 그 결과를 가져다 쓴다
		}

		else if (horizPossible(row, col) && vertPossible(row, col) && diagPossible(row, col)) { //case diagonal
			if (map[diag][row + 1][col + 1] == avail) { //미탐색 지역
				map[dir][row][col] += DFS(row + 1, col + 1, diag); //현재 dir에 다음 칸의 vert 모양일 때의 결과값을 더한다
			}
			else map[dir][row][col] += map[diag][row + 1][col + 1]; //이미 탐색한 경우 그 결과를 가져다 쓴다
		}
	}

	return map[dir][row][col];
}

void operate() {
	cout << DFS(0, 1, horiz) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}