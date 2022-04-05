#include <iostream>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> rawdata;
	for (int i = 1;; i++) {
		for (int j = 0; j < i; j++) {
			rawdata.push_back(i);
			if (rawdata.size() > 1000)	goto fin;
		}
	}
fin:;
	int start, end, sum = 0;
	cin >> start >> end;
	for (int i = start - 1; i <= end - 1; i++) {
		sum += rawdata[i];
	}

	cout << sum << endl;

	return 0;
}