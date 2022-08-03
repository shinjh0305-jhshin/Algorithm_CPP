#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct info {
	int a, b, c;
};

bool operator< (const info & x, const info& y) {
	if (x.a < y.a) return true;
	else if (x.a == y.a) {
		if (x.b < y.b) return true;
		else if (x.b == y.b) {
			if (x.c < y.c) return true;
		}
	}
	return false;
}
set<info> visit;
queue<info> qu;

bool visited(int a, int b, int c) {
	vector<int> v = { a,b,c };
	sort(v.begin(), v.end());

	info temp = { v[0], v[1], v[2] };
	//temp.a = v[0]; temp.b = v[1]; temp.c = v[2];

	if (visit.find(temp) != visit.end()) return true;
	else {
		visit.insert(temp);
		return false;
	}

}

void operate() {
	info rawdata;
	cin >> rawdata.a >> rawdata.b >> rawdata.c;

	if (rawdata.a == rawdata.b && rawdata.b == rawdata.c) {
		cout << 1 << endl;
		return;
	}

	qu.push(rawdata);
	visited(rawdata.a, rawdata.b, rawdata.c);

	int temp[3];
	int target1, target2, save; // t1, t2 : 값이 바뀌는 숫자들, s : 값이 안 바뀌는 숫자

	while (!qu.empty()) {
		temp[0] = qu.front().a; temp[1] = qu.front().b; temp[2] = qu.front().c;
		qu.pop();
		
		for (int i = 0; i < 3; i++) {
			save = temp[i];
			target1 = i - 1 == -1 ? temp[2] : temp[i - 1];
			target2 = i + 1 == 3 ? temp[0] : temp[i + 1];

			if (target1 == target2) continue;
			if (target1 > target2) swap(target1, target2);

			target2 -= target1;
			target1 *= 2;

			if (target1 == target2 && target2 == save) {
				cout << 1 << endl;
				return;
			}

			if (!visited(target1, target2, save)) { //함수 내에서 visit에 추가된다.
				qu.push({ target1, target2, save });
			}
		}
	}

	cout << 0 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}