#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class blackjack {
private:
	int cards, target;
	vector<int> rawdata;

public:
	void initialize() {
		int temp;
		cin >> cards >> target; cin.get();
		for (int i = 0; i < cards; i++) {
			cin >> temp; cin.get();
			rawdata.push_back(temp);
		}
	}

	void operate() {
		int temp, ans = 0;

		for (int i = 0; i <= cards - 3; i++) {
			for (int j = i + 1; j <= cards - 2; j++) {
				for (int k = j + 1; k <= cards - 1; k++) {
					temp = rawdata[i] + rawdata[j] + rawdata[k];
					if (temp > target) continue;
					ans = max(ans, temp);
				}
			}
		}

		cout << ans << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	blackjack op;
	op.initialize();
	op.operate();
	return 0;
}