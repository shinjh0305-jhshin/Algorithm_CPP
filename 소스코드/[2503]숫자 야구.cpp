#include <iostream>
#include <string>
using namespace std;

string query[103];
int queries;
pair<int, int> ballcount[103]; //strike, ball

bool checkValid(string target) {
	int strike, ball;
	for (int i = 0; i < queries; i++) {
		strike = ball = 0;

		for (int mov = 0; mov < 3; mov++) {
			if (target[mov] == query[i][mov]) strike++;
			else if (query[i].find(target[mov]) != query[i].npos) {
				ball++;
			}
		}

		if (ballcount[i].first != strike || ballcount[i].second != ball) return false;
	}

	return true;
}

void operate() {
	int temp, s, b, ans = 0;

	cin >> queries;

	for (int i = 0; i < queries; i++) {
		cin >> temp >> s >> b;

		query[i] = to_string(temp);
		ballcount[i] = { s, b };
	}


	for (int msd = 1; msd <= 9; msd++) {
		for (int mid = 1; mid <= 9; mid++) {
			for (int lsd = 1; lsd <= 9; lsd++) {
				if (msd == mid || mid == lsd || msd == lsd) continue;
				if (checkValid(to_string(100 * msd + 10 * mid + lsd))) {
					ans++;
				}
			}
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}