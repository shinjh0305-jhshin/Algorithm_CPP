#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> gen_num;
vector<char> ineq;
int sz_ineq;
bool used[10] = { false };

void initialize() {
	cin >> sz_ineq;
	ineq.resize(sz_ineq);

	for (int i = 0; i < sz_ineq; i++) {
		cin >> ineq[i];
	}
}

bool make_min_rawdata(int len, string &temp) {
	if (len == sz_ineq + 1) return true;

	for (int i = 0; i <= 9; i++) {
		if (!used[i]) {
			used[i] = true;
			temp[len] = i + '0';

			if (len >= 1) {
				if (ineq[len - 1] == '>' && temp[len - 1] > temp[len]);
				else if (ineq[len - 1] == '<' && temp[len - 1] < temp[len]);
				else {
					used[i] = false;
					continue;
				}
			}

			if (make_min_rawdata(len + 1, temp)) return true;

			used[i] = false;
		}
	}
	return false;
}

bool make_max_rawdata(int len, string &temp) {
	if (len == sz_ineq + 1) return true;

	for (int i = 9; i >= 0; i--) {
		if (!used[i]) {
			used[i] = true;
			temp[len] = i + '0';

			if (len >= 1) {
				if (ineq[len - 1] == '>' && temp[len - 1] > temp[len]);
				else if (ineq[len - 1] == '<' && temp[len - 1] < temp[len]);
				else {
					used[i] = false;
					continue;
				}
			}

			if (make_max_rawdata(len + 1, temp)) return true;

			used[i] = false;
		}
	}
	return false;
}

void operate() {
	string temp;
	temp.resize(sz_ineq + 1);

	make_max_rawdata(0, temp);
	cout << temp << endl;

	memset(used, false, sizeof(used));

	make_min_rawdata(0, temp);
	cout << temp << endl;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}