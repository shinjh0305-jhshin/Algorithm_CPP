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

		rawdata[1][0] = 0;
		rawdata[1][1] = wine_qty[1];
		rawdata[1][2] = 0;
	}

	void drink_wine() {
		for (int i = 2; i <= num_wine; i++) {
			//0번 연속으로 와인을 마시는 경우
			rawdata[i][0] = max(rawdata[i - 1][0], rawdata[i - 1][1]);
			rawdata[i][0] = max(rawdata[i][0], rawdata[i - 1][2]);

			//1번 연속으로 와인을 마시는 경우
			rawdata[i][1] = rawdata[i - 1][0] + wine_qty[i];

			//2번 연속으로 와인을 마시는 경우
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