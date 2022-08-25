#include <iostream>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

vector<string> rawdata;
int sz_rawdata;

void initialize() {
	cin >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

bool isPalindrome(int idx, int left, int right, bool isDeleted = false) {
	string& target = rawdata[idx];

	while (left <= right) {
		if (target[left] == target[right]) { //���� ���� ������ ���
			left++; right--; continue;
		}
		if (isDeleted) { //���� �ٸ� ���ڸ�, �̹� 1���� ���ڸ� ������ ���
			return false;
		}

		//���� �ٸ� �����̳�, ���� ���ڸ� �������� ���� ���
		if (target[left + 1] == target[right]) { //������ 1ĭ �մ�ܺ���.
			if (isPalindrome(idx, left + 2, right - 1, true)) {
				cout << 1 << endl;
				return true;
			}
		}
		if (target[left] == target[right - 1]) {
			if (isPalindrome(idx, left + 1, right - 2, true)) {
				cout << 1 << endl;
				return true;
			}
		}
		
		return false;
	}

	if (left > right && !isDeleted) {
		cout << 0 << endl;
		return true;
	}

	return true;
}

void operate() {
	for (int i = 0; i < sz_rawdata; i++) {
		if (!isPalindrome(i, 0, rawdata[i].length() - 1)) {
			cout << 2 << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}