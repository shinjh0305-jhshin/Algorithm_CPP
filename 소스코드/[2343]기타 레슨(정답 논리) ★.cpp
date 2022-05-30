#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int rawdata[100003];
int videos, disks;

void operate() {
	cin >> videos >> disks;

	int sum = 0;
	for (int i = 0; i < videos; i++) {
		cin >> rawdata[i];
		sum += rawdata[i];
	}

	int left = *max_element(rawdata, rawdata + videos), right = sum, mid, cnt;

	while (left <= right) {
		mid = (left + right) / 2;

		sum = 0; cnt = 0; //mid의 길이로 자를 때 나오는 디스크 개수
		for (int i = 0; i < videos; i++) {
			if (sum + rawdata[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += rawdata[i];
		}
		cnt++; //마지막 디스크!

		if (cnt > disks) left = mid + 1;
		else right = mid - 1;
	}

	cout << left << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}