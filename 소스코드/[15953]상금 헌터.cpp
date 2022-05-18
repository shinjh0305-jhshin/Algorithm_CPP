#include <iostream>
using namespace std;

int getFirstMoney(int num) {
	if (num == 0) return 0;
	else if (num <= 1) return 5000000;
	else if (num <= 1 + 2) return 3000000;
	else if (num <= 1 + 2 + 3) return 2000000;
	else if (num <= 1 + 2 + 3 + 4) return 500000;
	else if (num <= 1 + 2 + 3 + 4 + 5) return 300000;
	else if (num <= 1 + 2 + 3 + 4 + 5 + 6) return 100000;
	else return 0;
}
int getSecondMoney(int num) {
	if (num == 0) return 0;
	if (num <= 1) return 5120000;
	else if (num <= 1 + 2) return 2560000;
	else if (num <= 1 + 2 + 4) return 1280000;
	else if (num <= 1 + 2 + 4 + 8) return 640000;
	else if (num <= 1 + 2 + 4 + 8 + 16) return 320000;
	else return 0;
}

void operate() {
	int query, rank1, rank2;
	cin >> query;

	for (int i = 0; i < query; i++) {
		cin >> rank1 >> rank2;
		cout << getFirstMoney(rank1) + getSecondMoney(rank2) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}