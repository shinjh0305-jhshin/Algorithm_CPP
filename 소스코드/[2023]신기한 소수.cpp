#include <iostream>
#include <algorithm>
using namespace std;

int targetLen;

bool isPrime(int num) {
	for (int i = 2; i * i <= num; i++) { //소수 판정 시스템. 1이 num에 올 수 있으면, 1은 예외처리!
		if (num % i == 0) return false;
	}
	return true;
}

void makePrime(int len, int num) {
	if (len == targetLen) cout << num << endl;
	//1
	if (isPrime(num * 10 + 1)) makePrime(len + 1, num * 10 + 1);
	//3
	if (isPrime(num * 10 + 3)) makePrime(len + 1, num * 10 + 3);
	//7
	if (isPrime(num * 10 + 7)) makePrime(len + 1, num * 10 + 7);
	//9
	if (isPrime(num * 10 + 9)) makePrime(len + 1, num * 10 + 9);
}

void operate() {
	cin >> targetLen;

	//2
	makePrime(1, 2);
	//3
	makePrime(1, 3);
	//5
	makePrime(1, 5);
	//7
	makePrime(1, 7);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}