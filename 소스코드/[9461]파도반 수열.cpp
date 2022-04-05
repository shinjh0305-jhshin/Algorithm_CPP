#include <iostream>
#include <vector>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int testcases, max = 5;
	cin >> testcases; cin.get();

	vector<long long> vec;
	vec.push_back(0);
	vec.push_back(1); //P(1)
	vec.push_back(1); //P(2)
	vec.push_back(1); //P(3)
	vec.push_back(2); //P(4)
	vec.push_back(2); //P(5)

	int num_in;
	for (int i = 0; i < testcases; i++) {
		cin >> num_in; cin.get();
		if (num_in > max) {
			while (max != num_in) {
				vec.push_back(vec[max] + vec[max - 4]);
				max++;
			}
		}
		cout << vec[num_in] << endl;
	}
	return 0;
}