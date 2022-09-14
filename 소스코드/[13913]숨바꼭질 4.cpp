#include <iostream>
#include <queue>	
#include <stack>
#define INF 2134567890
using namespace std;

queue<int> qu;
int visited[200005];
int subin, sister, upperBound;

void initialize() {
	cin >> subin >> sister;
	upperBound = sister > subin ? sister + sister - subin : subin;

	for (int i = 0; i <= upperBound; i++) {
		visited[i] = INF;
	}
}

void printResult() {
	int curPos = sister;
	stack<int> st;

	while (1) {
		st.push(curPos);
		if (curPos == subin) break;
		curPos = visited[curPos];
	}

	cout << st.size() - 1 << endl;
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}

void operate() {
	qu.push(subin);
	visited[subin] = subin;

	int curPos, nextPos;
	while (1) {
		curPos = qu.front(); qu.pop();
		if (curPos == sister) goto print;

		for (int i = 0; i < 3; i++) {
			if (i == 0) nextPos = curPos - 1;
			else if (i == 1) nextPos = curPos + 1;
			else nextPos = curPos * 2;

			if (nextPos < 0 || upperBound < nextPos || visited[nextPos] != INF) continue;

			visited[nextPos] = curPos;
			qu.push(nextPos);
		}
	}

print: printResult();

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}