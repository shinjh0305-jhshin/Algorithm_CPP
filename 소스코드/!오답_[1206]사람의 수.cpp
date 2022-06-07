#include <iostream>
#include <cmath>
#include <vector>
#define err 0.001
using namespace std;

double rawdata[52];
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void operate() {
	bool status;
	for (int i = 1; i < 1000; i++) { //사람 수
		status = true;
		for (int j = 0; j < sz_rawdata; j++) { //평균값
			double temp = rawdata[j] * i; //이번 사람 수 기준 점수 합
			double nextTemp = rawdata[j] * (i + 1); //다음 사람 수 기준 점수 합

			if (temp - (int)temp < 0.00000001) continue; //정수일 경우
			else {
				if ((int)nextTemp - (int)temp >= 1) { //이번 사람 수 안에서 숫자가 바뀐 경우. 즉, 다음 사람 수 기준 점수 합의 정수 부분이 존재.
					if ((double)((int)temp + 1) / i - rawdata[j] < err) continue; //소숫점 셋째 자리 이하에서 바뀐 경우
				}
				status = false;
				break;
			}
		}

		if (status == true) {
			cout << i << endl;
			return;
		}
	}

	cout << 1000 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}