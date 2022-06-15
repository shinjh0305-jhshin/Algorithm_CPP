#include <iostream>
#include <vector>
#define startCity 1
#define endl "\n"
#define ll long long
#define INF 2134567890
using namespace std;

struct info {
	int start, end;
	ll cost;
};
info edge[6003];
ll totalTime[505];
int nodes, edges;

void initialize() {
	cin >> nodes >> edges;

	for (int i = 0; i < edges; i++) {
		cin >> edge[i].start >> edge[i].end >> edge[i].cost;
	}

	for (int i = 1; i <= nodes; i++) {
		totalTime[i] = INF;
	}
	totalTime[startCity] = 0;
}

bool getTime() {
	bool isINF = false; //무한히 과거로 돌아가는가

	int start, finish;
	ll cost;
	for (int i = 1; i <= nodes + 1; i++) {
		for (int k = 0; k < edges; k++) {
			start = edge[k].start; finish = edge[k].end; cost = edge[k].cost;

			if (totalTime[start] == INF) continue;
			if (totalTime[start] + cost < totalTime[finish]) {
				if (i == nodes) {
					isINF = true;
					return isINF;
				}
				totalTime[finish] = totalTime[start] + cost;
			} 
		}
	}

	return isINF;
}

void operate() {
	if (getTime()) {
		cout << -1 << endl;
	} 
	else {
		for (int i = 2; i <= nodes; i++) {
			if (totalTime[i] == INF) cout << -1 << endl;
			else cout << totalTime[i] << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}