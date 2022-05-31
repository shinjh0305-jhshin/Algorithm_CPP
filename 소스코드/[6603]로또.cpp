#include <iostream>
#include <vector>
#include <cstring>
#define endl "\n"
using namespace std;

int rawdata[15];
bool isChosen[15];
int sz_rawdata;

void initialize() {
	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void makeChoice(int curIdx, int selected) {
	if (sz_rawdata - curIdx + selected < 6) { //가망 없음
		return;
	}
	if (curIdx == sz_rawdata) {
		if (selected == 6) {
			for (int i = 0; i < sz_rawdata; i++) {
				if (isChosen[i]) cout << rawdata[i] << ' ';
			}
			cout << endl;
		}
		return;
	}

	//1. 선택한다
	isChosen[curIdx] = true;
	makeChoice(curIdx + 1, selected + 1);

	//2. 선택하지 않는다
	isChosen[curIdx] = false;
	makeChoice(curIdx + 1, selected);
}

void operate() {
	makeChoice(0, 0);
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> sz_rawdata;
		if (!sz_rawdata) return 0;

		initialize();
		operate();
	}
	return 0;
}