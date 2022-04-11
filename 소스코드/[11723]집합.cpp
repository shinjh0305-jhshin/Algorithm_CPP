#include <iostream>
#include <bitset>	
#include <string>
#define endl "\n"
using namespace std;

void operate() {
	int opers, target;
	string op;
	bitset<21> rawdata(0);
	cin >> opers;

	for (int i = 0; i < opers; i++) {
		cin >> op;

		if (op == "add") {
			cin >> target;
			if(!rawdata.test(target)) rawdata.set(target, true);
		}
		else if (op == "remove") {
			cin >> target;
			if (rawdata.test(target)) rawdata.set(target, false);
		}
		else if (op == "check") {
			cin >> target;
			cout << (int)rawdata.test(target) << endl;
		}
		else if (op == "toggle") {
			cin >> target;
			rawdata.flip(target);
		}
		else if (op == "all") {
			rawdata.set();
		}
		else {
			rawdata.reset();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}