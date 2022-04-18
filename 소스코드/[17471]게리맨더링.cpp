#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int sz_cities;
vector<int> ppls;
vector<int> map[11];

void initialize() {
	cin >> sz_cities;
	
	ppls.resize(sz_cities);

	for (int i = 0; i < sz_cities; i++) {
		cin >> ppls[i];
	}

	int iter, target;
	for (int i = 1; i <= sz_cities; i++) {
		cin >> iter;
		for (int j = 0; j < iter; j++) {
			cin >> target;
			map[i].push_back(target);
		}
	}
}

void operate() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();

	return 0;
}