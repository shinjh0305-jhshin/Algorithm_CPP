//메모이제이션 풀이 미완성(불가)
//메모이제이션을 위해서는 모든 상황에 대해서 해당 값을 참조하는 것이 보장되어야 하나.
//그래프의 탐색 과정에서는 한 노드를 방문했을 때, 직전 방문 노드에 대한 처리가 불가능하기에
//메모이제이션을 위해서는 문제 상에서 특수 조건이 주어져야 한다.

#include <iostream>
#include <vector>
#include <algorithm>
#define MIN -1
using namespace std;

vector<pair<int, int>> map[100005]; //{node, cost}
int maxWeight[100005]; //각 노드에서 끝 노드로 갈 수 있는 무게의 메모이제이션
int nodes, edges, startNode, endNode;

void initialize() {
	cin >> nodes >> edges;

	int nodeA, nodeB, cost;
	for (int i = 0; i < edges; i++) {
		cin >> nodeA >> nodeB >> cost;
		map[nodeA].push_back({ nodeB, cost });
		map[nodeB].push_back({ nodeA, cost });
	}

	for (int i = 1; i <= nodes; i++) {
		maxWeight[i] = MIN; //최소 무게로 설정한다.
	}
	maxWeight[endNode] = 2134567890; //도착지는 max weight을 줘서, 무게의 lower_bound의 메모이제이션에 영향이 없도록 한다.
}

bool DFS(int node) {
	int sz_map = map[node].size(), nextNode;
	for (int i = 0; i < sz_map; i++) {
		nextNode = map[node][i].first;
		if (maxWeight[nextNode] != MIN) { //방문한 적 있다.
			maxWeight[node] = max(maxWeight[node], min(map[node][i].second, maxWeight[nextNode])); //갈 수 있는 노드들 중에서 최댓값을 찾는다.
		}
		else { //새로 방문해야 한다.
			if (DFS(nextNode)) { //도착점까지 도달 할 수 있는 경로 상의 노드를 방문했다.
				//갈 수 있는 노드들 중에서 최댓값을 찾는다. min() : 현재 노드에서 다음 노드로 가는 다리 허용 무게와, 다음 노드에서 그 다음 노드로 해서 도착까지 갈 수 있는 최대 무게 중 최솟값
				maxWeight[node] = max(maxWeight[node], min(map[node][i].second, maxWeight[nextNode])); 
			}
		}
	}

	if (maxWeight[node] != MIN) return true; //현재 노드를 통해 끝까지 갈 수 있는 최대 무게가 생겼다.
	else return false;
}