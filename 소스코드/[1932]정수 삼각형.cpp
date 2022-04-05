#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable : 4996)
using namespace std;

class int_triangle {
private:
	vector <int>* rawdata;
	int num_triangle;
public:
	void initialize() {
		cin >> num_triangle; 
		rawdata = new vector<int>[num_triangle];

		int i, j, num;
		for (i = 0; i < num_triangle; i++) {
			rawdata[i].reserve(i + 1);
			for (j = 0; j <= i; j++) {
				cin >> num; 
				rawdata[i].push_back(num);
			}
		}
	}

	void maximum() {
		int i, j;
		for (i = 1; i < num_triangle; i++) {
			for (j = 0; j <= i; j++) {
				if (j == 0)
					rawdata[i][0] += rawdata[i - 1][0];
				else if (j == i)
					rawdata[i][i] += rawdata[i - 1][i - 1];
				else
					rawdata[i][j] += max(rawdata[i - 1][j - 1], rawdata[i - 1][j]);
			}
		}

		int max_sum = rawdata[num_triangle - 1][0];
		for (int i = 1; i < num_triangle; i++) {
			max_sum = max(max_sum, rawdata[num_triangle - 1][i]);
		}
		cout << max_sum << endl;
	}

};

int main() {
	ios::sync_with_stdio(false);
	int_triangle op;
	op.initialize();
	op.maximum();
	return 0;
}