#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<char> rawdata;
int sz_rawdata, sz_target;
vector<char> st;
vector<char> vowel = { 'a','e','i','o','u' };

void initialize() {
	cin >> sz_target >> sz_rawdata;

	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata.begin(), rawdata.end(), less<char>());
}

void DFS(int idx_start, int vowels, int consnts) { //consnts : consonants(자음)
	if (sz_target - st.size() > sz_rawdata - idx_start) { //남아있는 글자 개수보다 추가해야 될 글자의 개수가 더 많다.
		return;
	}

	if (st.size() == sz_target) {
		if (vowels >= 1 && consnts >= 2) {
			for (const auto& it : st) {
				cout << it;
			}
			cout << endl;
		}
		return;
	}

	for (int i = idx_start; i < sz_rawdata; i++) {
		st.push_back(rawdata[i]);

		if (find(vowel.begin(), vowel.end(), rawdata[i]) != vowel.end()) { //현재 글자는 모음이다
			DFS(i + 1, vowels + 1, consnts);
		}
		else { //현재 글자는 자음이다.
			DFS(i + 1, vowels, consnts + 1);
		}

		st.pop_back();
	}
}

void operate() {
	DFS(0, 0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}