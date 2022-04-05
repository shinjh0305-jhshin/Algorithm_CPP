#include <iostream>
#include <string>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cases, iter; string st; char ch;
	cin >> cases; cin.get();

	for (int i = 0; i < cases; i++) {
		cin >> iter; cin.get();
		getline(cin, st);

		for (int j = 0; j < st.length(); j++) {
			ch = st[j];
			for (int k = 0; k < iter; k++) cout << ch;
		}
		cout << endl;
	}
	return 0;
}