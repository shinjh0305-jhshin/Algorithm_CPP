#include <iostream>
#define ll long long
using namespace std;

int classes;
ll students[1000005];
ll head, sub; //head procter, sub procter의 인당 감시 가능 인원 수

void initialize() {
	cin >> classes;
	for (int i = 0; i < classes; i++) {
		cin >> students[i];
	}
	cin >> head >> sub;
}

void operate() {
	ll answer = 0;
	ll subProcters = 0;

	for (int i = 0; i < classes; i++) {
		ll leftstudent = students[i];
		leftstudent -= head; answer++; //총감독관 배정

		if (leftstudent > 0) { //남은 학생이 있을 경우
			subProcters = leftstudent / sub; //부감독관 배정
			if (leftstudent - subProcters * sub > 0) subProcters++; //감독할 수 없는 학생이 남아있으면, 부감독관 추가 배정
			answer += subProcters;
		}
	}

	cout << answer;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
