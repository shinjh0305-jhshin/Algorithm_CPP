#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string st;
int sz_string;
vector<int> len;

void initialize() {
	cin >> st;
	sz_string = st.length();
	len.resize(sz_string);
}

void failure() {
	int left, ans = 0;

	for (int left_bound = 0; left_bound < sz_string - 1; left_bound++) {
		left = left_bound;
		len[left] = - 1;

		for (int right = left_bound + 1; right < sz_string; right++) {
			while (1) {
				if (st[left] == st[right]) {
					len[right] = left - left_bound;
					left++;
					break;
				}
				if (left == left_bound) {
					len[right] = - 1;
					break;
				}

				left = len[left - 1] + left_bound + 1;
			}
			ans = max(ans, len[right] + 1);
		}
	}
	

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	failure();

	return 0;
}

/*
asexexssexessex
ans : 4
*/