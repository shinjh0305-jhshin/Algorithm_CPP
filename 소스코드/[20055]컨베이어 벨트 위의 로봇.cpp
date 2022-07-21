/*
프로세스
1. 올리는 위치, 내리는 위치 한 칸씩 움직이며 업데이트
2. 로봇이 한 칸 이동할 수 있는지 검토
3. 올리는 위치에 올릴 수 있으면 로봇 올리기
4. 내구도가 0인 칸이 K 개 이상이면 종료
*/

#include <iostream>
#include <deque>
using namespace std;

int belts, target;
int capa[205]; //각 칸의 내구도(시작:1)
int goUp = 1, goDown; //올리고 내리는 위치
deque<int> robots; //robot 위치
bool hasRobot[205] = { false };

void initialize() {
	cin >> belts >> target;
	goDown = belts;

	for (int i = 1; i <= 2 * belts; i++) {
		cin >> capa[i];
	}
}

void operate() {
	int nullCapa = 0; //내구도가 0인 칸의 개수
	int op = 1;

	while (1) {
		//phase 1 : update goup godown
		goUp = goUp - 1 == 0 ? 2 * belts : goUp - 1;
		goDown = goDown - 1 == 0 ? 2 * belts : goDown - 1;

		//phase2 : move robot
		//맨 앞 로봇이 내리는 위치에 갔는지 확인한다
		if (!robots.empty() && robots[0] == goDown) {
			hasRobot[goDown] = false;
			robots.pop_front();
		}

		//처음 드간 로봇부터 한 칸씩 움직인다
		int nextPos;
		for (auto& it : robots) {
			nextPos = it + 1 > 2 * belts ? 1 : it + 1;
			if (!hasRobot[nextPos] && capa[nextPos]) {
				hasRobot[it] = false;
				it = nextPos;
				hasRobot[nextPos] = true;
				capa[nextPos]--;

				if (capa[nextPos] == 0) nullCapa++;
			}
		}

		//로봇 이동 후맨 앞 로봇이 내리는 위치에 갔는지 확인한다.
		if (!robots.empty() && robots[0] == goDown) {
			hasRobot[goDown] = false;
			robots.pop_front();
		}

		//phase3 : new robot
		if (capa[goUp]) {
			robots.push_back(goUp);
			hasRobot[goUp] = true;
			capa[goUp]--;

			if (capa[goUp] == 0) nullCapa++;
		}

		if (nullCapa >= target) {
			cout << op << endl;
			return;
		}
		op++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}