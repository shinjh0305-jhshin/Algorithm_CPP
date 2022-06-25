#include <iostream>
#include <vector>
using namespace std;

int nodes, root, target;
vector<int> tree[52];

void initialize() {
	cin >> nodes;

	int temp;
	for (int i = 0; i < nodes; i++) {
		cin >> temp;
		if (temp == -1) {
			root = i;
			continue;
		}
		tree[temp].push_back(i);
	}

	cin >> target; //node to erase
}

int DFS(int node) {
	bool status = false; //현재 노드에서 아래 방향으로 DFS 탐색이 이루어 졌는가?
	int ret = 0;

	for (const auto& it : tree[node]) {
		if (it == target) continue;
		status = true;
		ret += DFS(it);
	}

	if (status == false) return 1; //갈 수 있는 자식 노드가 없을 경우, 리프 노드이다
	else return ret; //자식 노드의 리프 개수의 합을 구한다
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	
	if (target == root) cout << 0 << endl;
	else cout << DFS(root) << endl;

	return 0;
}