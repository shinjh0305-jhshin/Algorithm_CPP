#include <iostream>
#define endl "\n"
using namespace std;

bool switches[105] = { false };
int sz_switch, students;

void initialize() {
	cin >> sz_switch;
	for (int i = 1; i <= sz_switch; i++) {
		cin >> switches[i];
	}
	cin >> students;
}

void male(int num) {
	for (int i = num; i <= sz_switch; i += num) {
		switches[i] = switches[i] == true ? false : true;
	}
}

void female(int num) {
	int left = num, right = num;
	while (1 < left && right < sz_switch) {
		if (switches[left - 1] != switches[right + 1]) break;
		left--; right++;
	}

	for (int i = left; i <= right; i++) {
		switches[i] = switches[i] == true ? false : true;
	}
}

void printSwitch() {
	//cout << "//////////////////////////////////" << endl;
	for (int i = 1; i <= sz_switch; i++) {
		cout << switches[i];
		if (i % 20 == 0) cout << endl;
		else cout << ' ';
	}
	//cout << endl<< "//////////////////////////////////" << endl;
}

void operate() {
	int sex, num;
	for (int i = 0; i < students; i++) {
		cin >> sex >> num;
		
		if (sex == 1) male(num);
		else female(num);

		//printSwitch();
	}
	printSwitch();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}