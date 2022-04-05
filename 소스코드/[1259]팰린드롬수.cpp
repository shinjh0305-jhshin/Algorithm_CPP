#include <iostream>
#include <string>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

void operate() {
	string st;
	int left, right;
	bool flag;

	while (1) {
		getline(cin, st);

		if (st == "0") return;

		left = 0; right = st.size() - 1; flag = true;
		while (left <= right) {
			if (st[left] == st[right]) {
				left++; right--;
			}
			else {
				flag = false; break;
			}
		}

		if (flag == true) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	operate();

	return 0;
}