#include <iostream>
#include <algorithm>
#define endl "\n"
#define INF 2134567890
using namespace std;

int beads, groups;
int beadSize[305];

void initialize() {
	cin >> beads >> groups;
	for (int i = 0; i < beads; i++) {
		cin >> beadSize[i];
	}
}

pair<int, int> makeGroup(int target) {
	int maxSize = -1, sum = 0, group = 0;

	for (int i = 0; i < beads; i++) {
		if (sum + beadSize[i] > target) {
			maxSize = max(maxSize, sum);
			sum = beadSize[i];
			group++;
		}
		else sum += beadSize[i];
	}

	maxSize = max(maxSize, sum);
	group++;

	return { maxSize, group };
}

void printResult(int temp) {
	int sum = 0, cnt = 0, leftGroups = groups;

	for (int i = 0; i < beads; i++) {
		if (beads - i == leftGroups - 1) {
			if (cnt != 0) cout << cnt << ' ';
			for (; i < beads; i++) {
				cout << 1 << ' ';
			}
			return;
		}
		if (sum + beadSize[i] > temp) {
			cout << cnt << ' ';
			sum = beadSize[i];
			cnt = 1;
			leftGroups--;
		}
		else {
			sum += beadSize[i];
			cnt++;
		}
	}

	cout << cnt << ' ';
}

void operate() {
	int left = -1, right = 0, mid, temp;
	pair<int, int> info;
	for (int i = 0; i < beads; i++) {
		left = max(left, beadSize[i]);
		right += beadSize[i];
	}

	while (left <= right) {
		mid = (left + right) / 2;
		info = makeGroup(mid); //maxSize, groups

		if (info.second > groups) left = mid + 1;
		else if (info.second < groups) {
			temp = mid;
			right = mid - 1;
		}
		else {
			temp = info.first;
			right = info.first - 1;
		}
	}

	cout << temp << endl;
	printResult(temp);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}