#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1234567890
using namespace std;

bool plugged[101] = { false };
int plugs, devices;
int rawdata[101];
priority_queue<pair<int, int>> pq;  //<다음에 나오는 곳, 이름> 순서로 적는다.

void initialize() {
	cin >> plugs >> devices;

	for (int i = 0; i < devices; i++) {
		cin >> rawdata[i];
	}
}

int getNextTime(int curPos, int curDevice) { //다음에 언제 사용하는지를 return 한다.
	int nextTime;
	for (nextTime = curPos + 1; nextTime < devices; nextTime++) {
		if (rawdata[nextTime] == curDevice) { //추후에 다시 사용 할 기기일 경우
			return nextTime;
		}
	}
	return INF; //추후에 다시 사용하지 않을 기기일 경우
}

void operate() {
	int opers = 0, nextTime, curTopDevice, curPlugged = 0;
	for (int i = 0; i < devices; i++) {
		int curDevice = rawdata[i];

		if (!plugged[curDevice] && curPlugged >= plugs) { //꽂혀 있지 않은 기기이며, 다른 기기를 빼야 할 경우
			curTopDevice = pq.top().second; pq.pop();
			plugged[curTopDevice] = false; //다른 기기를 뺀다.
			opers++; //뺀 횟수 증가
		}

		//현재 기기를 꽂는다.
		//이미 꽂힌 기기일 경우, 다음에 나올 위치를 pq에 저장하기 위해 이 과정을 진행한다.
		//현재 자신의 위치 역시 pq에 남아 있으나, maxHeap이기에 상관 없으며, 데이터 양도 적기에 무시해도 된다.

		if (!plugged[curDevice] && curPlugged < plugs) curPlugged++; //꽂혀 있지 않은 기기이며, 아직 플러그가 남은 경우
		nextTime = getNextTime(i, curDevice); //다음에 이 기기를 사용하는 시점을 가져온다.
		pq.push({ nextTime, curDevice });
		plugged[curDevice] = true; //현재 기기는 플러그에 꽂혀 있음
	}
	
	cout << opers << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
3 8
1 3 4 2 1 2 3 4
ans : 2

3 9
1 2 3 2 4 3 4 5 2
ans : 2

3 9
1 2 3 4 1 3 4 2 1
ans : 2

1 9
1 2 3 4 5 6 7 8 9
ans : 8

3 14
1 4 3 2 5 4 3 2 5 3 4 2 3 4
ans : 4
*/