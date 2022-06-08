#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int num; //주석에서는 크기가 4인 순열을 예로 설명
bool used[21] = { false };

int getNum(int target) { //target번째 이용 가능한 숫자를 돌려준다
	for (int i = 1; i <= num; i++) {
		if (!used[i]) {
			target--;
			if (target == 0) {
				used[i] = true;
				return i;
			} 
		} 

	}
}

ll numBefore(int target) { //target 나오기 이전에 몇 개의 이용 가능한 숫자가 있는지
	ll ret = 0;
	for (int i = 1; i < target; i++) {
		if (!used[i]) {
			ret++;
		}
	}
	used[target] = true;
	return ret;
}

ll fact(int num) {
	if (num <= 1) return 1;
	return num * fact(num - 1);
}

void operate() {
	int typeOp, numtoGet;
	ll target, div;
	cin >> num >> typeOp;

	div = fact(num); //4!을 구한다

	if (typeOp == 1) { //순열을 구하자
		cin >> target; //몇 번째?

		for (int i = num; i > 0; i--) {
			div /= i; //4개 숫자로 만드는 순열은 4 * 3!이므로 3!에서 시작한다

			numtoGet = target / div; //3!이 몇 번 들어갈 수 있는가
			if(target % div) numtoGet++; //나머지가 있을 경우

			cout << getNum(numtoGet) << ' ';

			target -= div * (numtoGet - 1);
		}
		cout << endl;
	}

	else {
		ll ans = 0;
		for (int i = num; i > 0; i--) {
			cin >> target;
			div /= i;

			ans += numBefore(target)*div;
		}
		cout << ans + 1 << endl;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}

/*
4
2 2 3 4 1

10
1 124578
1 5 2 9 3 4 8 10 7 6
*/