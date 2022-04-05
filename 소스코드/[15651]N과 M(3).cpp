#include <iostream>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> vec;
int up_bound, len;

void initialize() {
	cin >> up_bound >> len;
}

void op(int cur_len) {
	for (int i = 1; i <= up_bound; i++) {
		vec.push_back(i);
		if (cur_len == len) {
			for (int i = 0; i < len; i++) {
				cout << vec[i] << ' ';
			}
			cout << endl;
		}
		else 
			op(cur_len + 1);

		vec.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	op(1);
	
	return 0;
}