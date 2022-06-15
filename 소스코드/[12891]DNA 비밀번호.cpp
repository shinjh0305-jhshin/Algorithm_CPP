#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, pair<int, int>> amount; //pair : 목표량, 현재량

string rawdata;
int sz_rawdata, sz_pass;

void initialize() {
	cin >> sz_rawdata >> sz_pass >> rawdata;
	
	int temp;
	cin >> temp; amount['A'] = { temp,0 };
	cin >> temp; amount['C'] = { temp,0 };
	cin >> temp; amount['G'] = { temp,0 };
	cin >> temp; amount['T'] = { temp,0 };
}

void operate() {
	int result = 0;

	for (int i = 0; i < sz_pass; i++) { //처음은 직접 넣어준다
		amount[rawdata[i]].second++;
	}

	for (int i = sz_pass; i <= sz_rawdata; i++) {
		bool isValid = true;
		for (auto it : amount) {
			if (it.second.first > it.second.second) {
				isValid = false;
				break;
			}
		}

		if (isValid) result++;

		if (i >= sz_rawdata) {
			cout << result << endl;
			return;
		}
		amount[rawdata[i]].second++;
		amount[rawdata[i - sz_pass]].second--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}