#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string initial, target;
bool direction = true; //true : 순방향, false : 역방향
int front, back;

void operate() {
	cin >> initial >> target;

	front = 0; back = target.length() - 1;
	int len_target = target.length(), len_initial = initial.length();

	while (len_target != len_initial) {
		if (direction == true) { //순방향 진행중. back 참조한다.
			if (target[back] == 'B') direction = false;
			back--;
		}
		else {
			if (target[front] == 'B') direction = true;
			front++;
		}
		len_target--;
	}

	target = target.substr(front, len_target);
	if(direction==false) reverse(target.begin(), target.end());

	if (target.compare(initial)) cout << 0 << endl;
	else cout << 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}

/*
ABA
ABBABAABAAB
ANS : 1

ABA
ABBABBABAAB
ANS : 0
*/