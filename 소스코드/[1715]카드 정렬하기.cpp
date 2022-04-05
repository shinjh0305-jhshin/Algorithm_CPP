//[11066]파일 합치기의 일반화된 문제
#include <iostream>
#include <queue>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int sz_queue;

void initialize() {
	int temp;
	cin >> sz_queue;
	for (int i = 0; i < sz_queue; i++) {
		cin >> temp;
		pq.push(temp);
	}
}

void operate() {
	int sum = 0, num1, num2, num_sum;
	
	if (sz_queue == 1) {
		cout << 0 << endl;
		return;
	}

	while (pq.size() != 1) {
		num1 = pq.top(); pq.pop();
		num2 = pq.top(); pq.pop();

		num_sum = num1 + num2;
		sum += num_sum;

		pq.push(num_sum);
	}

	cout << sum << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
6
10 60 40 20 30 50

1
50

2
50 100

3
20 40 10

*/