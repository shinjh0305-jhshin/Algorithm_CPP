#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

vector<int> failure;
string rawdata;
int sz_string;

void initialize() {
	cin >> sz_string; cin.get();
	getline(cin, rawdata);
	failure.resize(sz_string);
}

void get_failure() {
	int front = 0, rear;

	failure[0] = -1;

	for (rear = 1; rear < sz_string; rear++) {
		while (1) {
			if (rawdata[front] == rawdata[rear]) {
				failure[rear] = front;
				front++;
				break;
			}

			if (front == 0) {
				failure[rear] = -1;
				break;
			}
			else 
				front = failure[front - 1] + 1;
		}
	}

	cout << sz_string - (failure[sz_string - 1] + 1) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	get_failure();

	return 0;
}