#include <iostream>
#include <algorithm>
#include <cstring>
#define blank 0
using namespace std;

int map[21][21] = { 0 };
int sz_map, ans = 0;

void makeMov(int);

void initialize() {
	cin >> sz_map;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
			ans = max(ans, map[i][j]);
		}
	}
}

void moveUp(int depth) {
	bool isblank;
	int nums;

	for (int j = 0; j < sz_map; j++) { //세로 줄
		isblank = false;
		nums = 0;
		for (int i = 0; i < sz_map; i++) { //가로 줄
			if (map[i][j] == blank) isblank = true; //위에서 읽어가며, 빈 칸이 발견된 경우
			else if (map[i][j]) { 
				if (isblank) { //옮기려는 방향으로 빈 칸이 있는 경우
					for (int k = 0; k < i; k++) {
						if (map[k][j] == blank) {
							map[k][j] = map[i][j];
							map[i][j] = blank;
						}
					}
				}
				nums++;
			}
		}
		for (int i = 1; i < nums; i++) {
			if (map[i - 1][j] == map[i][j]) { //합칠 수 잇는 같은 숫자 발견
				map[i - 1][j] *= 2;
				ans = max(ans, map[i - 1][j]); //최댓값 갱신
				map[i][j] = blank;

				for (int k = i; k < nums - 1; k++) { //한 칸씩 끌어올린다
					map[k][j] = map[k + 1][j];
					map[k + 1][j] = blank;
				}
			}
		}
	}

	if (depth != 5) makeMov(depth + 1);
}

void moveDown(int depth) {
	bool isblank;
	int nums;

	for (int j = 0; j < sz_map; j++) { //세로 줄
		isblank = false;
		nums = 0;
		for (int i = sz_map - 1; i >= 0; i--) { //가로 줄
			if (map[i][j] == blank) isblank = true; //아래에서 읽어가며, 빈 칸이 발견된 경우
			else if (map[i][j]) {
				if (isblank) { //옮기려는 방향으로 빈 칸이 있는 경우
					for (int k = sz_map - 1; k > i; k--) {
						if (map[k][j] == blank) {
							map[k][j] = map[i][j];
							map[i][j] = blank;
						}
					}
				}
				nums++;
			}
		}
		for (int i = sz_map - 2; i > sz_map - nums - 1; i--) {
			if (map[i + 1][j] == map[i][j]) { //합칠 수 잇는 같은 숫자 발견
				map[i + 1][j] *= 2;
				ans = max(ans, map[i + 1][j]); //최댓값 갱신
				map[i][j] = blank;

				for (int k = i; k > sz_map - nums; k--) { //한 칸씩 끌어올린다
					map[k][j] = map[k - 1][j];
					map[k - 1][j] = blank;
				}
			}
		}
	}

	if (depth != 5) makeMov(depth + 1);
}

void moveLeft(int depth) {
	bool isblank;
	int nums;

	for (int i = 0; i < sz_map; i++) { //가로 줄
		isblank = false;
		nums = 0;
		for (int j = 0; j < sz_map; j++) { //세로 줄
			if (map[i][j] == blank) isblank = true; //왼쪽에서 읽어가며, 빈 칸이 발견된 경우
			else if (map[i][j]) {
				if (isblank) { //옮기려는 방향으로 빈 칸이 있는 경우
					for (int k = 0; k < j; k++) {
						if (map[i][k] == blank) {
							map[i][k] = map[i][j];
							map[i][j] = blank;
						}
					}
				}
				nums++;
			}
		}
		for (int j = 1; j < nums; j++) {
			if (map[i][j - 1] == map[i][j]) { //합칠 수 잇는 같은 숫자 발견
				map[i][j - 1] *= 2;
				ans = max(ans, map[i][j - 1]); //최댓값 갱신
				map[i][j] = blank;

				for (int k = j; k < nums - 1; k++) { //한 칸씩 끌어올린다
					map[i][k] = map[i][k + 1];
					map[i][k + 1] = blank;
				}
			}
		}
	}

	if (depth != 5) makeMov(depth + 1);
}
void moveRight(int depth) {
	bool isblank;
	int nums;

	for (int i = 0; i < sz_map; i++) { //가로 줄
		isblank = false;
		nums = 0;
		for (int j = sz_map - 1; j >= 0; j--) { //세로 줄
			if (map[i][j] == blank) isblank = true; //오른쪽에서 읽어가며, 빈 칸이 발견된 경우
			else if (map[i][j]) {
				if (isblank) { //옮기려는 방향으로 빈 칸이 있는 경우
					for (int k = sz_map - 1; k > j; k--) {
						if (map[i][k] == blank) {
							map[i][k] = map[i][j];
							map[i][j] = blank;
						}
					}
				}
				nums++;
			}
		}
		for (int j = sz_map - 2; j > sz_map - nums - 1; j--) {
			if (map[i][j + 1] == map[i][j]) { //합칠 수 잇는 같은 숫자 발견
				map[i][j + 1] *= 2;
				ans = max(ans, map[i][j + 1]); //최댓값 갱신
				map[i][j] = blank;

				for (int k = j; k > sz_map - nums; k--) { //한 칸씩 끌어올린다
					map[i][k] = map[i][k - 1];
					map[i][k - 1] = blank;
				}
			}
		}
	}

	if (depth != 5) makeMov(depth + 1);
}

void makeMov(int depth) {
	//현 상태를 copy 해 놓는다
	int duplicate[21][21];
	memcpy(duplicate, map, sizeof(map));

	//위로 옮겨서 합치는 작업 후 원상복귀
	moveUp(depth);
	memcpy(map, duplicate, sizeof(map));

	//아래로 옮겨서 합치는 작업 후 원상복귀
	moveDown(depth);
	memcpy(map, duplicate, sizeof(map));

	//오른쪽으로 옮겨서 합치는 작업 후 원상복귀
	moveRight(depth);
	memcpy(map, duplicate, sizeof(map));

	//왼쪽으로 옮겨서 합치는 작업 후 원상복귀
	moveLeft(depth);
	memcpy(map, duplicate, sizeof(map));
}

void operate() {
	makeMov(1);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
4
2 0 4 2
2 2 4 2
4 2 2 4
4 8 0 0

4
2 0 4 2
2 2 4 2
2 2 2 4
2 8 0 0

4
2 0 2 4
2 2 4 2
2 2 2 2
2 8 0 0
*/