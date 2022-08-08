#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define ll long long
#define WALL -1
#define BLANK 0
#define INF 2134567890
using namespace std;

int map[22][22];
int sz_map, ppls;
ll fuels;
pair<int, int> carPos; //row, col
pair<int, int> dest[403]; //row, col
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> sz_map >> ppls >> fuels;
	for (int i = 1; i <= sz_map; i++) {
		for (int j = 1; j <= sz_map; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = WALL;
		}
	}

	cin >> carPos.first >> carPos.second;
	
	int temprow, tempcol;
	for (int i = 1; i <= ppls; i++) {
		cin >> temprow >> tempcol;
		map[temprow][tempcol] = i;
		cin >> dest[i].first >> dest[i].second;
	}
}

pair<pair<int, int>, ll> pickUpPasenger() { //{passRow, passCol}, fuel
	int currow, curcol, nrow, ncol, sz_queue;
	bool visited[22][22] = { false };
	pair<int, int> ret = { INF, INF };

	queue<pair<int, int>> qu;
	qu.push(carPos);
	visited[carPos.first][carPos.second] = true;

	ll fuelCost = 0;
	while (!qu.empty()) {
		sz_queue = qu.size();
		while (sz_queue--) {
			currow = qu.front().first; curcol = qu.front().second;
			qu.pop();

			if (map[currow][curcol] != BLANK) { //�¿� �� �ִ� �°� �߰�
				if (currow < ret.first || (currow == ret.first && curcol < ret.second)) {
					ret.first = currow;
					ret.second = curcol;
				}
			}

			for (int k = 0; k < 4; k++) {
				nrow = currow + drow[k]; ncol = curcol + dcol[k];
				if (nrow <= 0 || nrow > sz_map || ncol <= 0 || ncol > sz_map || map[nrow][ncol] == WALL || visited[nrow][ncol]) continue;

				visited[nrow][ncol] = true;
				qu.push({ nrow, ncol });
			}
		}

		if (ret.first != INF) {
			return { ret, fuelCost };
		}
		else fuelCost++;
	}

	return { {INF, INF}, INF }; //������ ���θ����� �°����� �� �����ϴ� ���
}

ll gotoDestination(pair<int, int> curPos, int passIdx) {
	bool visited[22][22] = { false };

	queue<pair<int, int>> qu;
	qu.push(curPos);
	visited[curPos.first][curPos.second] = true;

	int sz_queue;
	int currow, curcol, nrow, ncol;
	ll fuelCost = 1;

	while (!qu.empty()) {
		sz_queue = qu.size();
		while (sz_queue--) {
			currow = qu.front().first; curcol = qu.front().second;
			qu.pop();

			for (int k = 0; k < 4; k++) {
				nrow = currow + drow[k]; ncol = curcol + dcol[k];

				if (nrow <= 0 || nrow > sz_map || ncol <= 0 || ncol > sz_map || map[nrow][ncol] == WALL || visited[nrow][ncol]) continue;

				visited[nrow][ncol] = true;

				if (dest[passIdx] == make_pair(nrow, ncol)) return fuelCost; //������ ����!
				else {
					qu.push({ nrow, ncol });
				}
			}
		}
		fuelCost++;
	}

	return INF; //������ ���θ��� ���������� �� �����ϴ� ���
}


void operate() {
	pair<pair<int, int>, ll> newPassenger;
	ll fuelToPass, fuelToDest;

	bool status = true;

	while (ppls--) {
		newPassenger = pickUpPasenger(); //���� �°� ã�´�

		pair<int, int>& newPos = newPassenger.first; //���� �°��� ��ġ
		fuelToPass = newPassenger.second; //���� �ڵ��� ��ġ���� ���� �°� ��ġ���� �����ϴ� �� �ʿ��� ���ᷮ

		if (fuels - fuelToPass < 0) { //���� ���ᷮ���δ� �°����� ���� ���Ѵ�
			status = false;
			break; 
		}

		fuels -= fuelToPass;
		int passIdx = map[newPos.first][newPos.second]; //���� �°��� �Ϸù�ȣ
		map[newPos.first][newPos.second] = BLANK;

		fuelToDest = gotoDestination(newPos, passIdx); //���� �°��� ���������� �������ִ� �� �ʿ��� ���ᷮ

		if (fuels - fuelToDest < 0) { //���� ���ᷮ���δ� ���������� ���� ���Ѵ�
			status = false; 
			break;
		}

		fuels += fuelToDest;
		carPos = dest[passIdx];

	}

	if (status) {
		cout << fuels << endl;
	}
	else {
		cout << -1 << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}