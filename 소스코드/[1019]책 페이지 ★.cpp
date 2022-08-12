#include <iostream>
using namespace std;

int targetNum, startNum;
int ans[10];
int pow10 = 1;

void calcNum(int& num, int target) {
	int temp;
	while (num % 10 != target && startNum <= targetNum) {
		temp = num;
		while (temp > 0) {
			ans[temp % 10] += pow10;
			temp /= 10;
		}
		if (&num == &startNum) num++;
		else num--;
	}
}

void operate() {
	cin >> targetNum;

	startNum = 1;

	while (startNum <= targetNum)  {
		if (targetNum % 10 != 9) {
			calcNum(targetNum, 9);
		}

		if (targetNum < startNum) break;

		if (startNum % 10 != 0) {
			calcNum(startNum, 0);
		}

		targetNum /= 10;
		startNum /= 10;

		for (int i = 0; i < 10; i++) {
			ans[i] += (targetNum - startNum + 1) * pow10;
		}

		pow10 *= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << ans[i] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}