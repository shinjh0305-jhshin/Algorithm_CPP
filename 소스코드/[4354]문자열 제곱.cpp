#include <iostream>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

string st;
int stLen;
int failure[1000002];

bool initialize() {
	cin >> st;
	stLen = st.length();

	if (st == ".") return false;
	return true;
}

void get_failure() {
	int left = 0, right = 1;
	failure[0] = -1;

	while (right < stLen) {
		while (1) {
			if (st[left] == st[right]) {
				failure[right] = left;
				left++;
				break;
			}
			if (left == 0) {
				failure[right] = -1;
				break;
			}
			left = failure[left - 1] + 1;
		}
		right++;
	}
}

void operate() {
	get_failure();

	int iter = failure[stLen - 1] + 1;
	if (iter == 0 || stLen % (stLen - iter)) cout << 1 << endl;
	else cout << stLen / (stLen - iter) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		if (initialize()) operate();
		else break;
	}

	return 0;
}

/*
abcbacbacbacabcbacbacbac
*/