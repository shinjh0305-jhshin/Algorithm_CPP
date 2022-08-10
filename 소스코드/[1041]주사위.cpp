#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define INF 2134567890
using namespace std;

string _3Side[8] = { "ADE", "ACE", "ABC", "ADB", "FDE", "FBD", "FEC", "FBC" };
string _2Side[12] = {
	"DE", "EC", "CB", "BD", "AE", "AD", "AB", "AC", "FE", "FD", "FC", "FB"
};
ll min_3side, min_2side, minblock;

ll sz_block;
ll nums[6];

void initialize() {
	cin >> sz_block;

	minblock = INF;
	for (int i = 0; i < 6; i++) {
		cin >> nums[i];
		minblock = min(minblock, nums[i]);
	}

	string temp;
	ll tempSum;

	min_3side = INF;
	for (int i = 0; i < 8; i++) {
		temp = _3Side[i];
		tempSum = 0;
		for (int j = 0; j < 3; j++) {
			tempSum += nums[temp[j] - 'A'];
		}
		min_3side = min(min_3side, tempSum);
	}

	min_2side = INF;
	for (int i = 0; i < 12; i++) {
		temp = _2Side[i];
		tempSum = 0;
		for (int j = 0; j < 2; j++) {
			tempSum += nums[temp[j] - 'A'];
		}
		min_2side = min(min_2side, tempSum);
	}
}

void operate() {
	ll ans = 0;

	if (sz_block == 1) {
		sort(nums, nums + 6);
		for (int i = 0; i < 5; i++) {
			ans += nums[i];
		}
		cout << ans << endl;
		return;
	}

	ans += ((sz_block - 2) * (sz_block - 2) * 5 + (sz_block - 2) * 4) * minblock; //1면만 보이는 부분 계산
	ans += ((sz_block - 2) * 8 + 4) * min_2side; //2면만 보이는 부분 계산
	ans += min_3side * 4; //3면만 보이는 부분 계산

	cout << ans << endl;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}