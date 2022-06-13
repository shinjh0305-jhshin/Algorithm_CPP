#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

struct line {
	double x1, x2, y1, y2;
};
int root[3003], sz_rawdata;
vector<line> rawdata;

double getCCW(double x1, double y1, double x2, double y2, double x3, double y3) {
	return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
}

bool isConnected(line& L1, line& L2) {
	double x1 = L1.x1, x2 = L1.x2, y1 = L1.y1, y2 = L1.y2;
	double x3 = L2.x1, x4 = L2.x2, y3 = L2.y1, y4 = L2.y2;

	double abc = getCCW(x1, y1, x2, y2, x3, y3);
	double abd = getCCW(x1, y1, x2, y2, x4, y4);
	double acd = getCCW(x1, y1, x3, y3, x4, y4);
	double bcd = getCCW(x2, y2, x3, y3, x4, y4);

	if (abc * abd == 0 && acd * bcd == 0) {
		double maxX1 = max(x1, x2), maxY1 = max(y1, y2), maxX2 = max(x3, x4), maxY2 = max(y3, y4);
		double minX1 = min(x1, x2), minY1 = min(y1, y2), minX2 = min(x3, x4), minY2 = min(y3, y4);

		if (maxX1 >= minX2 && maxY1 >= minY2 && maxX2 >= minX1 && maxY2 >= minY1) {
			return true;
		}
		else return false;
	}
	else if (abc * abd <= 0 && acd * bcd <= 0) return true;
	else return false;
}

int getRoot(int num) {
	if (root[num] < 0) return num;
	else return root[num] = getRoot(root[num]);
}

void mergeRoot(int num1, int num2) {
	int root1 = getRoot(num1);
	int root2 = getRoot(num2);

	if (root1 == root2) return;

	if (root1 > root2) swap(root1, root2);
	root[root1] += root[root2];
	root[root2] = root1;
}

void initialize() {
	cin >> sz_rawdata;
	for (int i = 0; i < sz_rawdata; i++) {
		root[i] = -1;
	}
}

void operate() {
	line L1;

	for (int i = 0; i < sz_rawdata; i++) {
		cin >> L1.x1 >> L1.y1 >> L1.x2 >> L1.y2;
		for (int mov = 0; mov < i; mov++) {
			if (isConnected(rawdata[mov], L1)) {
				mergeRoot(mov, i);
			}
		}
		rawdata.push_back(L1);
	}

	for (int i = 0; i < sz_rawdata; i++) getRoot(i);

	sort(root, root + sz_rawdata);

	int sz_max = 0, groups = 0;
	for (int i = 0; i < sz_rawdata; i++) {
		if (root[i] < 0) {
			sz_max = max(sz_max, -root[i]);
			groups++;
			continue;
		}
		break;
	}

	cout << groups << endl << sz_max << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}