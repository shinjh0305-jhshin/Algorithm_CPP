#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <Windows.h>
#pragma warning (disable:4996)
using namespace std;

string hello = u8"안녕하세요. 신재현입니다.";
u32string anthem = U"동해물과 백두산이 마르고 닳도록";
u32string st = U"동해물과";
u16string school = u"서강대학교 컴퓨터공학과 CSE_4011";

int main() {
	//UTF-32에서는 모든 유니코드 문자를 4바이트 단위로 센다.
	cout << anthem.length() << endl; //17 (실제 17글자)
	if (anthem.substr(0, 4) == st) { //동해물과 == 동해물과
		cout << "true" << endl;
	}
	if (anthem.find(U"백") != u32string::npos) {
		cout << "found" << endl;
	}

	//UTF-8
	size_t i = 0, len = 0;
	while (i < hello.length()) {
		int char_size = 0;
		if ((hello[i] & 0b11111000) == 0b11110000) {
			char_size = 4;
		}
		else if ((hello[i] & 0b11110000) == 0b11100000) {
			char_size = 3;
		}
		else if ((hello[i] & 0b11100000) == 0b11000000) {
			char_size = 2;
		}
		else {
			char_size = 1;
		}

		cout << hello.substr(i, char_size) << endl;
		i += char_size;
		len++;
	}
	cout << "total length : " << len << endl;

	//UTF-16
	cout << school.length() << endl;
	if (school.find(u"CSE") != u16string::npos) {
		cout << "find" << endl;
	}

	//wstring을 cout 할 때, 한국어임을 알려주는 용도.
	locale::global(locale(""));
	wcout.imbue(locale());

	//ㅂㅅㅌㅋㅍ
	string st = "동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라 만세.";
	string rawdata[][10] = { 
		{ "가", "갸", "백", " ", "하", "세", "너", "나", "영", "석" },
		{ "보", "닳", "중", "신", "계", "수", "상", "정", "종", "연" },
		{ "르", "망", "중", "사", "록", "동", "해", "이", "우", "정" }
	};

	return 0;
}