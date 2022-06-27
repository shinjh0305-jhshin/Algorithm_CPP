#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> inOrder;
int outOrder[1003];
int cars;

void operate() {
	cin >> cars;

	string temp;
	for (int i = 0; i < cars; i++) {
		cin >> temp;
		inOrder[temp] = i;
	}

	for (int i = 0; i < cars; i++) {
		cin >> temp;
		outOrder[i] = inOrder[temp];
	}

	int ans = 0;
	for (int i = 0; i < cars - 1; i++) {
		for (int j = i + 1; j < cars; j++) {
			if (outOrder[i] > outOrder[j]) { //나(i) 이후에 나온 차 중에서 나보다 먼저 들어간 차가 있는지 확인!
				ans++;
				break;
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