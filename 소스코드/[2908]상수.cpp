#include <iostream>
#include <algorithm>
#include <string>
#define endl "\n"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string st1, st2;
	cin >> st1 >> st2;

	reverse(st1.begin(), st1.end());
	int one = stoi(st1);

	reverse(st2.begin(), st2.end());
	int two = stoi(st2);

	cout << max(one, two) << endl;
	return 0;
}