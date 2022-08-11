#include <iostream>
#include <queue>
using namespace std;

int height, start, goal, up, down;
bool visited[1000005];

void initialize() {
	cin >> height >> start >> goal >> up >> down;
}

void operate() {
	queue<int> qu;
	qu.push(start);
	visited[start] = true;

	if (start == goal) {
		cout << 0 << endl;
		return;
	}

	int sz_queue, curheight, nextheight, iter = 1;
	while (!qu.empty()) {
		sz_queue = qu.size();

		while (sz_queue--) {
			curheight = qu.front(); qu.pop();

			for (int i = 0; i < 2; i++) {
				nextheight = i == 0 ? curheight + up : curheight - down;
				if (nextheight <= 0 || nextheight > height || visited[nextheight]) continue;

				if (nextheight == goal) {
					cout << iter << endl;
					return;
				}

				visited[nextheight] = true;
				qu.push(nextheight);
			}
		}

		iter++;
	}

	cout << "use the stairs" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}