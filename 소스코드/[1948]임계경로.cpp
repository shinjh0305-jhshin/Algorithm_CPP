#include <iostream>
#include <vector>
#include <algorithm>
#include <set>	
#define endl "\n"
using namespace std;

struct info {
	int from, cost;
};
vector<info> inRawdata[10003]; //inNode list로 만든다
vector<int> outRawdata[10003]; //outNode list로 만든다
bool visited[10003] = { false };
int duration[10003];
int leftNodesToCome[10003] = { 0 }; //더 들어와야 할 node개수
int runFast = 0; //쉬지 않고 달려와야 하는 도로 모임
int nodes, edges, start, finish;


void initialize() {
	cin >> nodes >> edges;

	int from, to, cost;

	for (int i = 0; i < edges; i++) {
		cin >> from >> to >> cost;
		inRawdata[to].push_back({ from, cost });
		outRawdata[from].push_back({ to });
		leftNodesToCome[to]++;
	}

	cin >> start >> finish;
}

void getminDuration(int node) {
	int numMax = 0;
	for (const auto prevNode : inRawdata[node]) {
		numMax = max(numMax, duration[prevNode.from] + prevNode.cost);
	}
	duration[node] = numMax;

	for (const auto nextNode : outRawdata[node]) {
		if (--leftNodesToCome[nextNode] == 0) { //innode의 개수를 업데이트. 위상정렬의 핵심.
			getminDuration(nextNode);
		}
	}
}

void roadsToGo(int startNode, int targetDist) {
	if (visited[startNode]) return; //분기되었다가 다시 합쳐질 경우, 분기되기 이전의 경로를 중복 counting 하는 점을 방지한다.

	visited[startNode] = true; 
	for (const auto prevNode : inRawdata[startNode]) {
		if (duration[prevNode.from] == targetDist - prevNode.cost) { //이전 노드에서 현재 노드로 올 경우, 시간이 맞는지
			runFast++; //사용할 수 있는 경로를 증가시킨다.
			roadsToGo(prevNode.from, targetDist - prevNode.cost);
		}
	}
}

void operate() {
	//1.총 걸리는 최종 시간 구하기
	getminDuration(start);
	int maxDuration = duration[finish];

	//2. 쉬지 않고 달려야 하는 도로 개수 구하기
	roadsToGo(finish, maxDuration);

	cout << maxDuration << endl;
	cout << runFast << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
5
7
1 2 1
1 3 3
2 3 2
2 4 1
2 5 3
3 5 1
4 5 1
1 5
ans : 4 5

7
9
1 2 4
1 3 2
1 4 3
2 6 3
2 7 5
3 5 1
4 6 4
5 6 2
6 7 5
1 7
ans : 12 5


5
7
1 2 1
1 3 3
2 3 2
2 4 1
4 5 1
3 5 1
2 5 3
1 5
ans : 4 5
*/