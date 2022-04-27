#include <iostream>
#define endl "\n"
#define MOD 1000000000
using namespace std;

int rawdata[102][10][(1 << 10) + 3] = { 0 }; //[LENGTH][LAST NUMBER][USED NUMBER]
int target_length;

void initialize() {
	cin >> target_length;
	for (int i = 1; i <= 9; i++) {
		rawdata[1][i][1 << i] = 1;
	}
}

void operate() {
	int numBelow, numAbove; //이전 len에서 마지막으로 끝난 값보다 1 작은, 1 큰 수

	for (int len = 2; len <= target_length; len++) { //현재 len
		for (int lastNum = 0; lastNum <= 9; lastNum++) { //이전 len에서 마지막으로 끝난 값
			for (int history = 0; history <= (1 << 10) - 1; history++) { //이전 len에서 사용한 숫자들에 대한 정보
				if (rawdata[len - 1][lastNum][history]) { //이전 len에서 계단수가 만들어졌을 경우
					numBelow = lastNum - 1; numAbove = lastNum + 1;

					if (lastNum != 0)
						rawdata[len][numBelow][history | 1 << numBelow] = 
						(rawdata[len][numBelow][history | 1 << numBelow] + rawdata[len - 1][lastNum][history]) % MOD;
					if (lastNum != 9) 
						rawdata[len][numAbove][history | 1 << numAbove] = 
						(rawdata[len][numAbove][history | 1 << numAbove] + rawdata[len - 1][lastNum][history]) % MOD;
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + rawdata[target_length][i][(1 << 10) - 1]) % MOD;
	}

	cout << sum << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}