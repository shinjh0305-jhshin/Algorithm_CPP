#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

char map[5][5];
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };
bool seatPicked[25], visited[25];
int answer = 0, firstSeat;

void initialize() {
	string st;
	for (int i = 0; i < 5; i++) {
		cin >> st;
		for (int j = 0; j < 5; j++) {
			map[i][j] = st[j];			
		}
	}
}

void checkSeats() {
	int numS = 0, numY = 0;
	for (int i = 0; i < 25; i++) {
		if (seatPicked[i]) {
			map[i / 5][i % 5] == 'S' ? numS++ : numY++;
		}
	}

	if (numS < 4) return; //이다솜파가 우위를 점하지 못했다.
	
	memset(visited, false, sizeof(visited));

	queue<int> qu;
	qu.push(firstSeat);
	visited[firstSeat] = true; //가장 처음으로 나오는 자리

	int currow, curcol, nrow, ncol, nextSeat, seatLeft = 6;

	while (!qu.empty()) {
		currow = qu.front() / 5; curcol = qu.front() % 5;
		qu.pop();

		for (int k = 0; k < 4; k++) {
			nrow = currow + drow[k]; ncol = curcol + dcol[k];
			if (nrow < 0 || nrow >= 5 || ncol < 0 || ncol >= 5) continue;

			nextSeat = nrow * 5 + ncol;
			if (visited[nextSeat] || !seatPicked[nextSeat]) continue; //칠공주 좌석 중 이미 방문했거나, 칠공주 좌석이 아닌 경우 pass

			qu.push(nextSeat);
			visited[nextSeat] = true;
			seatLeft--;
		}
	}

	if (seatLeft == 0) {
		answer++;
	}
}

void pickSeats(int startNum, int depth = 1) {
	if (depth == 7) {
		checkSeats();
		return;
	}
	for (int j = startNum; j < depth + 19; j++) {
		seatPicked[j] = true;
		pickSeats(j + 1, depth + 1);
		seatPicked[j] = false;
	}
}

void operate() {
	for (firstSeat = 0; firstSeat <= 18; firstSeat++) {
		seatPicked[firstSeat] = true;
		pickSeats(firstSeat + 1);
		seatPicked[firstSeat] = false;
	}

	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}