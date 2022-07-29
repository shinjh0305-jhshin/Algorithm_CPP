#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2134567890
using namespace std;

struct info {
	int dest, cost, time;
};
struct compare {
	bool operator() (const info& a, const info& b) {
		return a.time > b.time;
	}
};
int dp[103][10005]; //row�� ���׿� col�� �������� dp[row][col]�� �ּҽð����� �����Ѵ�.
int airports, maxCost, tickets;

priority_queue<info, vector<info>, compare> pq;
vector<vector<info>> map;

void initialize() {
	cin >> airports >> maxCost >> tickets;
	map.clear();
	map.resize(airports + 5);

	int from, to, cost, time;
	for (int i = 0; i < tickets; i++) {
		cin >> from >> to >> cost >> time;
		map[from].push_back({ to, cost, time });
	}

	for (int i = 1; i <= airports; i++) {
		for (int j = 0; j <= maxCost; j++) {
			dp[i][j] = INF;
		}
	}
	dp[1][0] = 0;
}

void operate() {
	pq.push({ 1,0,0 });

	int curAirport, curCost, curTime, nextAirport, nextCost, nextTime;
	while (!pq.empty()) {
		curAirport = pq.top().dest; curCost = pq.top().cost; curTime = pq.top().time;
		pq.pop();

		if (dp[curAirport][curCost] < curTime) continue;

		for (const auto& nextTicket : map[curAirport]) {
			nextAirport = nextTicket.dest; nextCost = curCost + nextTicket.cost; nextTime = curTime + nextTicket.time;

			if (nextCost > maxCost || dp[nextAirport][nextCost] <= nextTime) continue;

			dp[nextAirport][nextCost] = nextTime;
			for (int j = nextCost + 1; j <= maxCost; j++) { //5���� �鿩�� 5�ð����� ������, 5���� �鿩�� 100�ð����� �� �Ŵ� �ʿ䰡 ����.
				if (dp[nextAirport][j] > nextTime) dp[nextAirport][j] = nextTime;
			}
			pq.push({ nextAirport, nextCost, nextTime });
		}
	}

	int ans = INF;
	for (int j = 0; j <= maxCost; j++) {
		ans = min(ans, dp[airports][j]);
	}
	
	if (ans == INF) cout << "Poor KCM" << endl;
	else cout << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--) {
		initialize();
		operate();
	}


	return 0;
}