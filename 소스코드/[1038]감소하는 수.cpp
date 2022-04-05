#include <iostream>
#include <queue>	
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

void operate() {
	int rawdata[11][10]; //행 : 자릿수, 열 : MSD
	int target, totalSum = 0, digits;
	queue<int> st;

	cin >> target;

	if (target == 0) { cout << 0 << endl; return; }

	rawdata[1][0] = 1;
	for (int i = 1; i < 10; i++) {
		rawdata[1][i] = 1; 
		totalSum++;

		if (totalSum == target) {
			cout << i << endl;
			return;
		}
	}

	for (int i = 2; i <= 10; i++) {
		rawdata[i][0] = 0;
		for (int j = 1; j < 10; j++) {
			rawdata[i][j] = rawdata[i - 1][j - 1] + rawdata[i][j - 1]; //현재 자릿수(i)의 MSD가 j일 때 만들 수 있는 숫자의 개수

			if (totalSum + rawdata[i][j] < target) totalSum += rawdata[i][j]; //현재 작업중인 MSD로 target에 도달하지 못하면 계속 진행한다.
			else {// 현재 작업중인 MSD를 갖는 숫자가 우리가 찾는 숫자이다. 
				st.push(j); //MSD를 push 한다.
				digits = i; //자릿수를 keep 해놓는다.
				goto backtrack;
			} 
		}
	}

	if (st.empty()) { //target 번째 감소하는 숫자는 존재하지 않는다.
		cout << -1 << endl;
		return;
	}

backtrack:;
	for (int curdigit = digits - 1; curdigit >= 1; curdigit--) { //MSD부터 LSD로 가면서 차례대로 살펴본다.
		for (int temp = 0; temp < 10; temp++) {
			if (totalSum + rawdata[curdigit][temp] < target) totalSum += rawdata[curdigit][temp];
			else {
				st.push(temp);
				break;
			}
		}
	}

	while (!st.empty()) {
		cout << st.front();
		st.pop();
	}
	cout << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	operate();
	return 0;
}