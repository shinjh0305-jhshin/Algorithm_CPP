#include <iostream>
#include <algorithm>
#define endl "\n"
#define INF 1234567890
using namespace std;

/***********
cols : 세로선의 개수
rows : 이미 설치 된 가로선의 개수
avail : 가로선을 놓을 수 있는 후보지의 개수
************/
int rows, cols, avail;
int answer = INF;
bool map[32][12] = { false };

void initialize() {
	cin >> cols >> rows >> avail;

	int a, b;
	for (int i = 0; i < rows; i++) {
		cin >> a >> b;
		map[a][b] = true;
	}
}

bool play_game() {
	int mov;
	for (int i = 1; i <= cols; i++) {
		mov = i;
		for (int j = 1; j <= avail; j++) {
			if (map[j][mov - 1]) mov--;
			else if (map[j][mov]) mov++;
		}
		if (mov == i) continue; //세로 방향으로 그대로 떨어졌다
		else return false; //다른 곳으로 갔기 때문에 더 진행할 것 없이 바로 false를 리턴한다.
	}
	return true;
}

void make_col(int row, int col, int depth) {
	// 게임 결과 성공한 경우 진행할 필요가 없다.
	if (play_game()) {
		answer = min(answer, depth);
		return;
	}
	if (depth == 3) return; //더 이상 못 들어가는 깊이다.

	for (; row <= avail; row++) {
		for (; col < cols; col++) {
			if (!map[row][col - 1] && !map[row][col + 1] && !map[row][col]) {
				map[row][col] = true;
				if (depth < answer) make_col(row, col + 1, depth + 1); //기존에 구한 최소 depth보다 크거나 같을 경우 진행할 필요가 없다.
				map[row][col] = false;
			}
		}
		col = 1;
	}
}

void operate() {
	make_col(1, 1, 0);
	if (answer == INF) cout << -1 << endl;
	else cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
3 5 6
1 2
2 1
3 2
4 1
5 2
ans : 1
*/