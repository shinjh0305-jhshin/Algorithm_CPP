#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string st;
	cin >> st;

	int stLen = st.length(), result = 0, start = 0;

	for (int i = 1; i < stLen; i++) {
		if (st[i] == ',') {
			result += stoi(st.substr(start, i - start));
			start = i + 1;
		}
	}
	result += stoi(st.substr(start, stLen - start));

	cout << result << endl;

	return 0;
}