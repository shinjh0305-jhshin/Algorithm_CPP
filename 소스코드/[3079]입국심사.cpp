#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll desks, ppls;
ll duration[100003];

void operate() {
	ll left = 0, right = 0, mid;

	cin >> desks >> ppls;
	for (int i = 0; i < desks; i++) {
		cin >> duration[i];
		right = max(right, duration[i]);
	}
	right *= ppls / desks + 1; //최댓값 : 모든 사람이 아무 고려 없이 모든 데스크에 골고루 뿌려진다.

	ll pplCapa;
	while (left < right) {
		mid = (left + right) / 2; //단위 : 시간
		pplCapa = 0; //mid분 동안 처리할 수 있는 총 사람의 명수

		for (int i = 0; i < desks; i++) {
			pplCapa += mid / duration[i];
		}

		if (pplCapa >= ppls) right = mid;
		else left = mid + 1;
	}

	cout << left << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}