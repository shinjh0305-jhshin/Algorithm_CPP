#include <iostream>
#include <queue>
#define endl "\n"
#define INF 999999999
#pragma warning (disable:4996)
using namespace std;

int start, finish;
int visited[100003];
queue<int> qu;

void initialize() {
	cin >> start >> finish;

	for (int i = 0; i < 100003; i++) {
		visited[i] = INF;
	}

	qu.push(start);
	visited[start] = 0;
}

void operate() {
	int cur_pos, cur_time;
	while (1) {
		cur_pos = qu.front(); qu.pop();
		cur_time = visited[cur_pos];

		if (cur_pos == finish) {
			cout << cur_time << endl;
			return;
		}

		//case 1 : 뒤로 한 칸
		if (cur_pos - 1 >= 0 && visited[cur_pos - 1] > cur_time + 1) {
			qu.push(cur_pos - 1);
			visited[cur_pos - 1] = cur_time + 1;
		}

		//case 2 : 앞으로 한 칸
		if (cur_pos + 1 <= 100000 && visited[cur_pos + 1] > cur_time + 1) {
			qu.push(cur_pos + 1);
			visited[cur_pos + 1] = cur_time + 1;
		}

		//case 3 : 두배
		if (cur_pos * 2 <= 100000 && visited[cur_pos * 2] > cur_time) {
			qu.push(cur_pos * 2);
			visited[cur_pos * 2] = cur_time;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}