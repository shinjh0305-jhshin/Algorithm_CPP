#include <iostream>
#include <string>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

string rawdata;
int N, sz_rawdata;

void initialize() {
	cin >> N >> sz_rawdata; cin.get();
	getline(cin, rawdata);
}

void find_target(int& idx, int& ans) {
	int found_N = 0; //현재 시작점에서 찾을 수 있는 가장 긴 PN의 길이값
	while (idx < sz_rawdata) {
		if (rawdata[idx + 1] == 'O' && rawdata[idx + 2] == 'I') {
			found_N++;
			idx += 2;
		}
		else break;
	}

	if (found_N >= N) ans += (found_N + 1) - N;
}

void operate() {
	int idx = 0, ans = 0;

	for (idx = 0; idx < sz_rawdata; idx++) {
		if (rawdata[idx] == 'O') continue;

		find_target(idx, ans);
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
/*
2
21
OOIIOIOIIIOIOIIOIOIOI

*/