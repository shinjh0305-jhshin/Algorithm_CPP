//음수가 나오는 순간 그 뒤에 있는 숫자들은 계속 빼는 쪽으로 가는 것이 유리하다.

#include <iostream>
#include <string>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class lost {
private:
	string st;
	int temp, ans; //temp : 현재 작업중인 숫자 저장  ans : 최종 결과값
	bool status; //이전에 나온 숫자의 부호를 저장. true : +  false : -

public:
	void initialize() {
		getline(cin, st);
		status = true;
		temp = ans = 0; //첫 시작은 양수이며, temp를 초기화한다.
	}

	void operate() {
		char ch;

		for (int i = 0; i < st.length(); i++) {
			ch = st[i];

			if (ch >= '0' && ch <= '9') { //숫자
				temp *= 10; temp += ch - '0';
			}
			else { //부호
				if (ch == '+') {
					//1. 이전에 나온 부호가 -인 경우(status가 false) : 현재 숫자를 뺀다.
					if (status == false) {
						ans -= temp;
					}
					//2. 이전에 나온 부호가 +인 경우(status가 true) : 현재 숫자를 더한다.
					else if (status == true) {
						ans += temp;
					}
				}
				else if (ch == '-') {
					//1. 이전에 나온 부호가 -인 경우(status가 false) : 현재 숫자를 뺀다.
					if (status == false) {
						ans -= temp;
					}
					//2. 이전에 나온 부호가 +인 경우(status가 true) : 현재 숫자를 더하고, flag를 바꾼다.
					else if (status == true) {
						ans += temp;
						status = false;
					}
				}

				temp = 0;
			}
		}

		if (status == false) ans -= temp;
		else if (status == true) ans += temp;

		cout << ans << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	lost op;
	op.initialize();
	op.operate();

	return 0;
}