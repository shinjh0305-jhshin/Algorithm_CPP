#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numbers;
	string rawdata;

	cin >> numbers >> rawdata;

	int ans = 0;
	for (const char& a : rawdata) {
		ans += a - '0';
	}

	cout << ans << endl;
	return 0;
}