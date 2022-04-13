/*
목표 : 빨간 구슬을 구멍으로 빼내기
제한사항:
1. 파란구슬이 구멍에 들어가면 안 될 것. 들어가면 실패
2. 상하좌우만 이동 가능
3. 공은 동시에 이동
4. 빨간구슬 파란구슬은 동시에 이동하며, 한 칸을 모두 차지
5. 기울이는 동작을 그만하는 것은 구슬이 안 움직일 때 까지(끝까지 민다)
*/

/*수도코드
0. 큐의 크기를 받는 변수에 크기를 준다.
1. 큐에서 현재 R, B, 이전에 왔던 방향의 위치를 꺼낸다.
2. R, B를 움직이되, 이전에 왔던 방향과 그 반대 방향으로는 가지 않는다.
3. 움직이는 과정에서 R이 똥통에 빠지면(index의 값을 기준으로 판단) flag 업데이트하고 break
4. 움직이는 과정에서 B가 똥통에 빠지만 걍 break
5. 아무 소득도 없으면 0으로 돌아가나, 만약 10번째 움직임에 도달했다면 걍 -1출력하고 끝.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>	
using namespace std;

struct pos {
	short row, col;

	bool operator !=(const pos temp) {
		if (this->row != temp.row || this->col != temp.col) return true;
		return false;
	}
};
struct info {
	pos red, blue;
};
short drow[4] = { 1,0,-1,0 };
short dcol[4] = { 0,-1,0,1 };
char map[11][11];
int rows, cols;
pos hole;
queue<info> qu;

void initialize() {
	cin >> rows >> cols; cin.get();

	info first;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = (char)cin.get();

			if (map[i][j] == '.' || map[i][j] == '#') continue;
			if (map[i][j] == 'O') {
				hole.row = i; hole.col = j;
			}
			else if (map[i][j] == 'R') {
				first.red.row = i; first.red.col = j;
				map[i][j] = '.';
			}
			else {
				first.blue.row = i; first.blue.col = j;
				map[i][j] = '.';
			}

		}
		cin.get();
	}
	qu.push(first);
}

info getToMove(pos red, pos blue, short dir) { //dir 방향으로 움직일 시 갈 수 있는 곳
	short currow, curcol, nrow, ncol;
	bool swapped = false;
	info result;

	result.red = red; result.blue = blue;

	if ((dir == 0 && blue.row > red.row) || (dir == 1 && blue.col < red.col) ||
		(dir == 2 && blue.row < red.row) || (dir == 3 && blue.col > red.col)) {
		swap(red, blue);
		swapped = true;
	} //이 결과, 항상 red가 blue 보다 가려는 방향에서 앞서 있게 된다.

	currow = red.row; curcol = red.col;

	while (1) { //앞서 있는 구슬부터 움직인다
		nrow = currow + drow[dir];
		ncol = curcol + dcol[dir];
		if (map[nrow][ncol] == '.') { //더 갈 수 있는 곳
			map[currow][curcol] = '.';
			currow = nrow;
			curcol = ncol;
			continue;
		}
		if (map[nrow][ncol] == '#') { //벽에 닿았다
			result.red.row = currow;
			result.red.col = curcol;
			break;
		}
		if (map[nrow][ncol] == 'O') { //뭔지 모를 구슬이 똥통에 빠졌다. swapped로 무슨 구슬인지 알아보자.
			result.red.row = result.red.col = 777; 
			if (swapped) goto finale; //똥통에 빠진 구슬이 파란색이다. 이 길은 아니다.
			else break; //빨간 구슬이 똥통에 빠졌다.
		}
	}

	currow = blue.row; curcol = blue.col;
	while (1) { //뒤에 있는 구슬 움직이기 시작한다.
		nrow = currow + drow[dir];
		ncol = curcol + dcol[dir];

		if (map[nrow][ncol] == '#' || (nrow == result.red.row&&ncol == result.red.col)) { //앞에 다른 구슬이 막고 있어서 더 이상 못 가거나 벽에 막혔다.
			result.blue.row = currow;
			result.blue.col = curcol;
			break;
		}
		if (map[nrow][ncol] == '.') { //더 갈 수 있는 곳
			map[currow][curcol] = '.';
			currow = nrow;
			curcol = ncol;
			continue;
		}
		if (map[nrow][ncol] == 'O') {
			result.blue.row = result.blue.col = 777; //뭔지 모를 구슬이 똥통에 빠졌다. swapped로 무슨 구슬인지 알아보자.
			break;
		}
	}

finale: if (swapped) swap(result.red, result.blue);
	return result;
}

void operate() {
	int mov = 1, sz_queue;
	info result;

	while (mov <= 10) {
		sz_queue = qu.size();
		for (int iter = 0; iter < sz_queue; iter++) {
			for (short i = 0; i < 4; i++) {
				result = getToMove(qu.front().red, qu.front().blue, i);

				if (result.blue.row == 777) { //실패의 경우
					continue;
				}
				else if (result.red.row == 777) { //정답 찾았다
					cout << mov << endl;
					return;
				}

				if (result.red != qu.front().red || result.blue != qu.front().blue) {
					qu.push({ result.red, result.blue});
				}
			}
			qu.pop();
		}
		mov++;
	}

	cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*테스트케이스
5 7
#######
#....R#
#B.####
##O####
#######

3 6
######
#.ORB#
######
ans : -1

8 8
########
#.####.#
#...#B##
#.##.R.#
######.#
##.##O.#
###.##.#
########
ans : 7

4 6
######
#R####
#B..O#
######
ans : -1

4 6
######
#R#O##
#B...#
######
ans : 4

9 9
#########
###.....#
#..#..#O#
##..R.#B#
####....#
#.....#.#
#.#.....#
##.###..#
#########
*/