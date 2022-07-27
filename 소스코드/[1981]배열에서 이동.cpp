/*
1. �迭 ������ �ּڰ��� minValue, �ִ��� maxValue�� ����.
2. �� �迭 ������ �ִ�-�ּ��� ���̴� 0���� maxValue-minValue�� �ȴ�.
3. �� �� ������ �̺� Ž���� �ǽ��Ѵ�. mid�� �޴´�.
	4. minValue ~ maxValue ������ ���� i�� �ϳ��� �޾ƿ´�.
	5. �迭�� �� ĭ �߿��� ���� i���� i+mid ������ ��쿡�� Ž���� �ǽ��Ѵ�.
	6. Ž���� ������ ��, ������ ĭ�� �����ϸ� Ž���� ��ģ��.
7. Ž���� ����� ���� mid�� �����Ѵ�.

���� ���ϸ�, n���� m ���� ���ڷ� Ž���� �� �� �ִ�?�� ���캸�µ�, ������ ��� n�� ���ؼ� n�� m ������ �Ÿ��� �̺�Ž���Ѵ�.
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