/*
이 문제의 핵심은 A에서 B로 무한루프를 돌고서 갈 수 있는지를 판별하는 것이다.
그래프에 양의 가충지를 갖는 무한루프가 있는지를 판단하려면 N-1번의 에지 탐색을 마친 뒤 (N : 노드 개수)
1번의 에지 탐색을 추가로 하면 되지만,
이 경우에는 특정 노드부터 특정 노드까지 양의 가중치를 갖는 무한루프를 사용할 수 있는지를 판단해야 하는 경우이므로,
★노드보다 충분히 많은 값으로 에지 탐색을 해야 한다. (시작에서 시작으로 오는 양의 무한 루프가 존재하는 경우 처리)
이를 통해 무한루프 중간에 있는 모든 노드들이 무한루프에 포함 된 노드로 바뀌게 된다.
*/

#include <iostream>
#include <algorithm>
#define endl "\n"
#define ll long long
#define INF 2134567890000
#define MIN -2134567890000
using namespace std;

struct info {
	int start, end, cost;
};

ll cityProfit[53], totalSum[53];
info edge[53];
int cities, edges, start, finish;

void initialize() {
	cin >> cities >> start >> finish >> edges;

	for (int i = 0; i < edges; i++) {
		cin >> edge[i].start >> edge[i].end >> edge[i].cost;
	}

	for (int i = 0; i < cities; i++) {
		cin >> cityProfit[i];
		totalSum[i] = MIN;
	}
	totalSum[start] = cityProfit[start]; //최초 시작지 초기화
}

void operate() {
	int edgeStart, edgeEnd, edgeCost;

	for (int iter = 0; iter < cities + 50; iter++) { //도착지가 무한루프 중간 혹은 그 이후에 있을 수 있기에, 1배수만큼 루프를 추가로 돌린다.
		for (int k = 0; k < edges; k++) {
			edgeStart = edge[k].start; edgeEnd = edge[k].end; edgeCost = edge[k].cost;

			if (totalSum[edgeStart] == MIN) continue; //아직 방문하지 않음.	

			if (totalSum[edgeStart] == INF) totalSum[edgeEnd] = INF; //시작 지점이 루프 중간 혹은 이후에 나왔다
			else if (totalSum[edgeStart] + cityProfit[edgeEnd] - edgeCost > totalSum[edgeEnd]) { //더 이득이 생겼다
				if (iter >= cities) totalSum[edgeEnd] = INF;
				else {
					totalSum[edgeEnd] = totalSum[edgeStart] + cityProfit[edgeEnd] - edgeCost;
				}
			}
		}
	}

	if (totalSum[finish] == MIN) cout << "gg" << endl;
	else if (totalSum[finish] == INF) cout << "Gee" << endl;
	else cout << totalSum[finish] << endl;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}