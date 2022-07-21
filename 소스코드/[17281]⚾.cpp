#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int innings;
int playerResult[52][12];
int maxScore = 0;
vector<int> tempOrder(8);

void initialize() {
	cin >> innings;
	for (int i = 1; i <= innings; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> playerResult[i][j];
		}
	}

	for (int i = 2; i <= 9; i++) {
		tempOrder[i - 2] = i;
	}
}

void gameStart(vector<int>& playerOrder) {
	int outs, R = 0, curHitter = playerOrder[1], curResult;
	int hitterIdx = 1;
	bool onBase[4] = { false };

	for (int curInning = 1; curInning <= innings; curInning++) {
		outs = 0;
		memset(onBase, false, sizeof(onBase));

		while (outs != 3) {
			curResult = playerResult[curInning][curHitter];
			if (curResult == 1) { //안타
				R += onBase[3];
				onBase[3] = onBase[2]; onBase[2] = onBase[1]; onBase[1] = true;
			} 
			else if (curResult == 2) { //2루타
				R += (onBase[3] + onBase[2]);
				onBase[3] = onBase[1]; onBase[2] = true; onBase[1] = false;
			}
			else if (curResult == 3) { //3루타
				R += (onBase[3] + onBase[2] + onBase[1]);
				onBase[3] = true; onBase[2] = onBase[1] = false;
			}
			else if (curResult == 4) { //HR
				R += (onBase[3] + onBase[2] + onBase[1] + true); 
				onBase[3] = onBase[2] = onBase[1] = false;
			}
			else {
				outs++;
			}

			hitterIdx = hitterIdx == 9 ? 1 : hitterIdx + 1;
			curHitter = playerOrder[hitterIdx];
		}
	}

	maxScore = max(maxScore, R);
}

void operate() {
	vector<int> playerOrder(10);
	do {
		for (int pOrder = 1, tOrder = 0; pOrder <= 9; pOrder++) {
			if (pOrder == 4) {
				playerOrder[4] = 1;
			}
			else {
				playerOrder[pOrder] = tempOrder[tOrder];
				tOrder++;
			}
		}
		gameStart(playerOrder);
	} while (next_permutation(tempOrder.begin(), tempOrder.end()));

	cout << maxScore << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}