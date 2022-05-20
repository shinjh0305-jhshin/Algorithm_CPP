#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string st;
int stLen, ans = -(1 << 31);

void initialize() {
	cin >> stLen >> st;
}

int calc(int num1, int num2, char op) {
	if (op == '+') return num1 + num2;
	else if (op == '-') return num1 - num2;
	else if (op == '*') return num1 * num2;
	else {
		cout << "INDEX ERROR" << endl; //for debugging
		return 0;
	}
}

void makeChoice(int resultBefore, int idx) {
	char currentOp = idx == 0 ? '+' : st[idx - 1];

	if (idx >= stLen) { //index가 범위 밖으로 나간 경우
		ans = max(ans, resultBefore);
		return;
	}

	//괄호는 index(index는 항상 숫자와 매칭됨)을 기준으로 뒷 숫자와 묶는다
	//1. 괄호를 만들지 않을 때
	int Y = calc(resultBefore, st[idx] - '0', currentOp); //이전 숫자랑 현 숫자랑 계산한다
	makeChoice(Y, idx + 2); //바로 다음 숫자로 넘어간다

	//2. 괄호를 만들 때
	if (idx != stLen - 1) { //맨 마지막 숫자는 괄호를 만들 다음 숫자가 없다
		Y = calc(st[idx] - '0', st[idx + 2] - '0', st[idx + 1]); //괄호 안의 숫자를 계산한다
		int Z = calc(resultBefore, Y, currentOp); //이전 숫자랑 괄호 내부 계산 결과랑 계산한다
		makeChoice(Z, idx + 4); //다음 다음 숫자로 넘어간다.
	}

}

void operate() {
	makeChoice(0, 0);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}