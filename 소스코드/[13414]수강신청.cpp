#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#define pp pair<string, int>
#define endl "\n"
using namespace std;

int maxLimit, query;
unordered_map<string, int> orderOf;
vector<pp> rawdata;

bool compare(const pp& a, const pp& b) {
	return a.second < b.second;
}

void initialize() {
	cin >> maxLimit >> query;

	string student;
	for (int i = 0; i < query; i++) {
		cin >> student;
		orderOf[student] = i;
	}

	rawdata.assign(orderOf.begin(), orderOf.end());
	sort(rawdata.begin(), rawdata.end(), compare);
}

void operate() {
	int upperBound = min(maxLimit, (int)rawdata.size());

	for (int i = 0; i < upperBound; i++) {
		cout << rawdata[i].first << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}