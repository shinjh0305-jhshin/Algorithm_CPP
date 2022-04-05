#include <iostream>
#include <vector>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

vector<int> history;
vector<bool> used(9, false);
int bound, depth;

void initialize() {
	cin >> bound >> depth;
}

void operate(int cur_depth) {
	if (cur_depth == depth) {
		for (int i = 0; i < depth; i++) {
			cout << history[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= bound; i++) {
		if (!used[i]) {
			used[i] = true;
			history.push_back(i);

			operate(cur_depth + 1);

			history.pop_back();
			used[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate(0);

	return 0;
}