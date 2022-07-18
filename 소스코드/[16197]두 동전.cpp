#include <iostream>
#include <algorithm>
#define BLANK '.'
#define WALL '#'
#define COIN 'o'
#define INF 1234567890
using namespace std;

int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

pair<int, int> coins[2];
char map[21][21];
int rows, cols, answer = INF;

void initialize() {
	cin >> rows >> cols; cin.get();

	int coinTemp = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = cin.get();
			if (map[i][j] == COIN) {
				coins[coinTemp++] = { i,j };
				map[i][j] = BLANK; //동전 위치도 이동 편리를 위해 빈 칸으로 간주한다.
			}
		}
		cin.get();
	}
}

void DFS(int depth) {
	if (depth >= answer || depth > 10) return; //동전 이동 횟수가 이미 구한 최솟값보다 크거나 같은 경우

	pair<int, int> coinsTemp[2]; //동전의 이전 위치 저장
	for (int i = 0; i < 2; i++) {
		coinsTemp[i].first = coins[i].first;
		coinsTemp[i].second = coins[i].second;
	}

	int coinOut; // 떨어진 동전의 개수
	int temprow, tempcol;
	for (int j = 0; j < 4; j++) { 
		coinOut = 0;
		for (int i = 0; i < 2; i++) { //동전 2개 움직인다
			temprow = coinsTemp[i].first + drow[j];
			tempcol = coinsTemp[i].second + dcol[j];

			if (temprow < 0 || temprow >= rows || tempcol < 0 || tempcol >= cols) { //떨어진다
				coinOut++;
			}
			else if (map[temprow][tempcol] == WALL) { //벽이다
				coins[i] = { temprow - drow[j], tempcol - dcol[j] }; //이전 위치 담는다
			}
			else { //빈칸이다
				coins[i] = { temprow, tempcol }; //새로운 위치 담는다
			}
		}

		if (coinOut == 2) continue;
		else if (coinOut == 1) { //동전 1개만 떨어진 경우
			answer = min(answer, depth);
			//원상복귀 후 return
			return;
		}
		else { //떨어진 동전이 없는 경우
			DFS(depth + 1);
		}
	}

}

void operate() {
	DFS(1);

	if (answer == INF) cout << -1 << endl;
	else cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}