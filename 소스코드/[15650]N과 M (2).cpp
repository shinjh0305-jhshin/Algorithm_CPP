#include <iostream>
#include <vector>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

vector<int> history;
int bound, depth;

void initialize() {
	cin >> bound >> depth;
}

void operate(int cur_depth, int before) {
	if (cur_depth == depth) {
		for (int i = 0; i < depth; i++) {
			cout << history[i] << ' ';
		}
		cout << endl;
		return;
	}

	int up_bound = bound - (depth - cur_depth) + 1;
	for (int i = before + 1; i <= up_bound; i++) {
		history.push_back(i);
		operate(cur_depth + 1, i);
		history.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate(0, 0);

	return 0;
}