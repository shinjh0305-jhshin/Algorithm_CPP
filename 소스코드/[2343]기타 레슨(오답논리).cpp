#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAKESUM(a, b) (prefixSum[(b)] - prefixSum[(a) - 1])
using namespace std;

struct info {
	int sum, from, to;
};
struct compare {
	bool operator()(const info& a, const info& b) {
		return a.sum < b.sum;
	}
};

int rawdata[100003], prefixSum[100003];
int videos, disks;
priority_queue<info, vector<info>, compare> pq; //sum, upperIndex
//vector<pair<int, int>> result;

void initialize() {
	cin >> videos >> disks;

	prefixSum[0] = 0;
	for (int i = 1; i <= videos; i++) {
		cin >> rawdata[i];
		prefixSum[i] = prefixSum[i - 1] + rawdata[i];
	}

	pq.push({ prefixSum[videos], 1, videos });
}

void operate() {
	vector<int> divided;

	int from, to, leftSum, rightSum, mid;
	for (int made = 1; made < disks; made++) { //만들어진 블루레이 개수
		from = pq.top().from; to = pq.top().to; pq.pop();

		mid = (from + to) / 2;
		leftSum = MAKESUM(from, mid); rightSum = MAKESUM(mid + 1, to);

		if (from + 1 == to) {
			divided.push_back(mid);
			continue; //1개 짜리는 더 이상 나눌 수 없기에, 힙에 넣지 않는다.
		}

		if (leftSum > rightSum) { //왼쪽 반쪽이 더 큰 경우, 오른쪽 반쪽이 '왼쪽 반쪽의 오른쪽 끝 동영상'을 가져갈 수 있는지 본다.
			while (rightSum + rawdata[mid] < leftSum) {
				rightSum += rawdata[mid];
				leftSum -= rawdata[mid];
				mid--;
			}
		}
		else if (leftSum < rightSum) { //오른쪽 반쪽이 더 큰 경우, 왼쪽 반쪽이 '오른쪽 반쪽의 왼쪽 끝 동영상'을 가져갈 수 있는지 본다.
			while (leftSum + rawdata[mid + 1] < rightSum) {
				leftSum += rawdata[mid + 1];
				rightSum -= rawdata[mid + 1];
				mid++;
			}
		}

		pq.push({ leftSum, from, mid });
		pq.push({ rightSum, mid + 1,to });
		divided.push_back(mid);
	}

	sort(divided.begin(), divided.end());

	int ans = -1;
	from = 1;
	for (auto it : divided) {
		ans = max(ans, MAKESUM(from, it));
		from = it + 1;
	}
	ans = max(ans, MAKESUM(from, videos));

	cout << ans << endl;
}

//void operate() {
//	int ans = -1;
//	bool changed = true;
//
//	while (changed) {
//		changed = false;
//
//		for (int i = 0; i < result.size() - 1; i++) {
//			if (result[i].second + rawdata[result[i].first + 1] < result[i + 1].second) {
//				result[i].first++;
//				result[i].second += rawdata[result[i].first];
//				result[i + 1].second -= rawdata[result[i].first];
//				changed = true;
//			}
//		}
//	}
//
//	for (int i = 0; i < result.size(); i++) {
//		ans = max(ans, result[i].second);
//	}
//
//	cout << ans << endl;
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}

/*
9 3
7 3 2 4 8 1 6 4 5

50 14
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50

답: 105
*/