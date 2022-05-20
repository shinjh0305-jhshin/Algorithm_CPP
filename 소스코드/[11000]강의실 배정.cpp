#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> rawdata; //강의 시작시각, 종료시각에 대한 정보
priority_queue<int, vector<int>, greater<int>> classList; //각 강의실의 종료 시각 저장
int lectures;

void initialize() {
	cin >> lectures;
	rawdata.resize(lectures);

	for (int i = 0; i < lectures; i++) {
		cin >> rawdata[i].first >> rawdata[i].second;
	}

	sort(rawdata.begin(), rawdata.end());
}

void operate() {
	int timeEnd, timeStart; //각 수업 별 시작 및 종료 시각

	classList.push(rawdata[0].second); //첫 수업은 넣고 시작한다.
	for (int i = 1; i < lectures; i++) {
		timeStart = rawdata[i].first; timeEnd = rawdata[i].second;

		if (classList.top() <= timeStart) classList.pop(); //기존 수업 종료
		classList.push(timeEnd); //새로운 수업 넣는다
	}
	cout << classList.size() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
11
1 3
3 5
5 6
6 7
7 11
2 4
4 5
6 8
11 13
3 6
6 12
*/