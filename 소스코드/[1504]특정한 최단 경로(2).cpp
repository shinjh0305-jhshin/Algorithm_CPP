#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl "\n"
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;

struct info {
	int node;
	int dist;
};
struct compare {
	bool operator()(const info &a, const info &b) {
		if (a.dist > b.dist) return true;
		return false;
	}
};
vector<info> map[805];
int nodes, edges;

int start_To_X[805]; //시작점에서 출발
int A_To_X[805]; //경유지1에서 출발
int B_To_X[805]; //경유지2에서 출발
int A, B;

void initialize() {
	cin >> nodes >> edges;

	int node1, node2, dist;
	for (int i = 0; i < edges; i++) {
		cin >> node1 >> node2 >> dist;
		map[node1].push_back({ node2, dist });
		map[node2].push_back({ node1, dist });
	}
	cin >> A >> B;

	for (int i = 1; i <= nodes; i++) { //각 다익스트라 배열 초기화
		start_To_X[i] = A_To_X[i] = B_To_X[i] = INF;
	}

	start_To_X[1] =  A_To_X[A] = B_To_X[B] = 0; //각 다익스트라 배열의 시작점 초기화
}


void dijkstra(int(&dist)[805], int start_node) {
	priority_queue<info, vector<info>, compare> pq;
	pq.push({ start_node, 0 });

	int curnode, curdist, nnode, ndist;
	int sz_node;

	while (!pq.empty()) {
		curnode = pq.top().node; curdist = pq.top().dist; pq.pop();
		sz_node = map[curnode].size();

		if (curdist > dist[curnode]) continue;

		for (int i = 0; i < sz_node; i++) {
			nnode = map[curnode][i].node; ndist = map[curnode][i].dist + curdist;

			if (ndist < dist[nnode]) {
				dist[nnode] = ndist;
				pq.push({ nnode, ndist });
			}
		}
	}
}

void operate() {
	dijkstra(start_To_X, 1);
	dijkstra(A_To_X, A);
	dijkstra(B_To_X, B);

	int distRoute1, distRoute2;
	bool flag1 = false, flag2 = false;

	//Evaluate route 1->A->B->End
	if (start_To_X[A] == INF || A_To_X[B] == INF || B_To_X[nodes] == INF) flag1 = true;
	else distRoute1 = start_To_X[A] + A_To_X[B] + B_To_X[nodes];

	//Evaluate route 1->B->A->End
	if (start_To_X[B] == INF || B_To_X[A] == INF || A_To_X[nodes] == INF) flag2 = true;
	else distRoute2 = start_To_X[B] + B_To_X[A] + A_To_X[nodes];

	if (flag1 && flag2) cout << -1 << endl;
	else cout << min(distRoute1, distRoute2) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}