#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string rawdata;
int sz_rawdata;
int result[2] = { 0 }; //0개수, 1개수

void operate() {
	cin >> rawdata;
	sz_rawdata = rawdata.size();

	char cur = '0', next = '1';
	if (cur != rawdata[0]) swap(cur, next);

	int startIdx = 0;
	while (startIdx != string::npos) {
		startIdx = rawdata.find_first_not_of(cur, startIdx);
		result[cur - '0']++;
		swap(cur, next);
	}

	cout << min(result[0], result[1]) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}