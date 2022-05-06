#include <iostream>
#include <cstring>
#include <string>
#define endl "\n"
using namespace std;

class checker {
private:
	int	words;
	bool history[26];  //이미 나온 문자인지 저장하는 공간
	string st;

public:
	void operate() {
		int len, temp, j, answer = 0;
		cin >> words; 

		for (int i = 0; i < words; i++) {
			memset(history, false, sizeof(history)); //각 테스트케이스마다 초기화한다.
			cin >> st;
			len = st.length();

			for (j = 0; j < len; j++) {
				temp = st[j] - 'a'; //인덱스 0 부터 시작하도록 바꾼다.
				if (history[temp] == 0) history[temp] = true; //처음 나타나는 문자
				else {
					if (st[j] == st[j - 1]) continue;
					else break;
				}
			}

			if (j == len) answer++;
		}

		cout << answer << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	checker op;
	op.operate();

	return 0;
}