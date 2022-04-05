#include <iostream>
#include <stack>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	stack<int> st;
	long long a, b, c, newNum;

	cin >> a >> b >> c;
	newNum = b;
	
	while (1) {
		st.push(newNum % 2);
		if (newNum <= 3) break;
		newNum /= 2;
	}

	long long rem = a % c, temp = a % c;

	if (b != 1) {
		while (!st.empty()) {
			temp *= temp; temp %= c;
			if (st.top() == 1) {
				temp *= rem; temp %= c;
			}
			st.pop();
		}
	}

	cout << temp << endl;
	return 0;
}