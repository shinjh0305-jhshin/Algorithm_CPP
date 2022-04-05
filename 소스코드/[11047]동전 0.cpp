#include <iostream>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int types, target;
vector<int> currency;

int main() {
	cin >> types >> target; cin.get();
	int temp;
	for (int i = 0; i < types; i++) {
		cin >> temp; cin.get();
		currency.push_back(temp);
	}

	int result = 0;
	for (int i = currency.size() - 1; i >= 0; i--) {
		if (i > target) continue;
		result += target / currency[i];
		target = target % currency[i];
	}
	cout << result << endl;
	return 0;
}