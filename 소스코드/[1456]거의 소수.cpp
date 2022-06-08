#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10000000
#define ll long long
using namespace std;

bool checked[10000002];
ll from, to;

void operate() {
	cin >> from >> to;

	memset(checked, true, sizeof(checked));

	int temp, i;
	for (i = 2; i*i <= MAX; i++) {
		if (checked[i]) {
			for (int j = 2;; j++) {
				temp = i * j;
				if (temp > MAX) break;
				checked[temp] = false;
			}
		}
	}

	ll tempNum, ans = 0;
	for (i = 2; i <= MAX; i++) {
		if (i * i > to) break; //제곱이 최댓값을 넘어간다.

		if (checked[i]) {
			tempNum = i;
			while (i <= to / tempNum) {
				if (i * tempNum >= from) {
					ans++;
				}
				tempNum *= i;
			}
		}
	}

	cout << ans << endl;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}