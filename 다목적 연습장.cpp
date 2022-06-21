#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> vec = {
	{2,3},{4,5},{2,5},{5,4},{3,3}
};

bool compare(const vector<int>& a, const vector<int>& b) {
	if (a[0] < b[0]) return true;
	else if (a[0] == b[0]) {
		if (a[1] < b[1]) return true;
	}
	return false;
}

int main() {
	sort(vec.begin(), vec.end(), compare);
	string st1 = "a", st2 = "b";
	string st3 = st1 + st2;
	return 0;
}