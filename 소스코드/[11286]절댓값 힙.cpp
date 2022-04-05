#include <iostream>
#include <queue>
#include <cmath>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int key;
	int absKey;
};

struct compare {
	bool operator()(const info &a, const info &b) {
		if (a.absKey > b.absKey) return true;
		else if (a.absKey == b.absKey) {
			if (a.key > b.key) return true;
		}
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<info, vector<info>, compare> pq;

	int opers, inNum;

	cin >> opers; cin.get();
	
	for (int i = 0; i < opers; i++) {
		cin >> inNum; cin.get();

		if (inNum == 0) {
			if (pq.empty()) cout << 0 << endl;
			else {
				cout << pq.top().key << endl;
				pq.pop();
			}
		}
		else pq.push({ inNum, abs(inNum) });
	}


	return 0;
}