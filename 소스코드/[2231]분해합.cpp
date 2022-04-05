#include <iostream>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int key;//생성자
	int result;//분해합
};

info answer[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int target;

	cin >> target; //분해합

	for (int i = 1; i <= target; i++) {
		answer[i].key = answer[i].result = i; 
		
		answer[i].result += i % 10;
		if (i >= 10) {
			answer[i].result += (i % 100 - i % 10) / 10;
			if (i >= 100) {
				answer[i].result += (i % 1000 - i % 100) / 100;
				if (i >= 1000) {
					answer[i].result += (i % 10000 - i % 1000) / 1000;
					if (i >= 10000) {
						answer[i].result += (i % 100000 - i % 10000) / 10000;
						if (i >= 100000) {
							answer[i].result += (i % 1000000 - i % 100000) / 100000;
							if (i == 1000000) answer[i].result += 1;
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= target; i++) {
		if (answer[i].result == target) {
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;
	return 0;
}