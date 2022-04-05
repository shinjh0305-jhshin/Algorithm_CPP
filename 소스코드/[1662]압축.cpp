#include <iostream>
#include <string>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

string st;
int st_len;

void initialize() {
	getline(cin, st);
	st_len = st.length();
}

int get_length(int& idx) {
	int len = 0, iter;
	char ch;

	while (1) {
		ch = st[idx];

		if (ch == ')' || ch == '\0') break;
		if (st[idx + 1] == '(') {
			iter = st[idx] - '0';

			idx += 2;
			len += iter * get_length(idx);
		}
		else {
			len++; idx++;
		}
	}
	
	idx++;
	return len;
}

void operate() {
	int idx = 0;
	cout << get_length(idx) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	operate();

	return 0;
}