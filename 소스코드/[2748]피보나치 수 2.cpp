#include <iostream>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<long long> rawdata(91);

void operate() {
	int target;
	cin >> target;

	rawdata[0] = 0;
	rawdata[1] = 1;
	for (int i = 2; i <= target; i++) {
		rawdata[i] = rawdata[i - 1] + rawdata[i - 2];
	}

	cout << rawdata[target] << endl;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}