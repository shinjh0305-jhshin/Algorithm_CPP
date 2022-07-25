#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 100
using namespace std;

struct info {
	pair<int, int> pos;
	int dir;
};

int drow[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dcol[9] = { 0,0,-1,-1,-1,0,1,1,1 };

info fish[18];
int map[6][6]; //0,0시작, shark = INF;
info curShark;
int sharkEaten = 0; //sum of index of the fish that shark ate

void initialize() {
	int idx, dir;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> idx >> dir;
			fish[idx].pos = { i, j };
			fish[idx].dir = dir;

			map[i][j] = idx;
		}
	}

	int firstFish = map[0][0]; //0,0의 물고기는 먹고 시작한다.
	sharkEaten += firstFish;

	curShark.pos = { 0,0 };
	curShark.dir = fish[firstFish].dir;

	fish[firstFish].pos = { INF, INF };
	fish[firstFish].dir = INF;
	map[0][0] = INF;
}

int moveFish() {
	int nrow, ncol, targetFish;
	for (int i = 1; i <= 16; i++) {
		if (fish[i].dir == INF) continue; //이미 잡아먹힌 물고기
		
		for (int j = 0; j < 8; j++) {
			nrow = fish[i].pos.first + drow[fish[i].dir];
			ncol = fish[i].pos.second + dcol[fish[i].dir];

			if (nrow < 0 || nrow >= 4 || ncol < 0 || ncol >= 4 || curShark.pos == make_pair(nrow, ncol)) {
				fish[i].dir = fish[i].dir == 8 ? 1 : fish[i].dir + 1;
				continue;
			}

			targetFish = map[nrow][ncol]; //빈 칸일 경우 INF가 들어간다.
			swap(map[fish[i].pos.first][fish[i].pos.second], map[nrow][ncol]);

			if (targetFish != INF) {
				swap(fish[i].pos, fish[targetFish].pos);
			}
			else {
				fish[i].pos = { nrow, ncol };
			}
			break;
		}
	}

	info tempfish[18];
	int tempmap[6][6];
	info tempshark;

	memcpy(tempfish, fish, sizeof(fish));
	memcpy(tempmap, map, sizeof(map));
	tempshark = curShark;

	int fishToEat, localMax = 0;
	for (int i = 1; i <= 4; i++) {
		nrow = tempshark.pos.first + drow[tempshark.dir] * i;
		ncol = tempshark.pos.second + dcol[tempshark.dir] * i;

		if (nrow < 0 || nrow >= 4 || ncol < 0 || ncol >= 4 || map[nrow][ncol] == INF) continue;

		fishToEat = map[nrow][ncol];

		curShark.dir = fish[fishToEat].dir; //상어의 현재 위치와 방향 설정
		curShark.pos = { nrow, ncol };

		fish[fishToEat].pos = { INF, INF }; //상어가 먹은 칸의 물고기를 없애고, 물고기의 정보도 같이 없앤다.
		fish[fishToEat].dir = INF;
		map[nrow][ncol] = INF;

		localMax = max(localMax, fishToEat + moveFish());

		memcpy(fish, tempfish, sizeof(fish));
		memcpy(map, tempmap, sizeof(map));
	}

	return localMax;
}



void operate() {
	cout << sharkEaten + moveFish() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
