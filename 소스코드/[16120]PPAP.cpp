#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<pair<char, int>> st; //글자, 몇 개 연속
string rawdata;
int len_rawdata;

void initialize() {
	cin >> rawdata;
	len_rawdata = rawdata.length();
}

void operate() {
	for (int i = 0; i < len_rawdata; i++) {
		if (rawdata[i] == 'P') {
			if (st.empty()) {
				st.push({ 'P', 1 });
			}
			else if (st.top().first == 'A' && st.top().second == 1) {
				st.pop();

				if (!st.empty() && st.top().second >= 2) {
					st.pop();
					st.pop();
					
					if (st.empty() || st.top().first == 'A') {
						st.push({ 'P', 1 });
					}
					else {
						st.push({ 'P', st.top().second + 1 });
					}
				}
				else {
					st.push({ 'A', 1 });
				}
			}
			else if (st.top().first == 'A') {
				st.push({ 'P', 1 });
			}
			else if (st.top().first == 'P') {
				st.push({ 'P', st.top().second + 1 });
			}
		}
		else {
			if (st.empty()) {
				cout << "NP" << endl;
				return;
			}
			if (st.top().first == 'P') {
				st.push({ 'A', 1 });
			}
			else {
				st.push({ 'A', st.top().second + 1 });
			}
		}
	}

	if (st.size() == 1 && st.top().first == 'P') {
		cout << "PPAP" << endl;
	}
	else {
		cout << "NP" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}