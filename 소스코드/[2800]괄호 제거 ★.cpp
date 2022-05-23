//_ stands for parenthesis
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <set>
#define endl "\n"
using namespace std;

int lenRawdata;
string rawdata;
bool parenthesis[202];
vector<pair<int, int>> _pair;
set<string> s;

void initialize() {
	cin >> rawdata;

	stack<int> st;
	lenRawdata = rawdata.length();

	for (int i = 0; i < lenRawdata; i++) {
		parenthesis[i] = true;
		if (rawdata[i] == '(') st.push(i);
		else if (rawdata[i] == ')') {
			_pair.push_back({ st.top(), i });
			st.pop();
		}
	}

	sort(_pair.begin(), _pair.end());
}

void DFS(int cur_, int cnt) { //cur_ : parenthesisPair index
	if (cur_ == _pair.size()) {
		if (!cnt) return; //¾ø¾Ø °ýÈ£°¡ ¾ø´Â °æ¿ì
		
		string st = "";
		for (int i = 0; i < lenRawdata; i++) {
			if (parenthesis[i]) st += rawdata[i];
		}
		s.insert(st);
		return;
	}

	parenthesis[_pair[cur_].first] = parenthesis[_pair[cur_].second] = true; //°ýÈ£ ÀÖ´Â °æ¿ì
	DFS(cur_ + 1, cnt);
	parenthesis[_pair[cur_].first] = parenthesis[_pair[cur_].second] = false; //°ýÈ£ ¾ø´Â °æ¿ì
	DFS(cur_ + 1, cnt + 1);

}

void operate() {
	DFS(0, 0);
	for (const auto it : s) {
		cout << it << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}