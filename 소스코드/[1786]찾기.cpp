#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

string str, pat;
int sz_str, sz_pat;
vector<int> failure;

void initialize() {
	getline(cin, str);
	getline(cin, pat);

	sz_str = str.size();
	sz_pat = pat.size();
	failure.resize(sz_pat);
}

void get_failure() {
	int i = 0, j = 1;
	failure[0] = -1;

	while (j < sz_pat) {
		while (1) {
			if (pat[i] == pat[j]) { //일치
				failure[j] = i;
				i++;
				break;
			}

			if (i == 0) { //불일치
				failure[j] = -1;
				break;
			}
			else i = failure[i - 1] + 1;
		}

		j++;
	}

}

void get_match() {
	int str_mov = 0, pat_mov = 0;
	queue<int> qu;

	while (str_mov < sz_str && pat_mov < sz_pat) {
		if (str[str_mov] == pat[pat_mov]) {
			str_mov++; pat_mov++;
		}
		else if (pat_mov == 0) {
			str_mov++;
		}
		else {
			pat_mov = failure[pat_mov - 1] + 1;
		}

		if (pat_mov == sz_pat) {
			qu.push(str_mov - sz_pat + 1);
			pat_mov = failure[pat_mov - 1] + 1;
		}
	}

	cout << qu.size() << endl;
	while (!qu.empty()) {
		cout << qu.front() << ' ';
		qu.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	get_failure();
	get_match();

	return 0;
}