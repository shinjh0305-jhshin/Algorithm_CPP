#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

unordered_map<string, int> rawdata;
int test_cases, friends = 0;
int root[200003];

void initialize(int relations) {
	rawdata.clear();
	friends = 0;

	int maxsize = 2 * relations;

	for (int i = 0; i < maxsize; i++) 		
		root[i] = -1;
}

void make_idx(int& fr1_idx, int& fr2_idx) {
	string fr1, fr2;

	cin >> fr1 >> fr2;

	if (rawdata.find(fr1) == rawdata.end()) {
		rawdata.insert({ fr1, friends });
		fr1_idx = friends++;
	}
	else fr1_idx = rawdata[fr1];

	if (rawdata.find(fr2) == rawdata.end()) {
		rawdata.insert({ fr2, friends });
		fr2_idx = friends++;
	}
	else fr2_idx = rawdata[fr2];
}

int find_root(int num) {
	if (root[num] < 0) return num;

	return root[num] = find_root(root[num]);
}

int merge_root(int num1, int num2) {
	int root1 = find_root(num1);
	int root2 = find_root(num2);

	if (root1 == root2) return -root[root1];

	if (root[root1] > root[root2]) swap(root1, root2);

	root[root1] += root[root2];
	root[root2] = root1;

	return -root[root1];
}

void operate() {
	int fr1_idx, fr2_idx, relations;
	
	cin >> relations;

	initialize(relations); //테스트케이스 바뀔 때 이전 정보를 초기화시킨다.

	for (int i = 0; i < relations; i++) {
		make_idx(fr1_idx, fr2_idx);
		cout << merge_root(fr1_idx, fr2_idx) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> test_cases;
	for (int i = 0; i < test_cases; i++) {
		operate();
	}

	return 0;
}

/*
1
3
alpha bravo
charlie delta
echo foxtrot

ans:2 2 2

1
3
alpha bravo
bravo charlie
charlie delta

ans : 2 3 4

1
3
Fred Barney
Barney Betty
Betty Wilma

ans:2 3 4

1
3
Fred Barney
Betty Wilma
Barney Betty

ans:2 2 4

1
5
alpha bravo
bravo charlie
echo foxtrot
delta echo
bravo foxtrot

ans : 2 3 2 3 6

1
3
alpha bravo
bravo charlie
alpha charlie

ans : 2 3 3
*/