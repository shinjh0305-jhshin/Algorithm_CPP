#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> duration, answer, previous; 
vector<int> previousHouse[502], afterHouse[502]; //previous : 각 집을 짓기 이전에 지어야 할 집, after : 각 집을 짓고 나서 지을 수 있는 집
queue<int> qu; //이전에 지어야 할 집이 다 지어져서 당장 지을 수 있는 집
int sz_house; //집 개수

void initialize() {
	cin >> sz_house;
	duration.resize(sz_house + 1); //각 집 한 채를 짓는 데 걸리는 시간
	answer.resize(sz_house + 1, 0); //집 한채를 짓는 데 걸리는 최종 시간
	previous.resize(sz_house + 1, 0); //각 집을 짓기 이전에 지어야 할 집의 개수

	int temp;
	for (int i = 1; i <= sz_house; i++) {
		cin >> duration[i];

		while (1) {
			cin >> temp;
			if (temp == -1) break;

			previous[i]++;
			previousHouse[i].push_back(temp);
			afterHouse[temp].push_back(i);
		}
	}

	for (int i = 1; i <= sz_house; i++) {
		if (previous[i] == 0) {
			qu.push(i);
			answer[i] = duration[i];
		}
	}
}

void operate() {
	int curHouse, nextHouses, nextHouse, temp, previousSize;

	while (!qu.empty()) {
		curHouse = qu.front(); qu.pop(); //지금 지을 수 있는 집(현재 집)

		nextHouses = afterHouse[curHouse].size(); //현재 집이 선행 조건인 집의 개수

		for (int i = 0; i < nextHouses; i++) {
			nextHouse = afterHouse[curHouse][i]; //현재 집이 선행 조건인 집

			if (--previous[nextHouse] == 0) { //선행 조건인 집들이 다 지어졌을 경우
				qu.push(nextHouse);

				temp = 0;
				previousSize = previousHouse[nextHouse].size(); //선행 조건인 집들의 개수
				for (int iter = 0; iter < previousSize; iter++) {
					temp = max(temp, answer[previousHouse[nextHouse][iter]]); //선행 조건인 집들 중 최대 소요시간을 구한다
				}
				answer[nextHouse] = temp + duration[nextHouse];
			}
		}
	}

	for (int i = 1; i <= sz_house; i++) {
		cout << answer[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
8
4 -1
2 1 -1
5 2 8 -1
8 3 -1
3 2 -1
1 3 5 -1
4 4 6 -1
28 -1

answer :
4
6
33
41
9
34
45
28
*/