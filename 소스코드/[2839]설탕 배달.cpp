#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int target;
	cin >> target;

	int lsd = target % 10, answer = 0; //마지막에 만들 수 없는 숫자인지 판별하기 위해 0으로 초기화

	if (lsd == 0 || lsd == 5) {
		answer = target / 5;
	}
	else if (lsd == 1 || lsd == 6) {
		target -= 3 * 2; 
		if (target >= 0) answer += 2 + target / 5;
	}
	else if (lsd == 2 || lsd == 7) {
		target -= 3 * 4;
		if (target >= 0) answer += 4 + target / 5;
	}
	else if (lsd == 3 || lsd == 8) {
		target -= 3 * 1;
		if (target >= 0) answer += 1 + target / 5;
	}
	else if (lsd == 4 || lsd == 9) {
		target -= 3 * 3;
		if (target >= 0) answer += 3 + target / 5;
	}
	if (answer == 0) answer = -1;

	cout << answer << endl;
	return 0;
}