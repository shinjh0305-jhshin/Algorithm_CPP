#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

int stops;
vector<int> price, dist;

void initialize() {
	int temp;

	cin >> stops;
	for (int i = 1; i < stops; i++) {
		cin >> temp; cin.get();
		dist.push_back(temp);
	}
	for (int i = 0; i < stops; i++) {
		cin >> temp; cin.get();
		price.push_back(temp);
	}
}

void operate() {
	long long answer = 0;
	long long cur_price = price[0]; //현재까지 나온 가격 중에서 가장 싼 가격
	long long acc_dist = 0; //기존에 주유한 곳에서 현 위치까지 거리

	for (int city = 1; city < stops; city++) {
		acc_dist += dist[city - 1];

		if (price[city] < cur_price) {
			answer += cur_price * acc_dist;
			cur_price = price[city];
			acc_dist = 0;
		}
	}

	answer += cur_price * acc_dist;

	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}
/*
3
3 6
1000000000 500000000 5
*/