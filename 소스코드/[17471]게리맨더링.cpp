#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define RED 0
#define BLUE 1
#define INF 2134567890
using namespace std;

vector<int> map[12];
int population[12];
int whichSide[12];
int cities, ans = INF;

void initialize() {
	cin >> cities;
	for (int i = 1; i <= cities; i++) {
		cin >> population[i];
	}
	int iter;
	for (int i = 1; i <= cities; i++) {
		cin >> iter;
		map[i].resize(iter);

		for (int j = 0; j < iter; j++) {
			cin >> map[i][j];
		}
	}
}

bool traverseCity(int city) {
	bool visited[12] = { false };
	int targetSide = whichSide[city]; //targetSide : 1번 도시가 어디에 속하나

	queue<int> qu;
	qu.push(city); visited[city] = true; //1번 도시와 같은 그룹의 도시를 순회한다

	int curcity;
	while (!qu.empty()) {
		curcity = qu.front(); qu.pop();

		for (const auto& it : map[curcity]) {
			if (whichSide[it] == targetSide && !visited[it]) {
				visited[it] = true;
				qu.push(it);
			}
		}
	}

	for (int i = 1; i <= cities; i++) {
		if (whichSide[i] == targetSide && !visited[i]) return false;
	}

	return true;
}

void checkPossible() {
	bool visited[12] = { false };

	bool allInOneGroup = true;
	for (int i = 2; i <= cities; i++) { //1개의 그룹으로 이루어져 있는가?
		if (whichSide[i] != whichSide[1]) {
			allInOneGroup = false;
			break;
		}
	}

	if (allInOneGroup) return; 

	if (!traverseCity(1)) return; //1과 같은 그룹 도시 순회.

	int nextcity; //1과 다른 그룹에 속한 도시 찾는다.
	for (nextcity = 2; nextcity <= cities; nextcity++) {
		if (whichSide[nextcity] != whichSide[1]) break;
	}

	if (!traverseCity(nextcity)) return; //1과 다른 그룹 도시 순회

	//두 그룹 간의 인구 수 차이 구한다
	int redcnt = 0, bluecnt = 0;
	for (int i = 1; i <= cities; i++) {
		if (whichSide[i] == RED) redcnt += population[i];
		else bluecnt += population[i];
	}

	ans = min(ans, abs(redcnt - bluecnt));
}

void DFS(int city) {
	if (city > cities) {
		checkPossible();
		return;
	}

	whichSide[city] = RED;
	DFS(city + 1);

	whichSide[city] = BLUE;
	DFS(city + 1);
}

void operate() {
	DFS(1);

	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}