#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

void operate() {
	string st, temp; int iter, qu_size;
	queue<string> qu;
	
	cin >> st >> iter;
	qu.push(st);

	int len_st = st.length();

	while (iter--) {
		unordered_set<string> visited;
		qu_size = qu.size();

		while (qu_size--) {
			temp = qu.front(); qu.pop();
			if (visited.find(temp) != visited.end()) continue;
			visited.insert(temp);

			for (int i = 0; i < len_st - 1; i++) {
				for (int j = i + 1; j < len_st; j++) {
					if (i == 0 && temp[j] == '0') continue;
					swap(temp[i], temp[j]);
					qu.push(temp);
					swap(temp[i], temp[j]);
				}
			}
		}
	}

	if (qu.empty()) cout << -1 << endl;
	else {
		string maxSt = "0";
		while (!qu.empty()) {
			maxSt = max(maxSt, qu.front());
			qu.pop();
		}
		cout << maxSt << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}