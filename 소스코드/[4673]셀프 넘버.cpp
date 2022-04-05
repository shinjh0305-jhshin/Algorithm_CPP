#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int history[10005] = { 0 };

void operate(int start) {
	while (start < 10000) {
		if (start < 10) start += start;
		else if (start < 100) start = start + start / 10 + start % 10;
		else if (start < 1000) start = start + start / 100 + (start % 100) / 10 + start % 10; //자기자신 + 100자리 + 10자리 + 1자리
		else if (start < 10000) start = start + start / 1000 + (start % 1000) / 100 + (start % 100) / 10 + start % 10; //자기자신 + 1000자리 + 100자리 + 10자리 + 1자리
		history[start] = 1;
	}
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		if (history[i] == 0) operate(i);
	}
	for (int i = 1; i < 10000; i++) {
		if (history[i] == 0) cout << i << endl;
	}
	return 0;
}