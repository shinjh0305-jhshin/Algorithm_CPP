#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct info {
	int adjFriend, adjEmpty;
	pair<int, int> pos;
};

struct compare {
	bool operator() (const info& a, const info& b) {
		if (a.adjFriend < b.adjFriend) return true;
		else if (a.adjFriend == b.adjFriend) {
			if (a.adjEmpty < b.adjEmpty) return true;
			else if (a.adjEmpty == b.adjEmpty) {
				if (a.pos.first > b.pos.first) return true;
				else if (a.pos.first == b.pos.first) {
					if (a.pos.second > b.pos.second) return true;
				}
			}
		}

		return false;
	}
};

int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };
int seat[22][22];
int students;
vector<vector<int>> rawdata;

priority_queue<info, vector<info>, compare> pq;

void findScore() {
	int currow, curcol, curstudent, targetstudent, love, ans = 0;

	for (int i = 0; i < students; i++) {
		for (int j = 0; j < students; j++) {
			curstudent = seat[i][j];
			love = 0;

			for (int k = 0; k < 4; k++) {
				currow = i + drow[k]; curcol = j + dcol[k];

				if (currow < 0 || currow >= students || curcol < 0 || curcol >= students) continue;

				targetstudent = seat[currow][curcol];

				if (find(rawdata[curstudent].begin(), rawdata[curstudent].end(), targetstudent) != rawdata[curstudent].end()) {
					love++;
				}
			}

			if (love) {
				ans += pow(10, love - 1);
			}
		}
	}

	cout << ans;
}

void findSeat(int curStudent) {
	int nrow, ncol, _friends, _empty;
	int curMax = -1;

	while (!pq.empty()) pq.pop();

	for (int i = 0; i < students; i++) {
		for (int j = 0; j < students; j++) {
			if (seat[i][j]) continue; //이미 누가 가져간 좌석
			_friends = _empty = 0;

			for (int k = 0; k < 4; k++) {
				nrow = i + drow[k]; ncol = j + dcol[k];
				if (nrow < 0 || nrow >= students || ncol < 0 || ncol >= students) continue;

				if (seat[nrow][ncol] == 0) _empty++;
				else if (find(rawdata[curStudent].begin(), rawdata[curStudent].end(), seat[nrow][ncol]) != rawdata[curStudent].end()) _friends++;
			}

			if (_friends > curMax) {
				while (!pq.empty()) pq.pop();
				pq.push({ _friends, _empty, { i, j } });
				curMax = _friends;
			}
			else if (_friends == curMax) {
				pq.push({ _friends, _empty, { i, j } });
			}
		}
	}

	seat[pq.top().pos.first][pq.top().pos.second] = curStudent;
}

void operate() {
	cin >> students;

	rawdata.resize(students * students + 3);

	int curStudent;
	for (int i = 0; i < students * students; i++) {
		cin >> curStudent;
		rawdata[curStudent].resize(4);

		for (int k = 0; k < 4; k++) cin >> rawdata[curStudent][k];
		
		findSeat(curStudent);
	}

	findScore();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}