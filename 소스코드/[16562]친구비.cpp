#include <iostream>
#include <vector>
#include <algorithm>
#define junsuk friends + 1
using namespace std;

vector<int> friendFee;
int friends, rels, money;

int root[10005];

int find_root(int num) {
	if (root[num] < 0) return num;
	return root[num] = find_root(root[num]);
}

void merge_root(int num1, int num2) {
	int root1 = find_root(num1);
	int root2 = find_root(num2);

	if (root1 == root2) return;

	if (friendFee[root1] > friendFee[root2]) swap(root1, root2);

	root[root2] = root1;
}

void initialize() {
	cin >> friends >> rels >> money;

	friendFee.resize(friends + 2);
	for (int i = 1; i <= friends; i++) {
		cin >> friendFee[i];
		root[i] = -1;
	}
	friendFee[junsuk] = -1; //스스로의 친구는 스스로가 되어야 한다!
	root[junsuk] = -1;

	int fr1, fr2;
	for (int i = 0; i < rels; i++) {
		cin >> fr1 >> fr2;
		merge_root(fr1, fr2);
	}
}

void operate() {
	//root[junsuk]은 준석이가 친구를 맺어 가는 루트이다
	int root_temp;
	int used_money = money;

	for (int i = 1; i <= friends; i++) {
		root_temp = find_root(i);

		if (root_temp == junsuk) continue;
		else if (friendFee[root_temp] > used_money) {
			cout << "Oh no" << endl;
			return;
		}
		else {
			merge_root(junsuk, root_temp);
			used_money -= friendFee[root_temp];
		}
	}

	cout << money - used_money << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;

}