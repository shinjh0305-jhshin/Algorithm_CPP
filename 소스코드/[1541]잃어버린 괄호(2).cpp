#include <iostream>
#include <string>
using namespace std;

string st;

void initialize() {
	cin >> st;
}

void operate() {
	int result = 0, st_len = st.length();
	bool flag = false; //'-'기호가 나왔나?

	int start = 0;
	for (int i = 1; i < st_len; i++) {
		if (st[i] == '+' || st[i] == '-') { //연산자 기호가 나왔을 경우
			if (flag == true) result -= stoi(st.substr(start, i - start)); //이전에 - 기호가 나왔었으면
			else { //이전에 - 기호가 안 나왔었으면
				result += stoi(st.substr(start, i - start));
				if (st[i] == '-') flag = true; //다음 기호가 -일 경우, 앞으로 모든 숫자를 뺀다.
			}
			start = i + 1;
		}
	}
	if (flag == true) result -= stoi(st.substr(start, st_len - start));
	else result += stoi(st.substr(start, st_len - start));

	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}