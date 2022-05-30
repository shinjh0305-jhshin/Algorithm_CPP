#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define endl "\n"
#define INF 2134567890
using namespace std;

int nodes, edges, candidates, start, mustA, mustB, btwMust; //mustA, mustB : 반드시 지나야 하는 두 노드, btwMust : mustA-mustB 사이 간격
vector<pair<int, int>> map[2002]; //도착지점, 거리
int totalCost[3][2002]; //0:시작->종료 1:mustA->종료 2:mustB->종료

void initialize() {
	cin >> nodes >> edges >> candidates >> start >> mustA >> mustB;
	for (int i = 1; i <= nodes; i++) map[i].clear(); //기존에 남아있던 map 정보를 전부 지운다.

	int from, to, cost;
	for (int i = 0; i < edges; i++) { //map 만들기
		cin >> from >> to >> cost;
		map[from].push_back({ to, cost });
		map[to].push_back({ from, cost });

		if ((from == mustA && to == mustB) || (from == mustB && to == mustA)) btwMust = cost;
	}

	for (int i = 0; i < 3; i++) { //dijkstra 배열 초기화
		for (int j = 1; j <= nodes; j++) {
			totalCost[i][j] = INF;
		}
	}
}

void dijkstra(int curTarget, int startPoint) {//curTarget : 현재 진행중인 totalCost의 row index, startPoint : start, mustA, mustB 중 한 개
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //총 거리, 시작지점
	pq.push({ 0, startPoint });
	totalCost[curTarget][startPoint] = 0;

	int curSum, curStart, dest, tempSum;
	while (!pq.empty()) {
		curSum = pq.top().first; curStart = pq.top().second; pq.pop();

		if (curSum > totalCost[curTarget][curStart]) continue; //이미 더 최단경로에서 평가되었음.

		for (const auto it : map[curStart]) {
			dest = it.first; tempSum = curSum + it.second;

			if (totalCost[curTarget][dest] <= tempSum) continue;

			totalCost[curTarget][dest] = tempSum;
			pq.push({ tempSum, dest });
		}
	}
}

void operate() { 
	dijkstra(0, start); //시작지점에서 출발하는 다익스트라
	dijkstra(1, mustA); //필수지점 중 한 쪽 끝에서 출발하는 다익스트라
	dijkstra(2, mustB); //필수지점 중 다른 쪽 끝에서 출발하는 다익스트라

	vector<int> v;

	int candidate; //도착 후보지
	for (int i = 0; i < candidates; i++) {
		cin >> candidate;

		//min(start-A-B-End, start-B-A-End)
		if (min(totalCost[0][mustA] + totalCost[2][candidate], totalCost[0][mustB] + totalCost[1][candidate]) + btwMust == totalCost[0][candidate]) {
			v.push_back(candidate);
		}
	}
	sort(v.begin(), v.end());
//	cout << "				ANSWER : ";
	for (const auto it : v) cout << it << ' ';
	cout << endl;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++) {
		initialize();
		operate();
	}

	return 0;
}