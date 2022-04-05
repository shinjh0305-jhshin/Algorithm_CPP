#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

struct info{
	int weight, start_time, end_time;
};
vector<int> rawdata;
queue<info> qu;
int num_truck, len_bridge, capa;

void initialize() {
	cin >> num_truck >> len_bridge >> capa;
	rawdata.resize(num_truck);

	for (int i = 0; i < num_truck; i++) {
		cin >> rawdata[i];
	}

	qu.push({ rawdata[0], 1, 1 + len_bridge });
}

void operate() {
	int clock = 2, idx = 1, total_weight = rawdata[0];

	while (!qu.empty()) {
		if (qu.front().end_time == clock) {
			total_weight -= qu.front().weight;
			qu.pop();
		}
		if (idx < num_truck && total_weight + rawdata[idx] <= capa) {
			qu.push({ rawdata[idx], clock, clock + len_bridge });
			total_weight += rawdata[idx];
			idx++;
		}
		clock++;
	}

	cout << clock - 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}