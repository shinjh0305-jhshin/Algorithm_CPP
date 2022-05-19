#include <iostream>
#include <string>
#include <regex>
using namespace std;

string st;

void operate() {
	cin >> st;
	regex re("(100+1+|01)+");
	if (regex_match(st, re)) cout << "SUBMARINE" << endl;
	else cout << "NOISE" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}