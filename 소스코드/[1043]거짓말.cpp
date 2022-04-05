#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

vector<int> parties[52]; //각 파티에 참석한 사람들 모음
vector<int> knowTruth; //진실을 원래부터 알았던 사람들
vector<int> newknowTruth; //파티 종료 후 진실을 알고 있는 사람들
int root[52];
int height[52];
int ppl, truthPpl, numParty;

void initialize() {
	cin >> ppl >> numParty;
	cin >> truthPpl;
	knowTruth.resize(truthPpl);

	for (int i = 0; i < truthPpl; i++) {
		cin >> knowTruth[i];
	}

	int peoples;
	for (int i = 0; i < numParty; i++) {
		cin >> peoples;
		parties[i].resize(peoples);

		for (int j = 0; j < peoples; j++) {
			cin >> parties[i][j];
		}
	}

	for (int i = 1; i <= ppl; i++) {
		root[i] = i;
		height[i] = 1;
	}
}

int find_root(int num) {
	if (root[num] == num) return num;
	return root[num] = find_root(root[num]);
}

void merge(int num1, int num2) {
	int root1 = find_root(num1);
	int root2 = find_root(num2);

	if (root1 == root2) return;
	if (height[root2] > height[root1]) swap(root1, root2);

	root[root2] = root1;

	if (height[root1] == height[root2]) height[root1]++;
}

void makeGroup(int idx) {
	int szparty = parties[idx].size();

	for (int i = 1; i < szparty; i++) {
		merge(parties[idx][i - 1], parties[idx][i]);
	}
}

void makeNewknowTruth() { //파티 때 진실을 들은 사람들을 저장한다.
	for (int i = 1; i <= ppl; i++) {
		for (int j = 0; j < truthPpl; j++) {
			if (find_root(i) == find_root(knowTruth[j])) newknowTruth.push_back(i);
		}
	}
}

void findCanLie() {
	bool status;
	int ret = 0, szparty;
	
	for (int i = 0; i < numParty; i++) {
		status = true;
		szparty = parties[i].size();
		
		for (int j = 0; j < szparty; j++) {
			if (find(newknowTruth.begin(), newknowTruth.end(), parties[i][j]) != newknowTruth.end()) {
				status = false;
				break;
			} 
		}

		if (status == true) ret++;
	}

	cout << ret << endl;
}

void operate() {
	for (int i = 0; i < numParty; i++) {
		if (parties[i].size() >= 2) makeGroup(i);
	}

	makeNewknowTruth();
	findCanLie();
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	operate();

	return 0;
}