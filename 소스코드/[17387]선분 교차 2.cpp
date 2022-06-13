#include <iostream>
#include <algorithm>
using namespace std;

void operate() {
	double x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2; //A,B
	cin >> x3 >> y3 >> x4 >> y4; //C,D

	double abc = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	double abd = x1 * y2 + x2 * y4 + x4 * y1 - (x2 * y1 + x4 * y2 + x1 * y4);
	double acd = x1 * y3 + x3 * y4 + x4 * y1 - (x3 * y1 + x4 * y3 + x1 * y4);
	double bcd = x2 * y3 + x3 * y4 + x4 * y2 - (x3 * y2 + x4 * y3 + x2 * y4);

	if (abc * abd == 0 && acd * bcd == 0) { //선분이 일직선상에 있다
		//양 끝 점이 서로 만나는지 확인
		double maxX1 = max(x1, x2), minX1 = min(x1, x2), maxY1 = max(y1, y2), minY1 = min(y1, y2);
		double maxX2 = max(x3, x4), minX2 = min(x3, x4), maxY2 = max(y3, y4), minY2 = min(y3, y4);

		if (maxX1 >= minX2 && maxX2 >= minX1 && maxY1 >= minY2 && maxY2 >= minY1) cout << 1 << endl; //양 끝점이 만난다
		else cout << 0 << endl; //양 끝점이 만나지 않는다.
	}
	else if (abc * abd <= 0 && acd * bcd <= 0) { //선분이 서로 교차한다
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}