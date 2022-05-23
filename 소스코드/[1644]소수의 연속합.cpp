#include <iostream>
#include <vector>
using namespace std;

int target;
vector<int> primeSum;
bool check[4000003];

void initialize() {
	cin >> target;
	for (int i = 0; i <= target; i++) check[i] = true;
	check[1] = false;
	primeSum.push_back(0);
}

void countSum() {
	int left = 0, right = 0, cnt = 0;
	
	int partialSum, sz_primeSum = primeSum.size();
	while (right < sz_primeSum) {
		partialSum = primeSum[right] - primeSum[left]; //누적합을 이용한다.
		if (partialSum == target) {
			cnt++;
			right++;
		}
		else if (partialSum < target) {
			right++;
		}
		else {
			left++;
		}
	}

	cout << cnt << endl;
}

void operate() {
	int temp, i;
	for (i = 2; i*i <= target; i++) {
		if (!check[i]) continue;

		for (int mul = 2;; mul++) {
			temp = i * mul;
			if (temp > target) break;
			if (check[temp] == true) check[temp] = false;
		}
	}

	int sum = 0;
	for (int j = 2; j <= target; j++) {
		if (check[j]) {
			sum += j;
			primeSum.push_back(sum);
		}
	}

	countSum();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}