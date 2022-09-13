#include <iostream>
#include <cstring>
#include <vector>
#define endl "\n"
#define ll long long
#define space " "
using namespace std;

int result[6][6], curMatrix[6][6];
int sz_matrix;
ll times;

void squareMatrix() { //curMatrix를 제곱한다.
	int temp[6][6] = { 0 };
	
	for (int row = 0; row < sz_matrix; row++) {
		for (int col = 0; col < sz_matrix; col++) {
			for (int k = 0; k < sz_matrix; k++) {
				temp[row][col] += curMatrix[row][k] * curMatrix[k][col];
			}
			temp[row][col] %= 1000;
		}
	}

	memcpy(curMatrix, temp, sizeof(temp));
}

void addResult() {
	int temp[6][6] = { 0 };

	for (int row = 0; row < sz_matrix; row++) {
		for (int col = 0; col < sz_matrix; col++) {
			for (int k = 0; k < sz_matrix; k++) {
				temp[row][col] += result[row][k] * curMatrix[k][col];
			}
			temp[row][col] %= 1000;
		}
	}

	memcpy(result, temp, sizeof(temp));
}

void operate() {
	int target;

	while (1) {
		target = times % 2;

		if (target == 1) addResult();
		if (times == 1) break;

		squareMatrix();

		times /= 2;
	}

	for (int i = 0; i < sz_matrix; i++) {
		for (int j = 0; j < sz_matrix; j++) {
			cout << result[i][j] << space;
		}
		cout << endl;
	}
}

void initialize() {
	cin >> sz_matrix >> times;

	for (int i = 0; i < sz_matrix; i++) {
		for (int j = 0; j < sz_matrix; j++) {
			cin >> curMatrix[i][j];
		}
	}

	for (int i = 0; i < sz_matrix; i++) { //단위행렬로 만든다.
		result[i][i] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}