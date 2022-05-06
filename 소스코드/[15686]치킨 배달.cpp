//1. 현재 치킨집을 없앤다
//2. 현재 치킨집에 바인딩되었던 집은 다른 치킨집을 찾아 나선다
//3. 다음 치킨집으로 이동한다.
//3-1. 다음 치킨집으로 이동 할 때는 이전 치킨거리의 합만 전달하면 된다.

//필요 함수 : 재귀 밖 함수, 재귀함수, 치킨 거리 찾는 함수

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define endl "\n"
using namespace std;

struct pos {
	int row, col;
};

int map[52][52];
bool closed[15] = { false };
enum a { _home = 1, _chicken };
vector<pos> chicken, house;
int sz_map, close, result = 1234567890;

void initialize() {
	cin >> sz_map >> close;
	for (int i = 0; i < sz_map; i++) {
		for (int j = 0; j < sz_map; j++) {
			cin >> map[i][j];
			if (!map[i][j]) continue;
			if (map[i][j] == _home) { //house
				house.push_back({ i, j });
			}
			else if (map[i][j] == _chicken) { //chicken
				chicken.push_back({ i, j });
			}
		}
	}
}

void findChickenDist(int houseIdx, int &distance) { //전달 된 집의 치킨 거리를 계산해서 전체 치킨 거리에 반영한다.
	int houseRow = house[houseIdx].row, houseCol = house[houseIdx].col; //현재 집의 index
	int chickenDist = 1234567890, temp, iter = 0;

	for (auto it : chicken) { //치킨집들을 순회한다
		if (!closed[iter]) { //폐업하지 않은 치킨집이라면
			temp = abs(it.row - houseRow) + abs(it.col - houseCol);
			chickenDist = min(chickenDist, temp); //현재 치킨집이 현 집에서 가장 가까운 곳인가?
		}
		iter++;
	}
	
	distance += chickenDist; //현재 치킨 거리를 더한다.
}

void closeChicken(int start, int togo) { //start : 작업 시작하는 치킨집 인덱스, togo : 닫아야 할 잔여 치킨집 개수
	if (togo == 0) { //닫을 치킨집이 없다.
		int dist = 0, sz_house = house.size();
		for (int i = 0; i < sz_house; i++) {
			findChickenDist(i, dist); //각 집의 치킨 거리를 구한다.
		}
		result = min(dist, result);
		return;
	}

	int upperBound = chicken.size() - togo;
	for (int i = start; i <= upperBound; i++) {
		closed[i] = true; //치킨집을 닫는다.
		closeChicken(i + 1, togo - 1); //다음 치킨집을 닫으러 떠난다.
		closed[i] = false; //다시 원상복귀시킨다.
	}
}

void operate() {
	closeChicken(0, chicken.size() - close);
	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
