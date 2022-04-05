#include <iostream>
#include <string>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

int main() {
	string s;
	getline(cin, s);
	
	if (s[0] == ' ' && s.length() == 1) {
		cout << '0' << endl;
		return 0;
	}

	int words = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			if (i == 0) continue;
			else if (i == s.length() - 1) continue;
			else words++;
		}
	}
	words++;
	cout << words << endl;
	return 0;
}