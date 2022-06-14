#include <iostream>
#define endl "\n"
using namespace std;

int map[102][102];
int sz_map;

void initialize() {
	cin >> sz_map;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
		}
	}
}

void operate() {
	for (int k = 0; k < sz_map; k++) {
		for (int i = 0; i < sz_map; i++) {
			for (int j = 0; j < sz_map; j++) {
				if (map[i][k] && map[k][j]) map[i][j] = 1;
			}
		}
	}
	for (int row = 0; row < sz_map; row++) {
		for (int col = 0; col < sz_map; col++) {
			cout << map[row][col] << ' ';
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