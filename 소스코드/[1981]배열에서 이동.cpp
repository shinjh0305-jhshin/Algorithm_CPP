/*
1. 배열 내에서 최솟값을 minValue, 최댓값을 maxValue라 하자.
2. 이 배열 내에서 최대-최소의 차이는 0부터 maxValue-minValue가 된다.
3. 이 값 내에서 이분 탐색을 실시한다. mid로 받는다.
	4. minValue ~ maxValue 사이의 값을 i가 하나씩 받아온다.
	5. 배열의 각 칸 중에서 값이 i부터 i+mid 사이일 경우에만 탐색을 실시한다.
	6. 탐색을 진행한 뒤, 마지막 칸에 도달하면 탐색을 마친다.
7. 탐색의 결과에 따라 mid를 조절한다.

쉽게 말하면, n부터 m 사이 숫자로 탐색을 할 수 있니?를 살펴보는데, 가능한 모든 n에 대해서 n과 m 사이의 거리를 이분탐색한다.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int sz_rawdata, minValue = 2134567890, maxValue = -1;
int rawdata[103][103];
int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		for (int j = 0; j < sz_rawdata; j++) {
			cin >> rawdata[i][j];
			minValue = min(minValue, rawdata[i][j]);
			maxValue = max(maxValue, rawdata[i][j]);
		}
	}
}

bool BFS(int mid) {
	bool visited[103][103] = { false };

	queue<pair<int, int>> qu; //row, col
	int sz_qu, currow, curcol, nrow, ncol;

	for (int minNum = minValue; minNum <= maxValue; minNum++) {
		int maxNum = minNum + mid;
		if (rawdata[0][0] < minNum || maxNum < rawdata[0][0]) continue;

		memset(visited, false, sizeof(visited));
		qu.push({ 0,0 });
		visited[0][0] = true;

		while (!qu.empty()) {
			sz_qu = qu.size();
			while (sz_qu--) {
				currow = qu.front().first; curcol = qu.front().second;
				qu.pop();

				for (int i = 0; i < 4; i++) {
					nrow = currow + drow[i]; ncol = curcol + dcol[i];
					if (nrow < 0 || nrow >= sz_rawdata || ncol < 0 || ncol >= sz_rawdata || visited[nrow][ncol] || rawdata[nrow][ncol] < minNum || maxNum < rawdata[nrow][ncol]) continue;
					
					if (nrow == sz_rawdata - 1 && ncol == sz_rawdata - 1) return true;

					visited[nrow][ncol] = true;
					qu.push({ nrow, ncol });
				}
			}
		}

	}

	return false;
}

void operate() {
	int left = 0, right = maxValue - minValue, mid, temp;

	while (left <= right) {
		mid = (left + right) / 2;
		if (BFS(mid)) {
			temp = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << temp << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}