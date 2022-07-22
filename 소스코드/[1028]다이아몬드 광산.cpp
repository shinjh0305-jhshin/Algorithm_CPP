#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int rows, cols;
int map[755][755], ru[755][755], rd[755][755]; //ru : ↗ rd : ↘

int ans = 0;

void initialize() {
	cin >> rows >> cols;

	string st;
	for (int i = 0; i < rows; i++) {
		cin >> st;
		for (int j = 0; j < cols; j++) {
			map[i][j] = st[j] - '0';
			if (map[i][j] == 1) ans = 1; //1이 하나라도 있으면 크기는 1에서 시작
		}
	}
} 

void makeDP() {
	for (int row = 1; row < rows; row++) {
		for (int col = 0; col < cols - 1; col++) {
			if (!map[row][col] || !map[row - 1][col + 1]) continue;
			ru[row][col] = ru[row - 1][col + 1] + 1; 
		}
	}
	for (int row = rows - 2; row >= 0; row--) {
		for (int col = 0; col < cols - 1; col++) {
			if (!map[row][col] || !map[row + 1][col + 1]) continue;
			rd[row][col] = rd[row + 1][col + 1] + 1;
		}
	}
}

void calcMax() {
	int leftMax;
	for (int row = 1; row < rows - 1; row++) {
		for (int col = 0; col < cols - 2; col++) {
			leftMax = min(ru[row][col], rd[row][col]); //↗, ↘ 중에서 공통으로 최대로 갈 수 있는 값 구한다,
			for (int k = leftMax; k >= 1; k--) {
				if (rd[row - k][col + k] >= k && ru[row + k][col + k] >= k) {
					ans = max(ans, k + 1);
					break;
				}
			}
		}
	}

	cout << ans << endl;
}

void operate() {
	makeDP();
	calcMax();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}