#include <iostream>
#include <string>
using namespace std;

void operate() {
	double letterScore[6] = { 4,3,2,1,0,0 };

	string className, grade;
	double sum = 0, temp;
	int classes, qty, div = 0;

	cin >> classes;
	for (int i = 0; i < classes; i++) {
		cin >> className >> qty >> grade;

		temp = 0;
		if (grade[0] != 'F') {
			if (grade[1] == '+') temp = 0.3;
			else if (grade[1] == '0') temp = 0;
			else temp = -0.3;
		}

		temp += letterScore[grade[0] - 'A'];

		sum += temp * qty;
		div += qty;
	}
	cout << fixed;
	cout.precision(2);

	cout << sum / div + 0.00000000001 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}