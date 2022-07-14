#include <iostream>
#define endl "\n"
#define INF 2134567890
using namespace std;

int cellB[600][600];
int cellA[303][303];
int orirows, oricols, drow, dcol;

void initialize() {
	cin >> orirows >> oricols >> drow >> dcol;

	for (int i = 0; i < orirows + drow; i++) {
		for (int j = 0; j < oricols + dcol; j++) {
			cin >> cellB[i][j];
		}
	}
}

void operate() {
	//哭率 凯 贸府
	for (int col = 0; col < dcol; col++) {
		for (int row = 0; row < orirows; row++) {
			cellA[row][col] = cellB[row][col];
		}
	}

	//困率 青 贸府
	for (int col = dcol; col < oricols; col++) {
		for (int row = 0; row < drow; row++) {
			cellA[row][col] = cellB[row][col];
		}
	}

	//酒贰 青 贸府
	for (int col = dcol; col < oricols; col++) {
		for (int row = orirows; row < orirows + drow; row++) {
			cellA[row - drow][col - dcol] = cellB[row][col];
		}
	}

	//坷弗率 青 贸府
	for (int col = oricols; col < oricols + dcol; col++) {
		for (int row = drow; row < orirows + drow; row++) {
			cellA[row - drow][col - dcol] = cellB[row][col];
		}
	}

	//啊款单 贸府
	for (int col = dcol; col < oricols - dcol; col++) {
		for (int row = drow; row < orirows - drow; row++) {
			cellA[row][col] = cellB[row][col] - cellA[row - drow][col - dcol];
		}
	}

	for (int i = 0; i < orirows; i++) {
		for (int j = 0; j < oricols; j++) {
			cout << cellA[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}