#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string original, target;
int len_original;

void initialize() {
	cin >> original >> target;
	len_original = original.length();
}

bool checkString(string st = target) {
	if (st.length() == len_original) {
		if (st == original) return true;
		else return false;
	}

	if (st.back() == 'A' && checkString(st.substr(0, st.length() - 1))) {
		return true;
	}
	if (st.front() == 'B') {
		string temp = st.substr(1, st.length() - 1);
		reverse(temp.begin(), temp.end());

		if (checkString(temp)) return true;
	}

	return false;
}


void operate() {
	if (checkString()) {
		cout << 1;
	}
	else cout << 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}