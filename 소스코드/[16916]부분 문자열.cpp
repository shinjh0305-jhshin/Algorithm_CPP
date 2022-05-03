#include <iostream>
#include <vector>
#include <string>
using namespace std;

string rawdata, target;
int len_rawdata, len_target;
vector<int> failure;

void initialize() {
	cin >> rawdata >> target;
	len_rawdata = rawdata.length(); 
	len_target = target.length();

	failure.resize(len_target);
}

void get_failure() {
	failure[0] = -1;
	int right = 1, left = 0;

	while (right < len_target) {
		while (1) {
			if (target[left] == target[right]) {
				failure[right] = left;
				left++;
				break;
			}
			if (left == 0) {
				failure[right] = -1;
				break;
			}
			left = failure[left - 1] + 1;
		}
		right++;
	}
}

void compare() {
	int movRawdata = 0, movTarget = 0;
	while (1) {
		if (movTarget >= len_target) {
			cout << 1 << endl;
			return;
		}
		if (movRawdata >= len_rawdata) {
			cout << 0 << endl;
			return;
		}

		while (1) {
			if (rawdata[movRawdata] == target[movTarget]) {
				movRawdata++; movTarget++;
				break;
			}
			if (movTarget == 0) {
				movRawdata++;
				break;
			}
			movTarget = failure[movTarget - 1] + 1;
		}
	}
}

void operate() {
	get_failure();
	compare();
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
