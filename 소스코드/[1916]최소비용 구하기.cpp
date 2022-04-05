#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int city, price;
};
struct compare {
	bool operator()(const info &a, const info &b) {
		if (a.price > b.price) return true;
		return false;
	}
};
vector<info> map[1002];
priority_queue<info, vector<info>, compare> pq;
int result[1002];
int city, bus, dep, arr;

void initialize() {
	int acity, bcity, price;

	cin >> city >> bus; cin.get();

	for (int i = 0; i < bus; i++) {
		cin >> acity >> bcity >> price;
		map[acity].push_back({ bcity, price });
	}

	for (int i = 1; i <= 1000; i++) {
		result[i] = 987654321;
	}

	cin >> dep >> arr;
	
	result[dep] = 0;
}

void operate() {
	pq.push({ dep, 0 });

	int curCity, curPrice, iter, nCity, nPrice;

	while (!pq.empty()) {
		curCity = pq.top().city; curPrice = pq.top().price; pq.pop();

		if (curPrice > result[curCity]) continue;

		iter = map[curCity].size();

		for (int i = 0; i < iter; i++) {
			nCity = map[curCity][i].city; nPrice = map[curCity][i].price + curPrice;

			if (result[nCity] > nPrice) {
				result[nCity] = nPrice;
				pq.push({ nCity, nPrice });
			}
		}
	}

	cout << result[arr] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}