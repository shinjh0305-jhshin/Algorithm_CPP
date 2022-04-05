#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ppl, temp;
	vector<int> time;
	
	cin >> ppl;
	for (int i = 0; i < ppl; i++) {
		cin >> temp;
		time.push_back(temp);
	}
	
	sort(time.begin(), time.end());

	for (int i = 1; i < ppl; i++) {
		time[i] += time[i - 1];
	}

	int result = 0;
	for (int i = 0; i < ppl; i++) {
		result += time[i];
	}
	cout << result << endl;
	return 0;
}