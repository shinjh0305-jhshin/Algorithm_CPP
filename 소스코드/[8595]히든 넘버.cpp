#include <iostream>
#include <string>
#define ll long long
using namespace std;

void operate() {
	int lenSt;
	string st;
	cin >> lenSt >> st;

	ll answer = 0;
	for (int i = 0; i < lenSt; i++) {
		if (st[i] >= '0' && st[i] <= '9') {
			int start = i, end = i;
			while (end < lenSt && st[end] >= '0' && st[end] <= '9') {
				end++;
			}
			end--; //마지막에 더 간 부분 빼준다.

			answer += stoll(st.substr(start, end - start + 1));
			i = end;
		}
	}

	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}