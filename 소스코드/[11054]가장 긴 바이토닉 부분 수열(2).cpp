#include <iostream>
#include <algorithm>
using namespace std;

//toLeft : 오른쪽에서 시작하는 LIS에 대한 정보
//toRight : 왼쪽에서 시작하는 LIS에 대한 정보
//workspace : LIS를 구하면서 사용할 작업 공간
int rawdata[1003], toLeft[1003], toRight[1003], workspace[1003];
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void make_forward() { //LIS를 오른쪽으로 가는 방향으로 구한다.
	int idx = 0;
	workspace[0] = rawdata[0];
	toRight[0] = 1;

	for (int i = 1; i < sz_rawdata; i++) {
		if (rawdata[i] > workspace[idx]) {
			workspace[++idx] = rawdata[i];
			toRight[i] = idx + 1;
		}
		else {
			auto it = lower_bound(workspace, workspace + idx, rawdata[i]);
			*it = rawdata[i];
			toRight[i] = it - workspace + 1;
		}
	}
}

void make_backward() { //LIS를 왼쪽으로 가는 방향으로 구한다.
	int idx = 0;
	workspace[0] = rawdata[sz_rawdata - 1];
	toLeft[sz_rawdata - 1] = 1;

	for (int i = sz_rawdata - 2; i >= 0; i--) {
		if (rawdata[i] > workspace[idx]) {
			workspace[++idx] = rawdata[i];
			toLeft[i] = idx + 1;
		}
		else {
			auto it = lower_bound(workspace, workspace + idx, rawdata[i]);
			*it = rawdata[i];
			toLeft[i] = it - workspace + 1;
		}
	}
}
void operate() {
	//순방향, 역방향 각각에 대해 LIS를 구하고 그 합이 가장 큰 수열을 고른다.
	make_forward();
	make_backward();

	int result = -1;
	for (int i = 0; i < sz_rawdata; i++) {
		result = max(result, toRight[i] + toLeft[i]);
	}
	cout << result - 1 << endl; //가운데 숫자가 두 번 들어가서 한 번 빼준다.
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}