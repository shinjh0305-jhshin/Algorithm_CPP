#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

vector<int> rawdata;

void operate() {
	int nums;
	cin >> nums;
	rawdata.resize(nums);

	for (int i = 0; i < nums; i++) {
		cin >> rawdata[i];
	}

	sort(rawdata.begin(), rawdata.end(), less<int>());

	for (int i = 0; i < nums; i++) {
		cout << rawdata[i] << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}