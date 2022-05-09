#include <iostream>
#define endl "\n"
using namespace std;

int rawdata[1000004] = { 0 }; //index : 사탕의 맛
int segTree[4000008] = { 0 }; //값 : 해당 구간에 포함되는 맛을 가진 사탕의 개수

void insertCandy(int left, int right, int idx, int target, int size) {
	if (right < target || target < left) return;
	segTree[idx] += size;
	if (left == right) return;

	int mid = (left + right) / 2;
	insertCandy(left, mid, idx * 2, target, size);
	insertCandy(mid + 1, right, idx * 2 + 1, target, size);
}

int withdrawCandy(int left, int right, int idx, int target, int sum) { //sum : 누적 합, target : 몇 순위 사탕을 뺄지
	segTree[idx]--; //현재 구간에 타깃 사탕이 들어 있다.
	if (left == right) return left; 

	int mid = (left + right) / 2;
	if (sum + segTree[idx * 2] >= target) { //index가 작은 쪽 절반으로 이동한다.
		return withdrawCandy(left, mid, idx * 2, target, sum);
	}
	else {
		sum += segTree[idx * 2];
		return withdrawCandy(mid + 1, right, idx * 2 + 1, target, sum);
	}
}

void operate() {
	int queries;
	cin >> queries;

	int op, target, size;
	for (int i = 0; i < queries; i++) {
		cin >> op;
		if (op == 1) { //사탕 제거
			cin >> target;
			cout << withdrawCandy(1, 1000000, 1, target, 0) << endl;
		}
		else { //사탕 추가(혹은 제거)
			cin >> target >> size;
			insertCandy(1, 1000000, 1, target, size);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}

/*
100
2 5 3
2 2 4
2 3 4
2 2 -2
1 8
1 6
1 6
1 2
1 2
1 2


*/