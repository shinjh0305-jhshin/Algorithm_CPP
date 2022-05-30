#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int, int> rawdata[10]; //sour, bitter
bool used[10] = { false };
int sz, ans = 2134567890;
	
void initialize() {
	cin >> sz;
	for (int i = 0; i < sz; i++) {
		cin >> rawdata[i].first >> rawdata[i].second;
	}
}

void DFS(int level) {
	if (level == sz) {
		if (find(used, used + sz, true) == used + sz) return; //아무것도 안 썼다.

		int sour = 1, bitter = 0;
		for (int i = 0; i < sz; i++) {
			if (used[i]) {
				sour *= rawdata[i].first;
				bitter += rawdata[i].second;
			}
		}

		ans = min(ans, abs(sour - bitter));
		return;
	}

	//1. 안 쓴다
	used[level] = false;
	DFS(level + 1);

	//2. 쓴다
	used[level] = true;
	DFS(level + 1);
}

void operate() {
	DFS(0);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}