#include <iostream>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class wine_tasting {
private:
	int num_wine;
	int rawdata[10005][3]; 
	int wine_qty[10005];

public:
	void initialize() {
		cin >> num_wine;
		for (int i = 1; i <= num_wine; i++) {
			cin >> wine_qty[i];
		}

		rawdata[1][0] = 0; //이번 와인을 안 먹는 경우
		rawdata[1][1] = wine_qty[1]; //이번 와인을 먹고 이전 와인을 안 먹는 경우(1번 연속)
		rawdata[1][2] = 0; //이번 와인을 먹고 이전 와인도 먹는 경우(2번 연속)
	}

	void drink_wine() {
		for (int i = 2; i <= num_wine; i++) {
			//이번 와인을 안 먹는 경우, 이전 와인의 경우의 수 중 최댓값을 가져온다
			rawdata[i][0] = max(rawdata[i - 1][0], rawdata[i - 1][1]);
			rawdata[i][0] = max(rawdata[i][0], rawdata[i - 1][2]);

			//이번 와인을 먹고 이전 와인을 안 먹는 경우, 이전 와인을 안 먹은 경우의 값을 가져온다.
			rawdata[i][1] = rawdata[i - 1][0] + wine_qty[i];

			//이번 와인을 먹고 이전 와인도 먹는 경우, 이전 와인을 1번 연속으로 먹은 경우의 값을 가져온다.
			rawdata[i][2] = rawdata[i - 1][1] + wine_qty[i];
		}
	}

	void print_max() {
		int wine_max = max(rawdata[num_wine][0], rawdata[num_wine][1]);
		wine_max = max(wine_max, rawdata[num_wine][2]);

		cout << wine_max << endl;
	}
};

int main() {
	wine_tasting op;
	op.initialize();
	op.drink_wine();
	op.print_max();
	return 0;
}