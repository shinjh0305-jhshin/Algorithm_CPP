#include <iostream>
#include <cstring>
#include <vector>
#define endl "\n"
#define isPossible(a, b, c, d) ((double)(abs((a) - (c)) + abs((b) - (d))) / 50 <= 20)
using namespace std;

int cvs; //편의점 개수
pair<int, int> house, festival;
pair<int, int> store[102];
bool visited[102];

void initialize() {
	memset(visited, false, sizeof(visited));
	cin >> cvs;

	cin >> house.first >> house.second;
	for (int i = 0; i < cvs; i++) {
		cin >> store[i].first >> store[i].second;
	}
	cin >> festival.first >> festival.second;
}

bool traverse(int row, int col) {
	if (isPossible(row, col, festival.first, festival.second)) { //현 위치에서 바로 펜타포트로 갈 수 있다.
		return true;
	}

	int nextrow, nextcol;
	for (int i = 0; i < cvs; i++) {
		nextrow = store[i].first; nextcol = store[i].second;
		if (!visited[i] && isPossible(row, col, nextrow, nextcol)) { //방문하지 않은 편의점이고, 갈 수 있는 편의점이다.
			visited[i] = true;
			if (traverse(nextrow, nextcol)) return true;
		}
	}

	return false;
}

void operate() {
	if (traverse(house.first, house.second)) cout << "happy" << endl;
	else cout << "sad" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--) {
		initialize();
		operate();
	}

	return 0;
}