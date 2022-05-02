#include <iostream>
#include <algorithm>
using namespace std;

int rawdata[1002], result[1002];
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;

	for (int i = 1; i <= sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void operate() {
	for (int i = 1; i <= sz_rawdata; i++) {
		result[i] = rawdata[i];
		//카드를 5개 살 경우
		//5+0 4+1 3+2를 탐색하며, 아래의 j는 더하기 뒤 숫자(0,1,2)를 의미한다.
		for (int j = 1; j <= i / 2; j++) { 
			result[i] = max(result[i], result[j] + result[i - j]);
		}
	}

	cout << result[sz_rawdata] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}