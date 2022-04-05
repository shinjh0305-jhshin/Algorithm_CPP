#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
#define MOD 10007
using namespace std;

class UPnum {
private:
	int saveMatrix[10][2];
	int save_col, lookup_col, target;
public:
	UPnum() {
		save_col = target= 0;
		lookup_col = 1;
	}

	void initialize() {
		cin >> target; cin.get();
		for (int i = 0; i < 10; i++) {
			saveMatrix[i][save_col] = 1;
		}
	}

	void operate() {
		int mov = 2, i;
		while (mov <= target) {
			swap(save_col, lookup_col);
			saveMatrix[9][save_col] = 1;
			for (i = 8; i >= 0; i--) {
				saveMatrix[i][save_col] = (saveMatrix[i][lookup_col] + saveMatrix[i + 1][save_col]) % MOD;
			}
			mov++;
		}
	}

	void print_sum() {
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum = (sum + saveMatrix[i][save_col]) % MOD;
		}
		cout << sum << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	UPnum op;
	op.initialize();
	op.operate();
	op.print_sum();
	return 0;
}