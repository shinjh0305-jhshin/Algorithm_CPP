#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#define UNVISITED -1
#define ll long long
using namespace std;

//dp[i][j] : i�� ���Ե� ���ڵ��� ����߰�, mod�� ���� ���ڰ� ������� j�� ��, ���� ���� ����ؼ� ������ִ� mod�� ������������ ������ ����
ll dp[1 << 15][105]; 
int mod10[55]; //10^i�� mod�� ���� ������
pair<int, int> num[22]; //���ڸ� mod�� ���� ������, ������ ����
string rawdata[22];

int sz_rawdata, mod;
ll possiblePerm = 1; //������ ������ ���� ����

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
		possiblePerm *= (i + 1);
	}
	cin >> mod;

	//10^n�� mod�� ���� �������� ���� �����͸� ���� �� ���س���.
	mod10[0] = 1 % mod;
	for (int i = 1; i <= 50; i++) {
		mod10[i] = (mod10[i - 1] * 10) % mod;
	}

	//�� ������ ���̴� 50 �̻��̱⿡(int ���� ���), �� ������ �������� ���۾����� ���Ѵ�.
	for (int i = 0; i < sz_rawdata; i++) {
		num[i].second = rawdata[i].length();
		
		reverse(rawdata[i].begin(), rawdata[i].end());

		for (int j = 0; j < num[i].second; j++) {
			num[i].first += ((rawdata[i][j] - '0') * mod10[j]) % mod;
		}
		num[i].first %= mod;
	}

	memset(dp, UNVISITED, sizeof(dp));
}

ll findDP(int visited, int curNum) {
	if (visited == (1 << sz_rawdata) - 1) return (curNum % mod == 0);

	if (dp[visited][curNum] != UNVISITED) return dp[visited][curNum];

	ll ret = 0;
	int nextNum;
	for (int i = 0; i < sz_rawdata; i++) {
		if (visited & (1 << i)) continue; //i��° ���� �湮��

		nextNum = curNum * mod10[num[i].second] + num[i].first;
		nextNum %= mod;

		ret += findDP(visited | (1 << i), nextNum);
	}

	return dp[visited][curNum] = ret;
}

void operate() {
	ll ans = findDP(0, 0);
	ll div = gcd(ans, possiblePerm);

	cout << ans / div << '/' << possiblePerm / div << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}