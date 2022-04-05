#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class travel {
private:
	vector<int>* graph;
	int* visited;
	int start, nodes, edges;

public:
	void initialize() {
		cin >> nodes >> edges >> start; cin.get();
		graph = new vector<int>[nodes + 1];
		visited = new int[nodes + 1];

		int first, second;
		for (int i = 0; i < edges; i++) {
			cin >> first >> second; cin.get();

			graph[first].push_back(second); 
			graph[second].push_back(first);
		}

		for (int i = 1; i <= nodes; i++) {
			sort(graph[i].begin(), graph[i].end());
		}
	}

	void BFS() {
		memset(visited, 0, sizeof(int)*(nodes + 1));
		doBFS(start); cout << endl;
	}

	void DFS() {
		memset(visited, 0, sizeof(int)*(nodes + 1));
		queue<int> qu;
		qu.push(start);
		visited[start] = 1;

		int mov, curNode, nextNode;
		while (!qu.empty()) {
			curNode = qu.front(); qu.pop();
			cout << curNode << ' ';
			
			mov = 0;
			while (mov != graph[curNode].size()) {
				nextNode = graph[curNode][mov];
				if (visited[nextNode] == 0) {
					qu.push(nextNode);
					visited[nextNode] = 1;
				}
				mov++;
			}
		}
		cout << endl;
	}

	void doBFS(int startNode) {
		cout << startNode << ' ';
		visited[startNode] = 1;
		int mov = 0, nextnode;
		while (mov != graph[startNode].size()) {
			nextnode = graph[startNode][mov];
			if (visited[nextnode] == 0) { //NOT VISITED
				doBFS(nextnode);
			}
			mov++;
		}
	}
};


int main() {
	ios::sync_with_stdio(false);
	travel op;
	op.initialize();
	op.BFS();
	op.DFS();
	return 0;
}