#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct info {
	int gold, silver, bronze, rank, idx;
};

vector<info> rawdata;
int sz_rawdata, target;

bool sortByMedal(const info& a, const info& b) {
	if (a.gold > b.gold) return true;
	else if (a.gold == b.gold) {
		if (a.silver > b.silver) return true;
		else if (a.silver == b.silver) {
			if (a.bronze > b.bronze) return true;
		}
	}
	return false;
}

bool sortByIdx(const info& a, const info& b) {
	return a.idx < b.idx;
}

void initialize() {
	cin >> sz_rawdata >> target;

	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i].idx >> rawdata[i].gold >> rawdata[i].silver >> rawdata[i].bronze;
	}
}

void operate() {
	sort(rawdata.begin(), rawdata.end(), sortByMedal);
	rawdata[0].rank = 1;

	int sameRank = 1;
	for (int i = 1; i < rawdata.size(); i++) {
		info& curCountry = rawdata[i];
		const info& prevCountry = rawdata[i - 1];
		if (curCountry.gold == prevCountry.gold && curCountry.silver == prevCountry.silver && curCountry.bronze == prevCountry.bronze) {
			curCountry.rank = prevCountry.rank;
			sameRank++;
		}
		else {
			curCountry.rank = prevCountry.rank + sameRank;
			sameRank = 1;
		} 
	}

	sort(rawdata.begin(), rawdata.end(), sortByIdx);

	cout << rawdata[target - 1].rank << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}