#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#define endl "\n"
#define space " "
using namespace std;

pair<int, int> rawdata[250000];
int visited[250000];
int sz_map, sz_rawdata, maxDestination = 1;
int dblock[6];

void initialize() {
	cin >> sz_map;
	sz_rawdata = sz_map * sz_map - sz_map / 2;
	for (int i = 1; i <= sz_rawdata; i++) {
		cin >> rawdata[i].first >> rawdata[i].second;
	}
	visited[1] = -1; //starting point

	dblock[0] = -sz_map; dblock[1] = -1; dblock[2] = sz_map - 1;
	dblock[3] = -sz_map + 1; dblock[4] = 1; dblock[5] = sz_map;
}

int blockRow(int blockIdx) {
	int ret = 0;
	ret += 2 * (blockIdx / (2 * sz_map - 1));

	blockIdx %= (2 * sz_map - 1);

	if (blockIdx >= 1 && blockIdx <= sz_map) ret += 1;
	else if (blockIdx != 0) ret += 2;
	
	return ret;
}

void BFS() {
	queue<int> qu;
	qu.push(1);

	int curBlock, nextBlock, curRow, nextRow;

	while (!qu.empty()) {
		curBlock = qu.front(); qu.pop();
		curRow = blockRow(curBlock);

		for (int k = 0; k < 6; k++) {
			nextBlock = curBlock + dblock[k];
			nextRow = blockRow(nextBlock);

			if (nextBlock <= 0 || nextBlock > sz_rawdata) continue; //out of bound

			if ((k % 3 == 0 && nextRow != curRow - 1) || (k % 3 == 1 && nextRow != curRow) || (k % 3 == 2 && nextRow != curRow + 1)) continue; //줄이 이상하게 바뀌는 경우

			if (k < 3 && rawdata[curBlock].first != rawdata[nextBlock].second) continue; //서로 다른 값일 경우
			else if (k >= 3 && rawdata[curBlock].second != rawdata[nextBlock].first) continue;

			if (visited[nextBlock]) continue; //이미 방문한 곳일 경우

			visited[nextBlock] = curBlock;
			maxDestination = max(maxDestination, nextBlock);
			qu.push(nextBlock);
		}
	}
}

void printResult() {
	stack<int> st;
	int curIdx = maxDestination;

	while (curIdx != 1) {
		st.push(curIdx);
		curIdx = visited[curIdx];
	}
	st.push(1);

	cout << st.size() << endl;
	while (!st.empty()) {
		cout << st.top() << space;
		st.pop();
	}
}

void operate() {
	BFS();
	printResult();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}