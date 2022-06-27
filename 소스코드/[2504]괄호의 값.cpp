#include <iostream>
#include <string>
#include <stack>
#define leftPhar -1 //여는 소괄호
#define leftSquare -2 //여는 대괄호
using namespace std;

stack<int> st; //값 저장하는 스택
stack<char> testing; //유효한 입력인지 확인하는 스택
string rawdata;

bool initialize() { //테스트케이스를 입력받고 유효한 입력인지 확인한다.
	cin >> rawdata;
	int len_rawdata = rawdata.length();

	for (int i = 0; i < len_rawdata; i++) {
		if (rawdata[i] == '(' || rawdata[i] == '[') {
			testing.push(rawdata[i]);
		}
		else {
			if (rawdata[i] == ')') { //닫는 소괄호 나온 경우
				if (testing.empty() || testing.top() != '(') return false;
				else testing.pop();
			}
			else { //닫는 대괄호 나온 경우
				if (testing.empty() || testing.top() != '[') return false;
				else testing.pop();
			}
		}
	}

	if (testing.empty()) return true; //스택에서 dangling bracket 없이 전부 다 나온 경우
	else return false; //남은 괄호가 있는 경우
}

int seekFor(int target) {
	int answer = 0;
	while (st.top() != target) {
		answer += st.top();
		st.pop();
	}
	st.pop(); //여는 괄호를 제거한다

	if (answer == 0) return 1; //열자마자 닫힌 경우에는 1을 리턴한다
	else return answer; //안에 괄호식이 있는 경우, 괄호식들을 전부 더해서 리턴한다
}

void operate() {
	int len = rawdata.length();
	for (int i = 0; i < len; i++) {
		if (rawdata[i] == '(') st.push(leftPhar);
		else if (rawdata[i] == '[') st.push(leftSquare);
		else if (rawdata[i] == ')') {
			st.push(2 * seekFor(leftPhar)); //소괄호는 가중치 2
		}
		else if (rawdata[i] == ']') {
			st.push(3 * seekFor(leftSquare)); //대괄호는 가중치 3
		}
	}

	int ans = 0;
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	if (initialize()) {
		operate();
	}
	else cout << 0 << endl;

	return 0;
}