#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

enum teamName { _start, _link };
int map[21][21];
vector<int> team[2];
int sz_map, result = 2134567890;

void initialize() {
	cin >> sz_map;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		team[i].reserve(sz_map / 2 + 1);
	}
}

void make_score(int curNode) {
	if (curNode == sz_map) {
		int score[2] = { 0 }, sz_team;
		for (int i = 0; i < 2; i++) {
			sz_team = sz_map / 2;

			for (int j = 0; j < sz_team - 1; j++) {
				for (int k = j + 1; k < sz_team; k++) {
					score[i] += (map[team[i][j]][team[i][k]] + map[team[i][k]][team[i][j]]);
				}
			}
		}

		result = min(result, abs(score[_start] - score[_link]));
	}
	else {
		int start_size = team[_start].size(), link_size = team[_link].size();

		//1. curNode가 start 팀에 들어가는 경우
		/////////////////////////////////////
		team[_start].push_back(curNode);
		if (team[_start].size() == sz_map / 2) { //start 팀이 꽉 찬 경우
			for (int i = curNode + 1; i < sz_map; i++) { //남은 팀을 전부 다 link팀에 넣는다
				team[_link].push_back(i);
			}
			make_score(sz_map); //점수 계산 단계로 바로 간다
		}
		else make_score(curNode + 1);

		//원상복귀 시킨다.
		team[_start].pop_back();
		while (team[_link].size() != link_size) { //남은 팀을 전부 link에 넣었을 경우, 전부 빼낸다.
			team[_link].pop_back();
		}

		//2. curNode가 link 팀에 들어가는 경우
		/////////////////////////////////////
		team[_link].push_back(curNode);
		if (team[_link].size() == sz_map / 2) { //link 팀이 꽉 찬 경우
			for (int i = curNode + 1; i < sz_map; i++) { //남은 팀을 전부 다 start팀에 넣는다
				team[_start].push_back(i);
			}
			make_score(sz_map); //점수 계산 단계로 바로 간다
		}
		else make_score(curNode + 1);

		//원상복귀 시킨다.
		team[_link].pop_back();
		while (team[_start].size() != start_size) { //남은 팀을 전부 start에 넣었을 경우, 전부 빼낸다.
			team[_start].pop_back();
		}
	}
}

void operate() {
	make_score(0);
	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}