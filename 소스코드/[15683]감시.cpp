#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/****  CH1 : →  CH2 : ↔  CH3 : ↑→  CH4 : ←↑→  CH5 : ←↑↓→  ****/
enum type { Blank, CH1, CH2, CH3, CH4, CH5, Wall, CCTV };
struct info { int row; int col; int type; };
int map[8][8];
int rows, cols, num_cctv = 0, result = 123456790;
vector<info> cctv; //cctv가 있는 위치 및 종류를 저장한다.

void initialize() {
	cin >> rows >> cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> map[i][j];
			if (map[i][j] != Wall && map[i][j] != Blank) {
				cctv.push_back({ i, j, map[i][j] });
				num_cctv++;
			}
		}
	}
}

void colorRight(int row, int col) {
	while (col < cols) {
		if (map[row][col] == Blank) map[row][col] = CCTV;
		else if (map[row][col] == Wall) return;
		col++;
	}
}

void colorLeft(int row, int col) {
	while (col >= 0) {
		if (map[row][col] == Blank) map[row][col] = CCTV;
		else if (map[row][col] == Wall) return;
		col--;
	}
}

void colorUp(int row, int col) {
	while (row >= 0) {
		if (map[row][col] == Blank) map[row][col] = CCTV;
		else if (map[row][col] == Wall) return;
		row--;
	}
}

void colorDown(int row, int col) {
	while (row < rows) {
		if (map[row][col] == Blank) map[row][col] = CCTV;
		else if (map[row][col] == Wall) return;
		row++;
	}
}

void installCCTV(int cctvIdx) {
	if (cctvIdx == num_cctv) {
		int num_blank = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (map[i][j] == Blank) num_blank++;
			}
		}
		result = min(result, num_blank);
		return;
	}

	int mapTemp[8][8];
	memcpy(mapTemp, map, sizeof(map)); //기존의 원본 map을 대피시킨다.

	int typeCCTV = cctv[cctvIdx].type;
	int currow = cctv[cctvIdx].row, curcol = cctv[cctvIdx].col;

	switch (typeCCTV) { //현재 CCTV의 가능한 각 방향에 대해, CCTV 감시 구역을 색칠하고, 다음 CCTV를 재귀적으로 호출한 뒤, 다시 map을 원상복귀 시킨다. 
	case CH1:
		for (int i = 0; i < 4; i++) {
			if (i == 0) colorRight(currow, curcol);
			else if (i == 1) colorLeft(currow, curcol);
			else if (i == 2) colorUp(currow, curcol);
			else colorDown(currow, curcol);

			installCCTV(cctvIdx + 1); 
			memcpy(map, mapTemp, sizeof(map));
		}
		break;
	case CH2:
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				colorRight(currow, curcol); colorLeft(currow, curcol);
			}
			else {
				colorUp(currow, curcol); colorDown(currow, curcol);
			}
			installCCTV(cctvIdx + 1);
			memcpy(map, mapTemp, sizeof(map));
		}
		break;
	case CH3:
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				colorRight(currow, curcol); colorUp(currow, curcol);
			}
			else if (i == 1) {
				colorRight(currow, curcol); colorDown(currow, curcol);
			}
			else if (i == 2) {
				colorDown(currow, curcol); colorLeft(currow, curcol);
			}
			else {
				colorLeft(currow, curcol); colorUp(currow, curcol);
			}
			installCCTV(cctvIdx + 1);
			memcpy(map, mapTemp, sizeof(map));
		}
		break;
	case CH4:
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				colorLeft(currow, curcol); colorRight(currow, curcol); colorUp(currow, curcol);
			}
			else if (i == 1) {
				colorRight(currow, curcol); colorUp(currow, curcol); colorDown(currow, curcol);
			}
			else if (i == 2) {
				colorRight(currow, curcol); colorDown(currow, curcol); colorLeft(currow, curcol);
			}
			else {
				colorDown(currow, curcol); colorLeft(currow, curcol); colorUp(currow, curcol);
			}
			installCCTV(cctvIdx + 1);
			memcpy(map, mapTemp, sizeof(map));
		}
		break;
	case CH5:
		colorDown(currow, curcol); colorLeft(currow, curcol); colorUp(currow, curcol); colorRight(currow, curcol);
		installCCTV(cctvIdx + 1);
		memcpy(map, mapTemp, sizeof(map));
		break;
	}
}

void operate() {
	installCCTV(0);
	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}