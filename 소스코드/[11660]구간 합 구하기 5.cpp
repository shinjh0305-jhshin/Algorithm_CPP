#include <iostream>
#define endl "\n"
using namespace std;

int ori[1026][1026];
int sum[1026][1026] = { 0 };
int sz, queries;

void initialize() {
	cin >> sz >> queries;

	int rowSum;
	for (int i = 1; i <= sz; i++) {
		rowSum = 0;
		for (int j = 1; j <= sz; j++) {
			cin >> ori[i][j];
			rowSum += ori[i][j];
			sum[i][j] = sum[i - 1][j] + rowSum;
		}
	}
}

void operate() {
	int row1, col1, row2, col2;
	for (int i = 0; i < queries; i++) {
		cin >> row1 >> col1 >> row2 >> col2;
		cout << sum[row2][col2] - sum[row1 - 1][col2] - sum[row2][col1 - 1] + sum[row1 - 1][col1 - 1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}