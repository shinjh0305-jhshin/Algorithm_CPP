#include <iostream>
#include <algorithm>
using namespace std;

int horse[4] = { 0,0,0,0 }; //score의 index를 저장한다. score 값 저장하는거 아니다.
int dice[10];
int score[35], nextidx[35];
bool horseExist[36] = { false };

void initialize() {
	for (int i = 0; i <= 20; i++) { //외곽 맵 그린다
		score[i] = i * 2;
	}

	score[21] = 13; score[22] = 16; score[23] = 19; //10분기
	score[24] = 22; score[25] = 24;	//20분기
	score[26] = 28;	score[27] = 27; score[28] = 26;	//30분기
	score[29] = 25; score[30] = 30;	score[31] = 35; score[32] = 40; //25에서 40

	for (int i = 0; i < 35; i++) nextidx[i] = i + 1;

	nextidx[5] = 21; nextidx[10] = 24; nextidx[15] = 26; //10, 20, 30처리
	nextidx[19] = 32; //38처리
	nextidx[23] = nextidx[25] = 29; //25처리

	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
} 

int DFS(int idx) { //idx : dice index
	int curDice = dice[idx];
	int maxScore = 0, curScore;

	int curLoc, nextLoc;

	for (int i = 0; i < 4; i++) {
		curLoc = horse[i];

		if (curLoc == -1) continue;
		
		curScore = 0;

		if (curLoc <= 20 && curLoc != 5 && curLoc != 10 && curLoc != 15) { //외곽을 달리는 말
			nextLoc = curLoc + curDice;

			if (nextLoc > 20) { //말이 났다
				horse[i] = -1;
				horseExist[curLoc] = false;
				nextLoc = 0; //backtracking을 위한 임의 값 지정
			}
			else {
				if (nextLoc == 20) nextLoc = 32; //40으로 간다

				if (horseExist[nextLoc]) continue; //가려는 곳에 말이 있다.
				else { //말이 갈 수 있는 곳이다.
					curScore = score[nextLoc];
					horse[i] = nextLoc;
					horseExist[curLoc] = false;
					horseExist[nextLoc] = true;
				}
			}
		}
		else {
			nextLoc = curLoc;
			for (int j = 0; j < curDice; j++) {
				nextLoc = nextidx[nextLoc];

				if (nextLoc == 33) break; //말이 났다.
			}

			if (nextLoc == 33) { //말이 났다
				horse[i] = -1;
				horseExist[curLoc] = false; //이전 위치에서 말을 삭제한다
			}
			else if (horseExist[nextLoc]) continue; //가려는 위치에 말이 있다.
			else {
				curScore = score[nextLoc];
				horse[i] = nextLoc; //다음 위치에 말을 둔다.
				horseExist[nextLoc] = true;
				horseExist[curLoc] = false; //이전 위치에서 말을 삭제한다
			}
		}

		if (idx < 9) curScore += DFS(idx + 1);
		maxScore = max(maxScore, curScore);

		horse[i] = curLoc; //backtracking
		horseExist[nextLoc] = false;
		horseExist[curLoc] = true;

	}

	return maxScore;
}


void operate() {
	cout << DFS(0) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}