#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int operate(int target) {
	int result = 99;
	int d100; //100의 자릿수

	d100 = target / 100; 

	for (int i = 1; i <= d100; i++) { //100의 자리가 target의 백의 자리보다 작을 때 까지 진행
		for (int j = 0;; j++) { //오르는 수열 확인

			if (i + j >= 10 || i + j + j >= 10) break; //10의 자리 1의 자리 중 하나라도 조건 미충족

			if (i < d100) result++;
			else if (d100 * 100 + (i + j) * 10 + (i + j + j) <= target) result++;
		}

		for (int j = -1;; j--) {//내리는 수열 확인
			if (i + j < 0 || i + j + j < 0) break; //10의 자리 1의 자리 중 하나라도 조건 미충족

			if (i < d100) result++;
			else if (d100 * 100 + (i + j) * 10 + (i + j + j) <= target) result++; 
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	if (num < 100) cout << num << endl;
	else cout << operate(num) << endl;

	return 0;
}