#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int num, times;
int visited[1000000] = { 0 };

void operate() {
	cin >> num >> times;

	string temp;
	int idx = 1;
	while (1) {
		if (visited[num] == 0) visited[num] = idx++;
		else {
			cout << visited[num] - 1 << endl;
			return;
		}
		temp = to_string(num);

		num = 0;
		for (int i = 0; i < temp.length(); i++) {
			num += pow(temp[i] - '0', times);
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}