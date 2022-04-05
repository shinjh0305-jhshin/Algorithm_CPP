#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int dp[22][22][22] = { 0 };

int operate(int a, int b, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	
	while (1) {
		cin >> a >> b >> c; cin.get();

		if (a == -1 && b == -1 && c == -1) break;
		
		cout << "w(" << a << ", " << b << ", " << c << ") = " << operate(a, b, c) << endl;
	}
}

int operate(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) return operate(20, 20, 20);

	if (dp[a][b][c] != 0) return dp[a][b][c];

	if (a < b && b < c) return dp[a][b][c] = operate(a, b, c - 1) + operate(a, b - 1, c - 1) - operate(a, b - 1, c);
	else return dp[a][b][c] = operate(a - 1, b, c) + operate(a - 1, b - 1, c) + operate(a - 1, b, c - 1) - operate(a - 1, b - 1, c - 1);
}