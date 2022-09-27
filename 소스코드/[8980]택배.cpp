#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int from, to, weight;
};

bool compare(const info& a, const info& b) {
	if (a.to < b.to) return true;
	else if (a.to == b.to) {
		if (a.from < b.from) return true;
	}

	return false;
}

vector<info> rawdata;
int cities, max_capa, sz_rawdata;

int curweight[2005];

void initialize() {
	cin >> cities >> max_capa >> sz_rawdata;
	rawdata.resize(sz_rawdata);

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> rawdata[i].from >> rawdata[i].to >> rawdata[i].weight;
	}

	sort(rawdata.begin(), rawdata.end(), compare);
}

void operate() {
	int res = 0;
	for (const auto& it : rawdata) {
		int max_occupied_weight = 0;

		for (int i = it.from; i < it.to; i++) {
			max_occupied_weight = max(max_occupied_weight, curweight[i]);
		}

		int weight_avail = min(it.weight, max_capa - max_occupied_weight);
		res += weight_avail;

		for (int i = it.from; i < it.to; i++) {
			curweight[i] += weight_avail;
		}
	}

	cout << res << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}