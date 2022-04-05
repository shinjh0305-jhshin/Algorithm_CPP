#include <iostream>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	vector<int> rawdata;
	int iter, base, exp, temp;

	cin >> iter; cin.get();
	for (int i = 0; i < iter; i++) {
		cin >> base >> exp; cin.get();

		base %= 10;
		rawdata.push_back(base);
		while (1) {
			temp = (rawdata.back()*base) % 10;
			if (temp == rawdata.front()) break;
			else rawdata.push_back(temp);
		}
		
		temp = (exp - 1) % rawdata.size();
		if(rawdata[temp]) cout << rawdata[temp] << endl;
		else cout << 10 << endl;
		while (rawdata.size()) rawdata.pop_back();
	}
}