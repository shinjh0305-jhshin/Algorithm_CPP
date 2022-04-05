#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	//target : 최초에 들어온 숫자  target_mov : 생성되는 숫자  target_cnt : 카운터
	int target, target_mov, target_cnt = 0;
	cin >> target;

	//udigit : 십의자리수  ldigit : 일의자리수  newldigit : 새로 생성되는 일의자리수
	int udigit, ldigit, newldigit;
	target_mov = target;

	do {
		udigit = target_mov / 10;
		ldigit = target_mov % 10;
		newldigit = (udigit + ldigit) % 10;

		target_mov = 10 * ldigit + newldigit;
		target_cnt++;
	} while (target != target_mov);

	cout << target_cnt << endl;

	return 0;
}