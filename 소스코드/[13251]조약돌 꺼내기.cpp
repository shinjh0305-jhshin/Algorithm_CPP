#include <iostream>
using namespace std;

double pebbles[52];
int pebble, target;

void operate() {
	cin >> pebble;

	double totalPebbles = 0;
	for (int i = 0; i < pebble; i++) {
		cin >> pebbles[i];
		totalPebbles += pebbles[i];
	}
	cin >> target;

	double sum = 0, temp, originaltotal = totalPebbles, originaltarget = target;

	for (int i = 0; i < pebble; i++) {
		temp = 1;
		totalPebbles = originaltotal;
		target = originaltarget;

		for (double k = pebbles[i]; k >= 0 && target > 0; k--, target--) {
			temp *= k / totalPebbles;
			totalPebbles--;
		}
		sum += temp;
	}
	cout << fixed;
	cout.precision(12);
	cout << sum << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}