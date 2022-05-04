#include <iostream>
#include <algorithm>
#define endl "\n"
#pragma warning(disable:4996)
using namespace std;

struct info {
	int duration, price;
};

info rawdata[17];
int dp[17] = { 0 };
int days;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> days; cin.get();
	for (int i = 1; i <= days; i++) {
		cin >> rawdata[i].duration >> rawdata[i].price; cin.get();
	}
	
	int nextStart, temp, temp1, temp2;
	for (int i = days; i >= 1; i--) { //종료 지점이 명확하고, 종료 지점을 넘는 시작 지점을 선택할 수 없기에 끝에서부터 탐색한다.
		nextStart = i + rawdata[i].duration; //다음 상담을 시작할 수 있는 날

		temp1 = temp2 = 0;

		//i일에 시작하는 업무를 받을 때를 먼저 고려한다.(temp1)
		if (nextStart <= days + 1) { //i일에 시작하는 업무를 받을 수 있는지 확인
			temp1 = rawdata[i].price; temp = 0;
			for (int j = nextStart; j <= days; j++) {
				temp = max(temp, dp[j]);
			}
			temp1 += temp;
		}

		//i일에 시작하는 업무를 받지 않을 때를 고려한다.(temp2)
		for (int j = i + 1; j <= days; j++) {
			temp2 = max(temp2, dp[j]);
		}

		dp[i] = max(temp1, temp2);
	}

	cout << dp[1] << endl;

	return 0;
}