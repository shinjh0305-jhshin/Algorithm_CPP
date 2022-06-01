#include <iostream>
#include <algorithm>
using namespace std;

int spendings[100003];
int days, withdraws;

void operate() {
	cin >> days >> withdraws;

	int left = -1234567890, right = 0, mid;
	for (int i = 0; i < days; i++) {
		cin >> spendings[i];

		right += spendings[i];
		left = max(left, spendings[i]);
	}

	while (left < right) {
		mid = (left + right) / 2;

		int cnt = 1, balance = mid;
		for (int i = 0; i < days; i++) {
			if (balance < spendings[i]) {
				balance = mid;
				cnt++;
			} 
			balance -= spendings[i];
		}

		if (cnt <= withdraws) right = mid; //인출 횟수가 목표보다 적기에, 더 조금씩 인출해서 더 자주 인출해야 한다.
		else left = mid + 1; //인출 횟수가 목표보다 많기에, 더 많이 인출해서 더 뜸하게 인출해야 한다.
	}

	cout << left << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}