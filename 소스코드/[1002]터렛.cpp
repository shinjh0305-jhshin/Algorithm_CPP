#include <iostream>
#include <cmath>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class turret {
private:
	int x1, x2, y1, y2, cases;
	double r1, r2;
	double thr = 1e-5;


public:
	void initialize() {
		cin >> cases; cin.get();
	}

	void operate() {
		double dist; //중심 사이의 거리, d로 표현
		for (int i = 0; i < cases; i++) {
			cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2; cin.get();
			dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
			
			if (dist > r1 + r2) //서로 밖에 있으면서 교점이 없는 두 원 (d > r1 + r2)
				cout << 0 << endl;
			else if (abs(dist - (r1 + r2)) < thr) //외접하는 두 원 (d == r1 + r2)
				cout << 1 << endl;
			else if (dist < r1 + r2) { // d < r1 + r2
				if (dist < thr) { //d==0
					if (r1 == r2) //동일한 두 원
						cout << -1 << endl;
					else if (r1 != r2) // 동심원
						cout << 0 << endl;
				}
				else if (abs(dist - abs(r1 - r2)) < thr) //내접원
					cout << 1 << endl;
				else if(dist+min(r1, r2)<max(r1, r2)) //한 원이 다른 원을 포함하면서 교점이 없음
					cout << 0 << endl;
				else
					cout << 2 << endl;
			}
			else {
				cout << "Program error" << endl;
				cout << "d : " << dist << "  r1 + r2 : " << r1 + r2 << endl;
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	turret op;
	op.initialize();
	op.operate();
	return 0;
}