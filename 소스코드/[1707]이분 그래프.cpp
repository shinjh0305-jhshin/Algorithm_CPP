//그래프를 DFS 탐색을 하면서
//나와 연결된 node가 색깔이 나와 같은 상황밖에 발생할 수 없으면
//이분 그래프를 못 만드는 것이다.

#include <iostream>
#include <vector>
#include <cstring>
#define type1 1 //색칠의 종류
#define type2 2
using namespace std;

vector<int> map[20003];
int visited[20003];
int nodes, edges;

void initialize() {
	int from, to;
	
	cin >> nodes >> edges;
	for (int i = 1; i <= nodes; i++) map[i].clear();

	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		map[from].push_back(to);
		map[to].push_back(from);
	}

	memset(visited, 0, sizeof(visited));
}

bool DFS(int num, int previousType) {
	int currentType = visited[num] = previousType == type1 ? type2 : type1; //이전 타입과 반대되는 색상을 선택

	for (auto nextNode : map[num]) {
		if (visited[nextNode] && visited[nextNode] == currentType) { //방문한 적 있는 노드고, 현재 노드랑 색깔이 똑같다.
			return false;
		}
		else if (!visited[nextNode]) {
			if (DFS(nextNode, currentType) == false) { //실패...
				return false;
			}
		}
	}
	
	return true;
}

void operate() {
	for (int i = 1; i <= nodes; i++) {
		if (!visited[i]) {
			if (!DFS(i, type2)) { //첫 시작은 type1로 한다.
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;
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