#include <iostream>
#include <vector>
#include <cmath>
#define ROTATE(x, y) (((x) - (y) + 7) % 8 + 1)
using namespace std;

int cog[5][9]; //톱니바퀴의 상태
int incident[5][2]; //톱니바퀴가 왼쪽 오른쪽에 맞닿아있는 톱니의 index
enum a { goleft = -1, goright = 1 };
enum b { cogleft = 0, cogright };

void initialize() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			cog[i][j] = cin.get() - '0';
		}
		incident[i][cogleft] = 7;
		incident[i][cogright] = 3;
		cin.get();
	}
}

void get_ans() {
	int ans = 0, idx;
	for (int i = 1; i <= 4; i++) {
		idx = incident[i][cogleft];
		idx = (idx + 1) % 8 + 1;

		if (cog[i][idx] == 1) {
			ans += (int)pow(2, i - 1);
		}
	}
	cout << ans << endl;
}

//cogIdx : 톱니바퀴 index, dir : 시계방향(1)/반시계방향(-1), propagate : 오른쪽탐색(1)/왼쪽탐색(-1)/초기(0)
void turn(int cogIdx, int dir, int propagate) {
	int curleftidx = incident[cogIdx][cogleft], currightidx = incident[cogIdx][cogright];
	int nleftidx = incident[cogIdx + 1][cogleft], nrightidx = incident[cogIdx - 1][cogright];
	if (propagate <= 0 && cogIdx != 1 && cog[cogIdx][curleftidx] != cog[cogIdx - 1][nrightidx])
		turn(cogIdx - 1, -dir, goleft);
	if (propagate >= 0 && cogIdx != 4 && cog[cogIdx][currightidx] != cog[cogIdx + 1][nleftidx])
		turn(cogIdx + 1, -dir, goright);
	
	incident[cogIdx][cogleft] = ROTATE(curleftidx, dir);
	incident[cogIdx][cogright] = ROTATE(currightidx, dir);
}

void operate() {
	int ops, cogIdx, dir;
	cin >> ops;
	
	for (int i = 0; i < ops; i++) {
		cin >> cogIdx >> dir;
		turn(cogIdx, dir, 0);
	}
	get_ans();

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	initialize();
	operate();

	return 0;
}