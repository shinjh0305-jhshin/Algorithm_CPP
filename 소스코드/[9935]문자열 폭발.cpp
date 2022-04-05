#include <iostream>
#include <queue>
#include <string>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class burst {
private:
	string original;
	string target;
	deque<char>	qu;
	char end; //target의 가장 끝 문자

public:
	void initialize() {
		getline(cin, original);
		getline(cin, target);
		end = target.back();
	}

	void operate() {
		for (int i = 0; i < (int)original.length(); i++) {
			qu.push_back(original[i]);
			if (original[i] == end) review(i);
		}

		if (qu.empty()) cout << "FRULA" << endl;
		else {
			while (!qu.empty()) {
				cout << qu.front();
				qu.pop_front();
			}
			cout << endl;
		}

	}

	void review(int idx) { //idx : original에서의 끝 index
		for (int quIdx = qu.size() - 2, tgt = (int)target.length() - 2; tgt >= 0; quIdx--, tgt--) {
			if (quIdx < 0 || tgt < 0 || qu[quIdx] != target[tgt]) return;
		}

		for (int i = 0; i < (int)target.length(); i++) qu.pop_back();
		
	}
};

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	burst op;
	op.initialize();
	op.operate();
	return 0;
}