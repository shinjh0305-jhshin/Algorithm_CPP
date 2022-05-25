#include <iostream>	
#include <string>
#include <algorithm>
using namespace std;

int check[26] = { 0 };
string st;
int len_st;

void initialize() {
	cin >> st;
	
	len_st = st.length();
	for (int i = 0; i < len_st; i++) {
		check[st[i] - 'A']++;
	}
}

int operate() {
	bool isOdd = false;
	string newString = "";

	if (len_st % 2) { //길이가 홀수인 경우
		for (int i = 0; i < 26; i++) { //홀수가 딱 1개만 있어야 한다.
			if (check[i] % 2 && isOdd) return 1;
			else if (check[i] % 2) isOdd = true;
		}


	}
	else { //길이가 짝수인 경우
		for (int i = 0; i < 26; i++) {
			if (check[i] % 2) return 1;
		}
	}
	

	int oddChar;
	for (int i = 0; i < 26; i++) {
		if (check[i]) {
			for (int iter = 0; iter < check[i] / 2; iter++) {
				newString += i + 'A';
			}
			
			if (check[i] % 2) oddChar = i; //홀수 개수의 문자
		}
	}

	string copyString = newString;
	reverse(copyString.begin(), copyString.end()); //뒷 부분 팰린드롬을 만든다.

	if (len_st % 2) newString += oddChar + 'A'; //홀수개수 문자는 가운데 하나를 더 집어넣는다
	newString += copyString;


	for (auto it : newString) {
		cout << it;
	}
	cout << endl;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();

	if (operate()) {
		cout << "I'm Sorry Hansoo" << endl;
	}

	return 0;
}