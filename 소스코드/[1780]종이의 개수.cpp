#include <iostream>
#define endl "\n"
using namespace std;

int sz_map;
short map[2190][2190];
int result[3] = { 0 };

void initialize() {
	cin >> sz_map;
	for (int i = 1; i <= sz_map; i++) {
		for (int j = 1; j <= sz_map; j++) {
			cin >> map[i][j];
		}
	}
}

bool checkSame(int row, int col, int size) {
	short target = map[row][col];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (target != map[row + i][col + j]) return false;
		}
	}

	return true;
}

void makeChoice(int row, int col, int size) {
	int addsize = size / 3;

	if (!checkSame(row, col, size)) { //수가 다를 경우
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				makeChoice(row + i * addsize, col + j * addsize, addsize);
			}
		}
	}
	else { //수가 동일할 경우
		result[map[row][col] + 1]++;
	}
}

void operate() {
	makeChoice(1, 1, sz_map);

	for (const auto it : result) {
		cout << it << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}