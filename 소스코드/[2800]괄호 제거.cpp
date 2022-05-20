#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

string original, working;
int strLen;
bool notRemovedAtAll = true;

void initialize() {
	cin >> original;
	strLen = original.length();
}

int makeWorkingString(bool prevRemoved, int idx) { //prevRemoved : 직전 괄호가 제거 되었는가?
	int mov;
	for (mov = idx; mov < strLen; mov++) { 
		if (original[mov] == '(') {
			//1. 괄호를 유지 하는 경우의 수를 생각해본다
			working.push_back('(');
			makeWorkingString(false, mov + 1);
			working.pop_back(); //여는 괄호를 제거한다.

			//2. 괄호를 없애는 경우의 수를 생각해본다
			notRemovedAtAll = false;
			mov = makeWorkingString(true, mov + 1);
		}
		else if (original[mov] == ')' && prevRemoved) continue; //닫는 괄호가 나왔고, 이전 여는 괄호가 제거 된 경우
		else working.push_back(original[mov]);
	}
	if (mov == strLen && !notRemovedAtAll) cout << working << endl; //working을 출력한다.
	while (working.length() != idx) working.pop_back(); //string을 pop 한다
}

void operate() {
	makeWorkingString(false, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}