#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cube[25];
int cubeTemp[25];

int moveSet[6][8] = {
	{1,3,5,7,9,11,24,22},
	{2,4,6,8,10,12,23,21},
	{22,21,18,17,6,5,14,13},
	{24,23,20,19,8,7,16,15},
	{1,2,18,20,12,11,15,13},
	{3,4,17,19,10,9,16,14}
};

bool checkCube() {
	int temp;
	for (int i = 1; i <= 21; i += 4) {
		temp = cubeTemp[i];
		for (int j = i + 1; j <= i + 3; j++) {
			if (cubeTemp[j] != temp) return false;
		}
	}

	return true;
}

void operate() {
	for (int i = 0; i < 6; i++) {
		//1. 순방향 회전
		memcpy(cubeTemp, cube, sizeof(cube));
		for (int j = 0; j < 8; j++) {
			cubeTemp[moveSet[i][(j + 2) % 8]] = cube[moveSet[i][j]];
		}

		if (checkCube()) {
			cout << 1 << endl;
			return;
		}

		//2. 역방향 회전
		memcpy(cubeTemp, cube, sizeof(cube));
		for (int j = 0; j < 8; j++) {
			cubeTemp[moveSet[i][(j + 6) % 8]] = cube[moveSet[i][j]];
		}

		if (checkCube()) {
			cout << 1 << endl;
			return;
		}
	}

	cout << 0 << endl;
}

void initialize() {
	for (int i = 1; i <= 24; i++) {
		cin >> cube[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}