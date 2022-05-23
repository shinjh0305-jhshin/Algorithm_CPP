#include <iostream>
#define endl "\n"
using namespace std;

int low, up;
bool check[1000003];

void initialize() {
	cin >> low >> up;
	for (int i = 1; i <= up; i++) check[i] = true;
	check[1] = false;
}

void operate() {
	int temp;
	for (int i = 2; i * i <= up; i++) {
		if (!check[i]) continue; //소수가 아닌 수
		for (int mul = 2;; mul++) {
			temp = i * mul;
			if (temp > up) break;
			if (check[temp] == true) check[temp] = false;
		}
	}

	for (int i = low; i <= up; i++) {
		if (check[i] == true) cout << i << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}