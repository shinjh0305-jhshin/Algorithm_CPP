#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rawdata[100003];
int videos, disks;
vector<pair<int, int>> result;

void initialize() {
	cin >> videos >> disks;

	int sum = 0;
	for (int i = 0; i < videos; i++) {
		cin >> rawdata[i];
		sum += rawdata[i];
	}

	int dividedSum = sum / disks; //걍 1/n한 값. 이 값 이하로 들게 우선 잘라놓는다.

	sum = 0;
	for (int i = 0; i < videos; i++) {
		sum += rawdata[i];
		if (sum + rawdata[i + 1] > dividedSum) { //다음 강의까지 들어가면 불공평해진다.
			result.push_back({ i, sum });
			sum = 0;

			if (result.size() == disks - 1) { //다음 디스크가 마지막 디스크면 무조건 전부 집어넣는다.
				for (int j = i + 1; j < videos; j++) sum += rawdata[j]; 
				result.push_back({ videos - 1, sum });
				break;
			}
		}
	}
}

void operate() {
	int ans = -1;
	bool changed = true;

	while (changed) {
		changed = false;

		for (int i = 0; i < result.size() - 1; i++) {
			if (result[i].second + rawdata[result[i].first + 1] < result[i + 1].second) {
				result[i].first++;
				result[i].second += rawdata[result[i].first];
				result[i + 1].second -= rawdata[result[i].first];
				changed = true;
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		ans = max(ans, result[i].second);
	}

	cout << ans << endl;
}

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
*/