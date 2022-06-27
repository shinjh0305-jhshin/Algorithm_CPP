#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

void operate() {
	int queries;
	string st;

	cin >> queries >> st;

	string prefix, suffix;
	int len = st.length(), i = 0, lenPrefix, lenSuffix;

	prefix = st.substr(0, st.find('*'));
	lenPrefix = prefix.length();
	suffix = st.substr(st.find('*') + 1);
	lenSuffix = suffix.length();


	string query;
	while (queries--) {
		cin >> query;
		if (lenPrefix + lenSuffix > query.length()) cout << "NE" << endl; //ac*cd -> acd는 만족하지 않는 문자열이다.
		else if ((query.substr(0, lenPrefix) == prefix) && (query.substr(query.length() - lenSuffix) == suffix)) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	operate();

	return 0;
}