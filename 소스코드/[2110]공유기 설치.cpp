#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class router {
private:
	int houses, routers;
	vector<int> location;

public:
	void initialize() {
		cin >> houses >> routers;

		int num_in;

		for (int i = 0; i < houses; i++) {
			cin >> num_in;
			location.push_back(num_in);
		}

		sort(location.begin(), location.end());
	}

	void operate() {
		//front, mid : 이격하는 거리 저장됨,  mid : 거리 저장됨
		int front = 1, back = location[houses - 1] - location[0], mid;

		// installed : 설치된 공유기의 개수, prev_installed : 직전에 공유기가 설치된 집의 index
		// result : 최대 이격거리
		int installed, prev_installed, result = 0;

		while (front <= back) {
			mid = (front + back) / 2;
			installed = 1; prev_installed = 0;
			for (int mov = 1; mov < houses; mov++) {
				if (location[mov] - location[prev_installed] >= mid) {
					installed++;
					prev_installed = mov;
				}
			}

			if (installed >= routers) {
				result = max(result, mid);
				front = mid + 1;
			}
			else back = mid - 1;
		}

		cout << result << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	router op;
	op.initialize();
	op.operate();
	return 0;
}
