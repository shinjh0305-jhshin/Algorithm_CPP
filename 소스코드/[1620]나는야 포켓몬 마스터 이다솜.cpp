#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

struct info {
	string st;
	int key;
};

vector<string> rawdata;
vector<info> sorted;
int pokemons, queries;

bool compare(const info &a, const info &b){
	if (a.st < b.st) return true;
	return false;
}

void initialize() {
	cin >> pokemons >> queries; cin.get();

	rawdata.resize(pokemons);
	sorted.resize(pokemons);
	for (int i = 0; i < pokemons; i++) {
		getline(cin, rawdata[i]);
		sorted[i].st = rawdata[i];
		sorted[i].key = i;
	}

	sort(sorted.begin(), sorted.end(), compare);
}

void num_query(int num) {
	cout << rawdata[num - 1] << endl;
}

void str_query(string target) {
	int left = 0, right = pokemons - 1, mid;

	while (left < right) {
		mid = (left + right) / 2;

		if (target == sorted[mid].st) {
			cout << sorted[mid].key + 1 << endl;
			return;
		}

		if (target > sorted[mid].st) left = mid + 1;
		else right = mid - 1;
	}

	cout << sorted[left].key + 1 << endl;
}

void operate() {
	string temp;
	
	for (int i = 0; i < queries; i++) {
		getline(cin, temp);

		if (temp[0] >= '0' && temp[0] <= '9') num_query(atoi(temp.c_str())); //숫자로 들어왔을 때
		else str_query(temp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}