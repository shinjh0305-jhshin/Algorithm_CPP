#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

enum a { RED, GREEN, BLUE };
int dp[3][1005][3]; //i : 첫째 집의 색상, j : 각 집의 index, k : 각 집의 색상
int rawdata[1005][3];
int houses;

void initialize() {
	cin >> houses;
	for (int i = 1; i <= houses; i++) {
		cin >> rawdata[i][RED] >> rawdata[i][GREEN] >> rawdata[i][BLUE];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) dp[i][1][j] = INF;
			else dp[i][1][j] = rawdata[1][j];
		}
		
	}
}

void operate() {
	for (int houseIdx = 2; houseIdx <= houses; houseIdx++) {
		for (int firstColor = RED; firstColor <= BLUE; firstColor++) {
			dp[firstColor][houseIdx][RED] = min(dp[firstColor][houseIdx - 1][GREEN], dp[firstColor][houseIdx - 1][BLUE]) + rawdata[houseIdx][RED];
			dp[firstColor][houseIdx][GREEN] = min(dp[firstColor][houseIdx - 1][RED], dp[firstColor][houseIdx - 1][BLUE]) + rawdata[houseIdx][GREEN];
			dp[firstColor][houseIdx][BLUE] = min(dp[firstColor][houseIdx - 1][RED], dp[firstColor][houseIdx - 1][GREEN]) + rawdata[houseIdx][BLUE];
		}
	}

	int redMin = min(dp[RED][houses][GREEN], dp[RED][houses][BLUE]);
	int greenMin = min(dp[GREEN][houses][RED], dp[GREEN][houses][BLUE]);
	int blueMin = min(dp[BLUE][houses][RED], dp[BLUE][houses][GREEN]);

	cout << min(redMin, min(greenMin, blueMin)) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}