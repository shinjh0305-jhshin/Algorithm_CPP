#include <iostream>
#define ll long long
using namespace std;

ll map[102][102];
ll routes[102][102];
int sz_map;

void initialize() {
	cin >> sz_map;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
		}
	}

	routes[0][0] = 1;
}

void operate() {
	int nrow, ncol;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			if (map[i][j] == 0 || routes[i][j] == 0) continue; //종착점
			for (int k = 0; k < 2; k++) {
				if (k == 0) { //가로이동
					nrow = i; ncol = j + map[i][j];
				}
				else { //세로이동
					nrow = i + map[i][j]; ncol = j;
				}
				if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map) continue;
				routes[nrow][ncol] += routes[i][j];
			}
		}
	}

	cout << routes[sz_map - 1][sz_map - 1] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}