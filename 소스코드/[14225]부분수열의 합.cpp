#include <iostream>
#define endl "\n"
using namespace std;

int nums;
int rawdata[22];
bool visited[2000003] = { false };

void DFS(int idx, int sum) {
	visited[sum] = true;

	if (idx < nums) {
		DFS(idx + 1, sum + rawdata[idx]);
		DFS(idx + 1, sum);
	}
}

void initialize() {
	cin >> nums;
	for (int i = 0; i < nums; i++) {
		cin >> rawdata[i];
	}
}

void operate() {
	DFS(0, 0);

	for (int i = 1;; i++) {
		if (!visited[i]) {
			cout << i << endl;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}