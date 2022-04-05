#include <iostream>
#include <string>
#include <deque>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int test_cases;
string opers, rawdata;
int front, back;
int nums;

void initialize() {
	getline(cin, opers); 

	cin >> nums; cin.get();

	getline(cin, rawdata); 

	front = 0; back = nums - 1;
}

void operate() {
	int len_opers = opers.length();
	bool dir = true; //true : 정방향 작업, false : 역방향 작업

	for (int i = 0; i < len_opers; i++) {
		if (opers[i] == 'R') dir = !dir;
		else {
			if (back < front) {
				cout << "error" << endl;
				return;
			}
			if (dir == true) front++;
			else back--;
		}
	}

	int iter = back - front + 1;
	int idx_start, idx_fin, dq_front;

	cout << '[';
	if (dir == true && iter > 0) {
		idx_start = 1;
		
		dq_front = front;
		for (int cnt = 0; cnt < dq_front; cnt++, idx_start++) {
			while (rawdata[idx_start] != ',') idx_start++;
		}

		for (int i = 0; i < iter; i++) {
			idx_fin = idx_start;
			while (rawdata[idx_fin + 1] != ',' && rawdata[idx_fin + 1] != ']') idx_fin++;

			cout << rawdata.substr(idx_start, idx_fin - idx_start + 1);
			if (i < iter - 1) cout << ',';

			idx_start = idx_fin = idx_fin + 2;
		}

	}
	else if (dir == false && iter > 0) {
		idx_fin = rawdata.length() - 2;
		
		dq_front = back;
		for (int cnt = 0; cnt < nums - dq_front - 1; cnt++, idx_fin--) {
			while (rawdata[idx_fin] != ',') idx_fin--;
		}

		for (int i = 0; i < iter; i++) {
			idx_start = idx_fin;
			while (rawdata[idx_start - 1] != ',' && rawdata[idx_start - 1] != '[') idx_start--;

			cout << rawdata.substr(idx_start, idx_fin - idx_start + 1);
			if (i < iter - 1) cout << ',';

			idx_start = idx_fin = idx_start - 2;
		}
	}
	cout << ']' << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> test_cases; cin.get();
	for (int i = 0; i < test_cases; i++) {
		initialize();
		operate();
	}
	
	return 0;
}

/*
4
RRDD
7
[10,1,50,88,4,9,2]
RDD
7
[10,1,50,88,4,9,2]


1
DDD
4
[1,2,3,4]

1
RDDD
4
[21,88,9,41]
*/