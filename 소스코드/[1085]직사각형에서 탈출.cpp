#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int result = 987654321;
	
	result = min(result, x - 0);
	result = min(result, y - 0);
	result = min(result, w - x);
	result = min(result, h - y);

	cout << result << endl;
	return 0;
}