#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
#define INF 98765432
#define endl "\n"
using namespace std;

struct info {
	short destination;
	short cost;
};

class dijkstra {
private:
	int nodes, edges, beginning;
	vector<info>* map;
	int* distance;

public:
	dijkstra() :nodes(0), edges(0), distance(NULL) {};

	void initialize() {
		cin >> nodes >> edges; cin.get();
		cin >> beginning; cin.get();

		int i;
		map = new vector<info>[nodes + 1];

		short start_node, end_node, price;
		for (i = 0; i < edges; i++) {
			cin >> start_node >> end_node >> price; cin.get();
			map[start_node].push_back({ end_node, price });
		}

		distance = new int[nodes + 1];
		for (i = 1; i <= nodes; i++) {
			distance[i] = INF;
		}
	}

	void get_min_dist() {
		priority_queue<pair<int, int>> pq; //{cost, starting point}를 넣는다.

		int iter, min_cost, start_point, destination;
		pq.push({ 0, beginning });
		distance[beginning] = 0;

		while (!pq.empty()) {
			iter = map[pq.top().second].size();
			min_cost = -pq.top().first;
			start_point = pq.top().second;

			for (int i = 0; i < iter; i++) {
				destination = map[start_point][i].destination;
				if (min_cost + map[start_point][i].cost < distance[destination]) {
					distance[destination] = min_cost + map[start_point][i].cost;
					pq.push({ -distance[destination], destination });
				}
			}
			pq.pop();
		}
	}

	void print_dist() {
		for (int i = 1; i <= nodes; i++) {
			if (distance[i] == INF)
				cout << "INF" << endl;
			else
				cout << distance[i] << endl;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	dijkstra op;
	op.initialize();
	op.get_min_dist();
	op.print_dist();
	return 0;
}