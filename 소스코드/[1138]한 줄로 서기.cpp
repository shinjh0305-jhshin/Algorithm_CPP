#include <iostream>
using namespace std;

int ppls;
int order[13];
int result[13];

void initialize() {
	cin >> ppls;
	for (int i = 1; i <= ppls; i++) {
		cin >> order[i];
	}
}

void operate() {
	int cnt;
	for (int i = 1; i <= ppls; i++) {
		cnt = 0;
		for (int j = 1; j <= ppls; j++) { //result traverse
			if (result[j] == 0) {
				if (cnt == order[i]) {
					result[j] = i;
					break;
				}
				else cnt++;
			}
		}
	}

	for (int i = 1; i <= ppls; i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}