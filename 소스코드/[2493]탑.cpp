#include <iostream>
#include <stack>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int height;
	int order;
};

class tower {
private:
	int towers;
	stack<info> st;

public:
	void initialize() {
		cin >> towers; cin.get();
	}

	void operate() {
		int newHeight; //새로운 탑의 높이
		for (int i = 1; i <= towers; i++) {
			cin >> newHeight; cin.get();
			while (!st.empty() && st.top().height < newHeight) st.pop();

			if (st.empty()) cout << 0 << ' ';
			else cout << st.top().order << ' ';

			st.push({ newHeight, i });
		}
		cout << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	tower op;
	op.initialize();
	op.operate();
	return 0;
}