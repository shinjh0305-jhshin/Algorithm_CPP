#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct info {
	int x1, y1, x2, y2;
};
info rawdata[1003];
int root[1003];
int squares;

void initialize() {
	cin >> squares;
	rawdata[0].x1 = rawdata[0].y1 = rawdata[0].x2 = rawdata[0].y2 = 0; //초기 원점 포함
	root[0] = -1;

	for (int i = 1; i <= squares; i++) {
		cin >> rawdata[i].x1 >> rawdata[i].y1 >> rawdata[i].x2 >> rawdata[i].y2;
		root[i] = -1;
	}
}

int findRoot(int num) {
	if (root[num] < 0) return num;
	return root[num] = findRoot(root[num]);
}

void mergeRoot(int num1, int num2) {
	int root1 = findRoot(num1);
	int root2 = findRoot(num2);

	if (root1 == root2) return;

	if (root[root1] > root[root2]) swap(root1, root2);

	root[root1] += root[root2];
	root[root2] = root1;
}

bool doesIntersect(int sq1, int sq2) {
	info& s1 = rawdata[sq1];
	info& s2 = rawdata[sq2];

	if (s1.x1 < s2.x1 && s1.y1 < s2.y1 && s2.x2 < s1.x2 && s2.y2 < s1.y2) return false;
	if (s2.x1 < s1.x1 && s2.y1 < s1.y1 && s1.x2 < s2.x2 && s1.y2 < s2.y2) return false;
	if (s1.x2 < s2.x1 || s1.y2 < s2.y1 || s2.x2 < s1.x1 || s2.y2 < s1.y1) return false;

	return true;
}

void operate() {
	for (int i = 0; i < squares; i++) {
		for (int j = i + 1; j <= squares; j++) {
			if (doesIntersect(i, j)) {
				mergeRoot(i, j);
			}
		}
	}

	set<int> s;
	for (int i = 0; i <= squares; i++) {
		s.insert(findRoot(i));
	}

	cout << s.size() - 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}