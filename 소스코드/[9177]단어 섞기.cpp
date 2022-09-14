#include <iostream>
#include <cstring>
#include <string>
#define endl "\n"
using namespace std;

bool impossible[1005][1005];
string one, two, target;
int sz_one, sz_two, sz_target;

void initialize() {
	cin >> one >> two >> target;
	sz_one = one.length();
	sz_two = two.length();
	sz_target = sz_one + sz_two;

	memset(impossible, false, sizeof(impossible));
}

bool DFS(int onePos = 0, int twoPos = 0, int targetPos = 0) {
	if (targetPos == sz_target) return true;
	if (impossible[onePos][twoPos]) return false;
	if (onePos < sz_one && one[onePos] == target[targetPos]) {
		if (DFS(onePos + 1, twoPos, targetPos + 1)) return true;
	}
	if (twoPos < sz_two && two[twoPos] == target[targetPos]) {
		if (DFS(onePos, twoPos + 1, targetPos + 1)) return true;
	}

	impossible[onePos][twoPos] = true;
	return false;
}

void operate(int caseNum) {
	string result;
	if (DFS()) result = "yes";
	else result = "no";

	cout << "Data set " << caseNum << ": " << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases;
	cin >> cases;

	for (int i = 1; i <= cases; i++) {
		initialize();
		operate(i);
	}
}