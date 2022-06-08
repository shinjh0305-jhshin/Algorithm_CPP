#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 2000000
using namespace std;

bool isPrime[2000003];
int num;

void initialize() { 
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false;

	int temp;
	for (int i = 2; i * i <= MAX; i++) {
		if (isPrime[i]) {
			for (int j = 2;; j++) {
				temp = i * j;
				if (temp > MAX) break;
				isPrime[temp] = false;
			}
		}
	}

	cin >> num;
}

void operate() {
	bool isPalin;
	int left, right;
	string st;

	for (int idx = num;; idx++) {
		if (isPrime[idx]) {
			isPalin = true;
			st = to_string(idx);
			left = 0; right = st.length() - 1;

			while (left <= right) {
				if (st[left] != st[right]) {
					isPalin = false;
					break;
				}
				left++; right--;
			}
			if (isPalin) {
				cout << idx << endl;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}