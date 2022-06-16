#include <iostream>
#include <vector>
using namespace std;

int friends, rels;
vector<int> rawdata[2005];
bool visited[2005] = { false };

void initialize() {
	cin >> friends >> rels;

	int a, b;
	for (int i = 0; i < rels; i++) {
		cin >> a >> b;
		rawdata[a].push_back(b);
		rawdata[b].push_back(a);
	}
}

bool BFS(int level, int num) { //level : 충족해야 하는 친구 수, num : 현재 사람 번호
	if (level == 5) {
		return true;
	}

	visited[num] = true;

	for (auto it : rawdata[num]) {
		if (!visited[it]) {
			bool isPossible = BFS(level + 1, it);
			if (isPossible) {
				return true;
			}
		}
	}

	visited[num] = false;
	return false;
}

void operate() {
	for (int i = 0; i < friends; i++) {
		if (BFS(1, i)) {
			cout << 1 << endl;
			return;
		}
	}
	cout << 0 << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}