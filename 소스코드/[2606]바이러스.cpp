#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class virus {
private:
	vector<int> graph[102];
	int infected[102];
	int computers;
	int start = 1; //바이러스가 시작되는 컴퓨터 번호
	int edges;
	int result = 0;

public:
	void initialize() {
		cin >> computers >> edges; cin.get();

		int first, second;
		for (int i = 0; i < edges; i++) {
			cin >> first >> second; cin.get();
			graph[first].push_back(second);
			graph[second].push_back(first);
		}

		memset(infected, 0, sizeof(int) * 102);
	}

	void operate() { //with DFS
		DFS(1);

		cout << result << endl;
	}

	void DFS(int node) {
		infected[node] = 1;

		int mov = 0, temp;
		while (mov != graph[node].size()) {
			temp = graph[node][mov];
			if (infected[temp] == 0) {
				result++;
				DFS(temp);
			}
			mov++;
		}
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	virus op;
	op.initialize();
	op.operate();
	return 0;
}