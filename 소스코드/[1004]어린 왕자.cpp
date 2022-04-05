#include <iostream>
#include <cmath>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class b664 {
private:
	short x1, x2, y1, y2;
	int cases;

public:
	void initialize() {
		cin >> cases; cin.get();
	}

	void operate() {
		short cx, cy, circles, result, temp;
		double r;
		
		for (int i = 0; i < cases; i++) {
			result = 0;

			cin >> x1 >> y1 >> x2 >> y2; cin.get();
			cin >> circles; cin.get();

			for (int j = 0; j < circles; j++) {
				temp = 0;

				cin >> cx >> cy >> r; cin.get();

				//출발점~원의 중심이 반지름보다 작은 경우에는 포함한다.
				if (sqrt(pow(cx - x1, 2) + pow(cy - y1, 2)) < r) temp++;
				//도착점~원의 중심이 반지름보다 작은 경우에는 포함한다.
				if (sqrt(pow(cx - x2, 2) + pow(cy - y2, 2)) < r) temp++;

				//큰 원 안에 출/도착점이 모두 존재하는 경우, 이 원은 지나가는 원이 아니다.
				if (temp == 1) result++;
			}

			cout << result << endl;
		}

	}
};

int main() {
	ios::sync_with_stdio(false);
	b664 op;
	op.initialize();
	op.operate();
	return 0;
}