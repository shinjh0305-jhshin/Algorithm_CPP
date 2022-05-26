#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> dragon;
short isDragon[103][103] = { 0 };
pair<int, int> mod[4] = { {0,1},{-1,0},{0,-1},{1,0} };


void makeDragon() {
	int col, row, dir, gen;

	cin >> col >> row >> dir >> gen;

	dragon.clear();
	dragon.push_back({ row, col });
	dragon.push_back({ row + mod[dir].first, col + mod[dir].second });

	for (int iter = 0; iter < gen; iter++) {
		for (int i = dragon.size() - 1; i >= 1; i--) {
			if (dragon[i - 1].second == dragon[i].second + 1) { //direction 0
				dragon.push_back({ dragon.back().first + 1, dragon.back().second }); //to direction 3
			}
			else if (dragon[i - 1].first == dragon[i].first - 1) { //direction 1
				dragon.push_back({ dragon.back().first, dragon.back().second + 1}); //to direction 0
			}
			else if (dragon[i - 1].second == dragon[i].second - 1) { //direction 2
				dragon.push_back({ dragon.back().first - 1, dragon.back().second}); //to direction 1
			}
			else { //to direction 3
				dragon.push_back({ dragon.back().first, dragon.back().second - 1 }); //to direction 2
			}
		}
	}
}

void countSquare() {
	int cnt = 0;

	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (isDragon[i][j]) {
				if (isDragon[i + 1][j] && isDragon[i][j + 1] && isDragon[i + 1][j + 1]) cnt++;
			}
		}
	}

	cout << cnt << endl;
}

void operate() {
	int sz_dragon;
	cin >> sz_dragon;

	for (int i = 0; i < sz_dragon; i++) {
		makeDragon();
		for (auto it : dragon) {
			isDragon[it.first][it.second] = 1;
		}
	}

	countSquare();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}