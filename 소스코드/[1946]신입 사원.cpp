#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class employee {
private:
	struct info {
		int application;
		int interview;
	};
	int cases, ppls;
	vector<info> rawdata;

public:
	void initialize() {
		cin >> cases; cin.get();
	}

	static bool compare(const info &a, const info &b) {
		if (a.application < b.application) return true;
		else if (a.application == b.application) {
			if (a.interview < b.interview) return true;
		}

		return false;
	}

	void operate() {
		int app, inter;

		for (int i = 0; i < cases; i++) {
			rawdata.clear();
			cin >> ppls; cin.get();

			for (int j = 0; j < ppls; j++) {
				cin >> app >> inter; cin.get();
				rawdata.push_back({ app,inter });
			}

			sort(rawdata.begin(), rawdata.end(), compare);

			int min = rawdata[0].interview;
			int ans = 1;

			for (int j = 1; j < rawdata.size(); j++) {
				if (rawdata[j].interview <= min) {
					min = rawdata[j].interview;
					ans++;
				}
			}

			cout << ans << endl;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	employee op;
	op.initialize();
	op.operate();

	return 0;
}