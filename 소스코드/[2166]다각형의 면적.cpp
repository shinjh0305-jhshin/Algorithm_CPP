#include <iostream>
#include <cmath>
using namespace std;

double getArea(double x1, double y1, double x2, double y2, double x3, double y3) {
	return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
}

void operate() {
	double result = 0, x1, y1, x2, y2, tx1, ty1;
	int iter;

	cin >> iter;

	//하나의 지점을 잡아서 그 지점을 꼭짓점으로 하는 삼각형을 계속 만든다. (삼각형 개수 = iter-2)
	cin >> tx1 >> ty1;
	cin >> x1 >> y1;
	for (int i = 0; i < iter - 2; i++) {
		cin >> x2 >> y2;
		result += getArea(tx1, ty1, x1, y1, x2, y2)/2;
		x1 = x2; y1 = y2;
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(result) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}