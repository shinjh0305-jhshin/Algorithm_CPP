#include <iostream>
#include <stack>
#define ll long long
using namespace std;

struct info {
	int height, idx;
};
stack<info> st;
int avail[80003];

void operate() {
	ll sum = 0, buildings;
	cin >> buildings;

	int curHeight;
	
	for (int i = 1; i <= buildings; i++) {
		cin >> curHeight;

		while (!st.empty() && st.top().height <= curHeight) {
			avail[st.top().idx] = i - st.top().idx - 1;
			st.pop();
		}

		st.push({ curHeight, i });
	}

	while (!st.empty()) {
		avail[st.top().idx] = buildings - st.top().idx;
		st.pop();
	}

	for (int i = 1; i <= buildings; i++) {
		sum += avail[i];
	}

	cout << sum << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}