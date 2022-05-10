#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define endl "\n"
#define STATUS vector<bool>
using namespace std;

int sz_cities;
int ppls[11];
vector<int> map[11];

void initialize() {
	cin >> sz_cities;

	for (int i = 1; i <= sz_cities; i++) {
		cin >> ppls[i];
	}

	int iter, target;
	for (int i = 1; i <= sz_cities; i++) {
		cin >> iter;
		for (int j = 0; j < iter; j++) {
			cin >> target;
			map[i].push_back(target);
		}
	}
}

bool check_connection(STATUS visited) {
	int target;
	queue<int> qu;

	target = find(visited.begin() + 1, visited.begin() + sz_cities, false) - visited.begin();
	visited[target] = true;
	qu.push(target);

	while (!qu.empty()) {
		target = qu.front(); qu.pop();
		for (int i = 0; i < map[target].size(); i++) {
			if (visited[map[target][i]] == false) {
				qu.push(map[target][i]);
				visited[map[target][i]] = true;
			}
		}
	}

	if (find(visited.begin() + 1, visited.begin() + sz_cities, false) != visited.begin() + sz_cities) return false;
	return true;
}

void operate() {
	queue<STATUS> qu;
	STATUS visited(11, false), original, temp;
	int target, withOne, withoutOne, answer = 123456790;
	visited[1] = true; //1을 기준으로 생각한다
	qu.push(visited);

	while (!qu.empty()) {
		original = temp = qu.front(); qu.pop(); //original : 초기에 받아온 연결관계, temp : 같은 노드 재방문 금지하는 워킹메모리

		if (check_connection(original)) { //도시 간 연결 조건이 충족한다면
			withOne = withoutOne = 0;
			for (int i = 1; i <= sz_cities; i++) {
				if (original[i] == true)  withOne += ppls[i];
				else withoutOne += ppls[i];
			}
			answer = min(answer, abs(withOne - withoutOne));
		}
		
		for (int i = 1; i <= sz_cities; i++) {
			if (original[i] == true) { //1과 같은 그룹에 있는 도시
				for (int j = 0; j < map[i].size(); j++) {
					target = map[i][j];

					if (temp[target] == false) { //선택된 적 없다
						temp[target] = true; //방문 이력 표시

						original[target] = true;
						qu.push(original);
						original[target] = false;
					}
				}
			}
		}
	}
	if (answer == 123456790) cout << -1 << endl;
	else cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	operate();

	return 0;
}