/**************************************************************************************************/
//문제의 주안점 : DFS, DP, Bitmasking
//Key Point : 시작점이 주어지지 않았더라도, 하나의 정점에서만 고려해도 된다.
//사유 : 0123450이 최소(1000원)라고 하면, 이 경로는 2345012(역시 1000원)와 정확히 일치하기 때문.
/**************************************************************************************************/
#include <iostream>
#include <algorithm>
#define INF 2000000000
#define UNVISITED -1
using namespace std;

int city_no; //도시 수
int cost[16][16]; //비용 배열
int result[16][1 << 16]; //result[i][j] = 현재 i번 node에 있고, j에 있는 node를 방문한 상태일 때, 완주하는데 걸리는 거리.

void initialize() {
	cin >> city_no;

	for (int i = 0; i < city_no; i++) {
		for (int j = 0; j < 1 << city_no; j++) {
			result[i][j] = UNVISITED;
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

	//초기화를 INF로 하면 안 되는 이유 : 옷걸이 구조일 때 문제 발생 가능
	//모든 노드를 삥 돌아서 다시 현재 노드로 와서 다시 삥 돌아서 다시 현재 노드로 올 경우
	//currentNode와 visited가 같은 상황이 발생한다.
	//이 때, result가 INF이냐 아니냐로 따지면, 당연히 result는 INF이기에 다시 루프를 돈다.
	//즉, 현재 탐지를 시작했다는 표시는 INF로 가고, 탐지를 시작하지도 않았다는 UNVISITED로 해야 된다.

	if (result[currentNode][visited] != UNVISITED) return result[currentNode][visited];

	int nextVisited;
	result[currentNode][visited] = INF;
	for (int nextNode = 0; nextNode < city_no; nextNode++) {
		//현재 노드에서 다음 노드로 가는 길이 없거나, 이미 방문한 노드면 무시.
		if (cost[currentNode][nextNode] == 0 || (visited & (1 << nextNode)) != 0) continue;
		
		nextVisited = visited | (1 << nextNode);
		result[currentNode][visited] = min(result[currentNode][visited], cost[currentNode][nextNode] + tsp(nextNode, nextVisited));
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