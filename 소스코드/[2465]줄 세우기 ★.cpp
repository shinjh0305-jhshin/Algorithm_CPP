#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

/*
전략
1. 키 집합을 오름차순으로 정렬한다
2. 수열 S의 맨 뒤부터 시작한다.
3-1. 세그트리는 현재 키 집합 구간에서 사용한 키의 개수다
3-2. 수열 S의 맨 뒤의 개수가 나올 수 있는 키의 값을 찾는다.
3-3. 해당 키를 포함하는 세그트리의 구간을 전부 더한다
*/

//펜윅트리로는 구현하기 힘들 것 같다
int sz_rawdata;
int heightData[100003], orderData[100003], result[100003], segTree[400012];

void update(int target, int left = 1, int right = sz_rawdata, int idx = 1) {
	if (left <= target && target <= right) segTree[idx]++;
	else return;

	if (left == right) return;

	int mid = (left + right) / 2;
	update(target, left, mid, idx * 2);
	update(target, mid + 1, right, idx * 2 + 1);
}

int getIdx(int targetOrder, int left = 1, int right = sz_rawdata, int idx = 1, int sum = 0) {
	if (left == right) return right;
	int used = segTree[idx]; //left에서 right까지 키 중에서 사용한 키의 개수
	int avail = sum + (right - left + 1 - used); //현재 구간에서 사용할 수 있는 키의 개수

	int mid = (left + right) / 2;
	int leftAvail = mid - left + 1 - segTree[2 * idx];
	int newSum = sum + leftAvail; //왼쪽 절반에서 사용할 수 있는 수

	if (newSum >= targetOrder) return getIdx(targetOrder, left, mid, idx * 2, sum); //왼쪽 절반 구간을 검토한다.
	else return getIdx(targetOrder, mid + 1, right, idx * 2 + 1, newSum);
}

void initialize() {
	cin >> sz_rawdata;
	for (int i = 1; i <= sz_rawdata; i++) {
		cin >> heightData[i];
	}
	for (int i = 1; i <= sz_rawdata; i++) {
		cin >> orderData[i];
	}

	sort(heightData + 1, heightData + sz_rawdata + 1);
}

void operate() {
	int target;
	for (int i = sz_rawdata; i > 0; i--) {
		target = getIdx(orderData[i] + 1);
		result[i] = heightData[target];
		update(target);
	}

	for (int i = 1; i <= sz_rawdata; i++) {
		cout << result[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}