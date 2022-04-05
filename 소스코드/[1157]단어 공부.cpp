#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

string rawdata;
int save[28] = { 0 };

int main() {
	int ch;

	getline(cin, rawdata);
	for (int i = 0; i < rawdata.length(); i++) {
		ch = rawdata[i];

		if (islower(ch)) {
			ch = toupper(ch);
		}
		save[ch - 'A']++;
	}

	bool flag = false;
	int result = 0, resultIndex;
	for (int i = 0; i < 26; i++) {
		if (result == save[i]) flag = true;
		else if (result < save[i]) {
			result = save[i];
			resultIndex = i;
			flag = false;
		}
	}

	if (flag == true) cout << '?' << endl;
	else cout << (char)(resultIndex + 'A') << endl;

	return 0;
}