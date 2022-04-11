#include <iostream>
#include <bitset>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num;

	cout << bitset<8>(num).count() << endl;

	return 0;
}