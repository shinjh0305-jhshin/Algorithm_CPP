#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

bool dp[2002][2002] = { false };
vector<int> rawdata;
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	for (int i = 0; i < sz_rawdata; i++) {
		dp[i][i] = true; //길이가 1인 수열은 무조건 팰린드롬이다
		if (i < sz_rawdata - 1 && rawdata[i] == rawdata[i + 1]) {
			dp[i][i + 1] = true; //길이가 2인 수열에 대한 판별
		}
	}

	int st;
	for (int sz = 2; sz <= sz_rawdata - 1; sz++) { //수열의 길이 순서로 팰린드롬 판별을 진행한다.
		for (int fin = sz; fin <= sz_rawdata-1; fin++) { //수열의 종료 지점
			st = fin - sz; //수열의 시작 지점
			if (rawdata[st] == rawdata[fin] && dp[st + 1][fin - 1]) { //양 끝단이 같은 값이며, 중간이 팰린드롬일경우, 전체가 팰린드롬이다.
				dp[st][fin] = true;
			}
		}
	}
}

void operate() {
	int query, to, from;
	cin >> query;

	for (int i = 0; i < query; i++) {
		cin >> to >> from;
		cout <<	dp[to - 1][from - 1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}