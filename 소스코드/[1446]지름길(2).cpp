#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int front;
	int back;
	int dist;
};

vector<info> rawdata;
int numRoad, distHighway;
int dp[10005];

bool compare(const info &a, const info &b) {
	if (a.back < b.back) return true;
	return false;
}

void initialize() {
	cin >> numRoad >> distHighway;

	rawdata.resize(numRoad);
	for (int i = 0; i < numRoad; i++) {
		cin >> rawdata[i].front >> rawdata[i].back >> rawdata[i].dist;
	}

	sort(rawdata.begin(), rawdata.end(), compare); //지름길의 종료 위치 순으로 정렬한다.
}

void operate() {
	dp[0] = 0;
	int roadIdx = 0; //현재 평가 대기중인 지름길 INDEX
	int curFront, curBack, curDist; //현재 roadIdx가 가르키고 있는 지름길에 대한 정보
	int curIdx = 1; //현재 평가중인 지점

	curFront = rawdata[roadIdx].front; curBack = rawdata[roadIdx].back; curDist = rawdata[roadIdx].dist;
	for (curIdx = 1; curIdx <= distHighway; curIdx++) {
		if (curIdx < curBack) { //평가 대기중인 지름길의 종료 지점까지 못 왔을 경우
			dp[curIdx] = dp[curIdx - 1] + 1;
		}
		else { //평가 대기중인 지름길의 종료 지점에 온 경우
			dp[curIdx] = dp[curIdx - 1] + 1; //일단 직전 지점에서 오는 경우를 저장해 놓는다. 이후, 지름길을 이용하는 경우를 생각한다.
			while (curBack == curIdx) { //같은 종료 지점을 갖는 지름길이 여러 개 있을 수 있다.
				dp[curIdx] = min(dp[curIdx], dp[curFront] + curDist);

				roadIdx++; //다음 지름길로 넘어간다.
				if (roadIdx == numRoad) { //평가할 수 있는 지름길이 더 이상 없다.
					curIdx++; //이 다음 지점부터는 finale에서 책임진다.
					goto finale;
				}
				curFront = rawdata[roadIdx].front; curBack = rawdata[roadIdx].back; curDist = rawdata[roadIdx].dist;
			}

		}
	}
finale:;
	for (; curIdx <= distHighway; curIdx++) dp[curIdx] = dp[curIdx - 1] + 1; //마지막에 다 못 간 부분 보상

	cout << dp[distHighway] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}