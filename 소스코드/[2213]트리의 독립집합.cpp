#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

class MIND {
private:
	vector<vector<int>> tree;
	int nodes;
	int* cost;
	int** rawdata; /*각 노드별로 포함/불포함 시 cost 저장*/
	bool* visited;
	short* set; //0 : 판단 이전, 1 :  포함, 2 : 불포함
	enum status { inc, exc };

public:
	MIND() :cost(NULL), rawdata(NULL), visited(NULL), set(NULL) {};

	void initialize() {
		cin >> nodes; cin.get();

		tree.resize(nodes + 1);
		cost = new int[nodes + 1];
		visited = new bool[nodes + 1];
		memset(visited, 0, nodes + 1);

		set = new short[nodes + 1];
		memset(set, 0, sizeof(short) * (nodes + 1));

		rawdata = new int*[nodes + 1];
		for (int i = 1; i <= nodes; i++) {
			rawdata[i] = new int[2];
		}

		for (int i = 1; i <= nodes; i++) {
			cin >> cost[i]; cin.get();
		}

		int node1, node2;
		for (int i = 1; i < nodes; i++) {
			cin >> node1 >> node2;
			tree[node1].push_back(node2);
			tree[node2].push_back(node1);
		}
	}

	void operate() {
		/*root는 항상 1로 생각*/
		dfs(1);
		print_result();
		if (rawdata[1][inc] > rawdata[1][exc]) {
			set[1] = inc + 1;
			backtracking(1, inc);
		}
		else {
			set[1] = exc + 1;
			backtracking(1, exc);
		}

		for (int i = 1; i <= nodes; i++) {
			if (set[i] == inc + 1) cout << i << ' ';
		}
		cout << endl;
	}

	void dfs(int num) {
		int mov;
		visited[num] = 1;
		rawdata[num][inc] = cost[num]; //현재 노드를 포함할 경우 얻을 수 있는 최댓값
		rawdata[num][exc] = 0; //현재 노드를 불포함할 경우 얻을 수 있는 최댓값

		for (int i = 0; i < tree[num].size(); i++) {
			mov = tree[num][i];
			if (!visited[mov]) {
				dfs(mov);
				rawdata[num][inc] += rawdata[mov][exc];
				rawdata[num][exc] += max(rawdata[mov][inc], rawdata[mov][exc]);
			}
		}
	}

	void print_result() {
		cout << max(rawdata[1][inc], rawdata[1][exc]) << endl;
	}

	void backtracking(int parent, bool parent_flag) { //parent_flag와 enum status 동기화
		int mov;
		for (int i = 0; i < tree[parent].size(); i++) {
			mov = tree[parent][i];
			if (!set[mov]) {
				if (parent_flag == inc) { //부모 node가 포함되었을 때
					set[mov] = exc + 1;
					backtracking(mov, exc);
				}

				else { //부모 node가 불포함되었을 때
					if (rawdata[mov][inc] < rawdata[mov][exc]) { //현재 자식 노드 불포함이 좋다
						set[mov] = exc + 1;
						backtracking(mov, exc);
					}
					else { //현재 자식 노드 포함이 좋다
						set[mov] = inc + 1;
						backtracking(mov, inc);
					}
				}
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	MIND op;
	op.initialize();
	op.operate();
	return 0;
}