/**************************************************************************************************/
//문제의 주안점 : DFS, DP, Bitmasking
//Key Point : 시작점이 주어지지 않았더라도, 하나의 정점에서만 고려해도 된다.
//사유 : 0123450이 최소(1000원)라고 하면, 이 경로는 2345012(역시 1000원)와 정확히 일치하기 때문.
/**************************************************************************************************/
#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int city_no; //도시 수
int cost[16][16]; //비용 배열
int result[16][1 << 16]; //result[i][j] = 현재 i번 node에 있고, j에 있는 node를 방문한 상태일 때, 완주하는데 걸리는 거리.

void initialize() {
	cin >> city_no;

	for (int i = 0; i < city_no; i++) {
		for (int j = 0; j < 1 << city_no; j++) {
			result[i][j] = INF;
		}
		for (int j = 0; j < city_no; j++) {
			cin >> cost[i][j];
		}
	}
}

int tsp(int currentNode, int visited) {
	if (visited == (1 << city_no) - 1) { //모든 곳을 탐색했을 경우
		if (cost[currentNode][0] == 0) return INF; //다시 원점으로 복귀하는 루트가 없는 경우
		else return cost[currentNode][0];
	}

	if (result[currentNode][visited] != INF) return result[currentNode][visited];

	int nextVisited;
	for (int nextNode = 0; nextNode < city_no; nextNode++) {
		//현재 노드에서 다음 노드로 가는 길이 없거나, 이미 방문한 노드면 무시.
		if (cost[currentNode][nextNode] == 0 || (visited & (1 << nextNode)) != 0) continue;
		
		nextVisited = visited | 1 << nextNode;
		result[currentNode][visited] = min(result[currentNode][visited], tsp(nextNode, nextVisited) + cost[currentNode][nextNode]);
	}

	return result[currentNode][visited];
}

void operate() {
	//0번째 노드에서 출발한다고 가정한다
	cout << tsp(0, 1) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}