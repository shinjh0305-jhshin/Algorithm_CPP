#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>

#pragma warning (disable:4996)
#define iter 1e5
#define endl "\n"
using namespace std;

class suneung {
private:
	//bunmo : a5 + b5 >= 7일 때, 증가
	//bunja : ak == bk인 자연수 k의 개수
	int white, black;
	double bunmo, bunja;

public:
	suneung() :bunmo(0), bunja(0), white(0), black(0) {};

	void roll_dice() {
		random_device rand;
		mt19937_64 gen(rand());
		uniform_int_distribution<int> dis(1, 6);

		int dice; /*dice : 나온 주사위 번호*/
		for (double i = 1; i <= iter; i++) {
			for (int j = 0; j < 5; j++) {
				dice = dis(gen);

				if (dice >= 5)
					white += 2;
				else
					black += 1;
			}
			if (white + black >= 7) {
				bunmo++;
				cout << "white :" << white << "   black : " << black << endl;
				if (white == black) bunja++;
			}

			white = black = 0;
		}
	}

	void print() {
		cout << "Result : " << bunja << "/" << bunmo << endl;
	}

};

int main() {
	ios::sync_with_stdio(false);
	suneung op;
	op.roll_dice();
	op.print();
	return 0;
}