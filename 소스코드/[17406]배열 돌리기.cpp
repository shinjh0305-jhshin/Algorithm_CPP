#include <iostream>
#include <cstring>
#include <algorithm>
#define endl "\n"
using namespace std;

struct info {
	int row, col, size;
};

int rawdata[52][52];
int rows, cols, opers, ans = 1234567890;
info rota[6];
bool used[6] = { false };

void initialize() {
	cin >> rows >> cols >> opers;
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			cin >> rawdata[i][j];
		}
	}

	for (int i = 0; i < opers; i++) {
		cin >> rota[i].row >> rota[i].col >> rota[i].size;
	}
}

void make_rotation(int idx) {
	int row = rota[idx].row, col = rota[idx].col, size = rota[idx].size, temp;
	int up, down, left, right; //각 회전에서 상하좌우 index의 bound
	for (int i = 1; i <= size; i++) {
		up = row - i; down = row + i; left = col - i; right = col + i;
		temp = rawdata[up][left]; //임시 저장!

		for (int j = up; j < down; j++) rawdata[j][left] = rawdata[j + 1][left];
		for (int j = left; j < right; j++) rawdata[down][j] = rawdata[down][j + 1];
		for (int j = down; j > up; j--) rawdata[j][right] = rawdata[j - 1][right];
		for (int j = right; j > left + 1; j--) rawdata[up][j] = rawdata[up][j - 1];

		rawdata[up][left + 1] = temp;
	}
}

void rotate(int depth) {
	if (depth == opers) { //모든 가능한 회전을 시도했을 경우
		int minTemp = 1234567890, sum;
		for (int i = 1; i <= rows; i++) {
			sum = 0;
			for (int j = 1; j <= cols; j++) {
				sum += rawdata[i][j];
			}
			minTemp = min(minTemp, sum);
		}
		ans = min(ans, minTemp);
		return;
	}

	int rawdatacpy[52][52];
	for (int i = 0; i < opers; i++) {
		if (!used[i]) {
			memcpy(rawdatacpy, rawdata, sizeof(rawdata)); //회전!
			make_rotation(i);
			used[i] = true;

			rotate(depth + 1);

			used[i] = false; //원상복구
			memcpy(rawdata, rawdatacpy, sizeof(rawdata));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	rotate(0);

	cout << ans << endl;

	return 0;
}