#include <iostream>
#define endl "\n"
using namespace std;

int rawdata[100003];
int partialSum[100003];
int sz_rawdata, query;

void initialize() {
	cin >> sz_rawdata >> query;

	for (int i = 0; i < sz_rawdata; i++) cin >> rawdata[i];

	partialSum[0] = 0;
	for (int i = 1; i <= sz_rawdata; i++) {
		partialSum[i] = partialSum[i - 1] + rawdata[i - 1];
	}
}

void operate() {
	int from, to;

	for (int i = 0; i < query; i++) {
		cin >> from >> to;
		cout << partialSum[to] - partialSum[from - 1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}
