#include <iostream>
#include <deque>
using namespace std;

void operate() {
	int len, del, target;
	cin >> len >> del; cin.get();

	deque<int> dq;
	for (int i = 0; i < len; i++) {
		target = cin.get() - '0';

		while (del > 0 && !dq.empty() && dq.back() < target) { //삭제할 수 있는 개수가 남았고, 앞 숫자가 나보다 작을 때 까지 pop
			dq.pop_back();
			del--;
		}
		dq.push_back(target);
	}

	for (int i = 0; i < dq.size() - del; i++) {
		cout << dq[i];
	}

	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}