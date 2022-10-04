#include <iostream>
#include <deque>
#include <vector>
#define STUDENT 'S'
#define TEACHER 'T'
#define OBSTACLE 'X'
using namespace std;

int sz_map, sz_obs;
char map[10][10];
vector<pair<int, int>> obs, ts;
deque<pair<int, int>> obs_chosen;

int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> sz_map;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
			if (map[i][j] == OBSTACLE) {
				obs.push_back({ i, j });
			}
			else if (map[i][j] == TEACHER) {
				ts.push_back({ i, j });
			}
		}
	}

	sz_obs = obs.size();
}


bool seeStudents() {
	int currow, curcol, nrow, ncol;
	bool isObstacle[10][10] = { false };

	for (const auto& it : obs_chosen) {
		isObstacle[it.first][it.second] = true;
	}

	for (const auto& t : ts) {
		currow = t.first; curcol = t.second;

		for (int k = 0; k < 4; k++) {
			for (int i = 1;; i++) {
				nrow = currow + drow[k] * i; 
				ncol = curcol + dcol[k] * i;

				if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map || isObstacle[nrow][ncol]) break;

				if (map[nrow][ncol] == STUDENT) return false;
			}
		}
	}

	return true;
}

bool chooseobs(int idx = 0, int chosen = 0) {
	if (sz_obs - idx < 3 - chosen) return false;
	if (chosen == 3) {
		return seeStudents();
	}

	obs_chosen.push_back(obs[idx]);
	if (chooseobs(idx + 1, chosen + 1)) return true;
	obs_chosen.pop_back();

	if (chooseobs(idx + 1, chosen)) return true;

	return false;
}

void operate() {
	if (chooseobs()) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}