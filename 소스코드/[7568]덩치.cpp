#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

struct info {
	int weight, height, rank;
};
vector<info> rawdata;
int ppl;

void initialize() {
	cin >> ppl; 

	int wtemp, htemp;
	for (int i = 0; i < ppl; i++) {
		cin >> wtemp >> htemp;
		rawdata.push_back({ wtemp, htemp, 1 });
	}
}

void operate() {
	for (int i = 0; i < ppl; i++) {
		for (int j = 0; j < ppl; j++) {
			if (rawdata[i].height < rawdata[j].height && rawdata[i].weight < rawdata[j].weight) rawdata[i].rank++;
		}
	}

	for (int i = 0; i < ppl; i++) {
		cout << rawdata[i].rank << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}