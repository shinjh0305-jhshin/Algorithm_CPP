//LCA는 또 하나의 다른 장르다.
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#define root 1
#define endl "\n"
using namespace std;

vector<int> tree[50003];
int depth[50003];
int parentInfo[17][50003] = { 0 }; //17 : ceil(log_2(50000))
bool visited[50003] = { false };
int nodes, height;

void initialize() {
	cin >> nodes;

	int innode, outnode;
	for (int i = 0; i < nodes - 1; i++) {
		cin >> innode >> outnode;
		tree[innode].push_back(outnode);
		tree[outnode].push_back(innode);
	}
}

void BFS() {
	queue<int> qu;
	qu.push(root);
	visited[root] = true;

	int curdepth = 0, cursize, curNode;
	while (!qu.empty()) {
		cursize = qu.size();
		while (cursize--) {
			curNode = qu.front(); qu.pop();
			depth[curNode] = curdepth;

			for (auto it : tree[curNode]) {
				if (!visited[it]) {
					visited[it] = true;
					parentInfo[0][it] = curNode;
					qu.push(it);
				}
			}
		}
		curdepth++;
	}

	height = curdepth - 1; //트리의 높이
}

void getLCA() {
	int maxParent, temp = 2; //maxParent : 조상쪽으로 몇 2^k단계를 올라갈 수 있는가에서 k 값
	maxParent = floor(log2(height)); //트리의 높이가 5일 경우, 모든 노드의 깊이가 2^3미만이기에 maxparent==2가 된다.
	
	for (int i = 1; i <= maxParent; i++) {
		for (int j = 1; j <= nodes; j++) {
			parentInfo[i][j] = parentInfo[i - 1][parentInfo[i - 1][j]];
		}
	}

	//쿼리를 처리한다.
	int queries, nodeA, nodeB;
	cin >> queries;

	while (queries--) {
		cin >> nodeA >> nodeB;
		if (depth[nodeA] > depth[nodeB]) swap(nodeA, nodeB);
		
		for (int k = maxParent; k >= 0; k--) {
			if (pow(2, k) <= depth[nodeB] - depth[nodeA]) { //한번에 nodeB가 2^k 계단을 올라도 되는가?
				nodeB = parentInfo[k][nodeB];
			}
		}
		/*
		31 계단을 올라야 공통 조상이 나온다 치자.
		2^5 계단을 오르면 부모가 같아지고, 2^4 계단을 오르면 부모가 다르다.
		그럼 2^4계단을 오르면, 15계단이 남게 된다. (31-16=15)
		15=2^3+2^2+2^1+2^0이기에, 2^3계단을 오를 수 있는지부터 탐색해도 무방하다.
		*/
		for (int k = maxParent; k >= 0 && nodeA != nodeB; k--) {
			if (parentInfo[k][nodeA] != parentInfo[k][nodeB]) {
				nodeA = parentInfo[k][nodeA];
				nodeB = parentInfo[k][nodeB];
			}
		}

		if (nodeA != nodeB) cout << parentInfo[0][nodeA] << endl;
		else cout << nodeA << endl;
	}
}

void operate() {
	BFS();
	getLCA();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}