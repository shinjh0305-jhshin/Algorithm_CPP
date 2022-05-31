#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

vector<pair<int, int>> vec;

void hanoi(int num, int from, int to, int temp) {
	if (num == 1) {
		vec.push_back({ from, to });
		return;
	}
	hanoi(num - 1, from, temp, to);
	hanoi(1, from, to, temp);
	hanoi(num - 1, temp, to, from);
}

void operate() {
	int target;
	cin >> target;

	hanoi(target, 1, 3, 2);

	cout << vec.size() << endl;
	for (const auto it : vec) {
		cout << it.first << ' ' << it.second << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}