#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int test_cases, height, width, target, room_no;
	cin >> test_cases;
	
	for (int i = 0; i < test_cases; i++) {
		room_no = 0;
		cin >> height >> width >> target;
		room_no += (target - 1) / height + 1;
		room_no += ( (target - 1) % height + 1) * 100;
		cout << room_no << endl;
	}
	return 0;
}