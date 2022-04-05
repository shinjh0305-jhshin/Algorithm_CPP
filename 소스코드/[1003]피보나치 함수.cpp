#include <iostream>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class fib_cnt {
private:
	int max_history = -1, cases;
	vector<pair<int, int>> fib;

public:
	void initialize() {
		cin >> cases; cin.get();
		fib.push_back({ 1,0 }); max_history++;
		fib.push_back({ 0,1 }); max_history++;
	}

	void operate() {
		int num;
		for (int i = 0; i < cases; i++) {
			cin >> num; cin.get();
			if (max_history < num) {
				do {
					fib.push_back({ fib[max_history].first + fib[max_history - 1].first, fib[max_history].second + fib[max_history - 1].second });
					max_history++;
				} while (max_history != num);
			}
			cout << fib[num].first << ' ' << fib[num].second << endl;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	fib_cnt op;
	op.initialize();
	op.operate();
	return 0;
}