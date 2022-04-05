#include <iostream>
#include <vector>
#include <string>
#pragma warning (disable:4996)
using namespace std;

vector<char> vec = { ' ','A','D','G','J','M','P','T','W' };

int main() {
	string st;
	getline(cin, st);
	int ans = 0, j;

	for (int i = 0; i < st.size(); i++) {
		for (j = 1; j <= 8; j++) {
			if (st[i] >= vec[j]) continue;
			else break;
		}
		ans += j + 1;
	}

	cout << ans << endl;
	return 0;
}