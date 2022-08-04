#include <iostream>
#define endl "\n"
using namespace std;

bool operate(int casenum) {
	int L, P, V;

	cin >> L >> P >> V;
	if (L == 0) return false;

	int complete = V / P;
	int residual = V % P;

	int sum = complete * L;
	sum += residual > L ? L : residual;

	cout << "Case " << casenum << ": " << sum << endl;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases = 1;
	while (operate(cases++));

	return 0;
}