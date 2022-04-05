#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ropes, temp;
	vector<int> rawdata;

	cin >> ropes; cin.get();
	
	for (int i = 0; i < ropes; i++) {
		cin >> temp; cin.get();
		rawdata.push_back(temp);
	}

	sort(rawdata.begin(), rawdata.end(), greater<int>());

	int answer = 0;
	for (int i = 1; i <= ropes; i++) {
		answer = max(answer, i*rawdata[i - 1]);
	}

	cout << answer << endl;
	return 0;
}