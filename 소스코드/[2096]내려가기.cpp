#include <iostream>
#include <algorithm>
using namespace std;

short rawdata[100002][3];
int dpMax[2][3], dpMin[2][3];
int prevRow = 0, curRow = 1, sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> rawdata[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		dpMax[0][i] = dpMin[0][i] = rawdata[0][i];
	}
}

void operate() {
	int temp;
	for (int i = 1; i < sz_rawdata; i++) {
		//dpMax 구하기
		temp = max(dpMax[prevRow][0], dpMax[prevRow][1]); //첫 번째, 두 번째 칸 구할 때 중복되는 연산
		dpMax[curRow][0] = temp + rawdata[i][0];
		dpMax[curRow][1] = max(temp, dpMax[prevRow][2]) + rawdata[i][1];
		dpMax[curRow][2] = max(dpMax[prevRow][1], dpMax[prevRow][2]) + rawdata[i][2];

		//dpMin 구하기
		temp = min(dpMin[prevRow][0], dpMin[prevRow][1]); //첫 번째, 두 번째 칸 구할 때 중복되는 연산
		dpMin[curRow][0] = temp + rawdata[i][0];
		dpMin[curRow][1] = min(temp, dpMin[prevRow][2]) + rawdata[i][1];
		dpMin[curRow][2] = min(dpMin[prevRow][1], dpMin[prevRow][2]) + rawdata[i][2];

		swap(curRow, prevRow);
	}

	//최종 max 구하기
	temp = 0;
	for (int i = 0; i < 3; i++) {
		temp = max(temp, dpMax[prevRow][i]);
	}
	cout << temp << ' ';

	temp = 1234567890;
	for (int i = 0; i < 3; i++) {
		temp = min(temp, dpMin[prevRow][i]);
	}
	cout << temp << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}