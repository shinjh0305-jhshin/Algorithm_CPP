#include <iostream>
#include <vector>
using namespace std;

int map[52][52];
bool visited[52][52] = { false };
int sz_map, lowerBound, upperBound;

void initialize() {
	cin >> sz_map >> lowerBound >> upperBound;

	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
		}
	}
}
 /*
 1. visited를 순회하면서 이전 단계에서 인구 이동이 일어난 곳인지 확인한다.
 2. 인구 이동이 일어난 곳이라면, 들어가서 BFS를 하면서 인구 이동이 일어날 곳을 전부 vector에 넣는다. (좌표값만 넣으면 된다)
 3. BFS 탐색을 하면서 인구수의 합을 sum에서 관리한다. 또, 
 3. vector에 있는 좌표의 인구를 평탄화 시킨다.

 */


int operate() {
	int days = -1;
	bool moved = true;

	while (moved) {
		moved = false;
		days++;

		for (int i = 0; i < sz_map; i++) {
			for (int j = 0; j < sz_map; j++) {

			}
		}
	}
}
