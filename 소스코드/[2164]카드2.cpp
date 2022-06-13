#include <iostream>
#include <queue>
using namespace std;

void operate() {
	int num;
	cin >> num;

	queue<int> qu;
	for (int i = 1; i <= num; i++) {
		qu.push(i);
	}

	int temp;
	for (int i = 1; i < num; i++) {
		qu.pop();
		temp = qu.front(); qu.pop();
		qu.push(temp);
	}

	cout << qu.front() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}