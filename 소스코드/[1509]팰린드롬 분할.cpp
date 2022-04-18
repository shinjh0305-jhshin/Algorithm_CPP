#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool dp[2505][2505] = { false };
int result[2505];
string st;
int sz_string;

void initialize() {
	cin >> st;
	sz_string = st.size();
	st.insert(0, "."); //string index를 위한 dummy character
	
	for (int i = 1; i <= sz_string; i++) {
		dp[i][i] = true;
		if (i <= sz_string - 1 && st[i] == st[i + 1]) {
			dp[i][i + 1] = true;
		}
	}

	int end_of_start, end;
	for (int sz = 3; sz <= sz_string; sz++) {
		end_of_start = sz_string - (sz - 1);

		for (int start = 1; start <= end_of_start; start++) {
			end = start + sz - 1;

			if (st[start] == st[end] && dp[start + 1][end - 1] == 1) { //전체가 팰린드롬!
				dp[start][end] = true;
				continue;
			}
		}
	}
}

void operate() {
	result[0] = 0;

	for (int back = 1; back <= sz_string; back++) {
		result[back] = 1234567890;
		for (int start = 1; start <= back; start++) {
			if (dp[start][back]) {
				result[back] = min(result[back], result[start - 1] + 1);
			}
		}
	}

	cout << result[sz_string] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}