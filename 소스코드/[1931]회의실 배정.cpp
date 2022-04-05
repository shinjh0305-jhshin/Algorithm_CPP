#include <iostream>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct ttime {
	int begin, end;
};

class room {
private:
	int sessions;
	ttime sschedule[100005];

public:
	static bool cmp(const ttime& a, const ttime& b) {
		if (a.end == b.end)
			return a.begin < b.begin;
		return a.end < b.end;
	}
	
	void initialize() {
		cin >> sessions; cin.get();
		
		for (int i = 0; i < sessions; i++) {
			cin >> sschedule[i].begin >> sschedule[i].end; cin.get();
		}

		sort(sschedule, sschedule + sessions, cmp);
	}

	void operate() {
		int result = 1;
		int endStart = sschedule[0].end; //이전 회의가 끝나는 시작이자 다음 회의가 시작할 수 있는 시각

		int mov = 1;
		while (mov < sessions) {
			if (sschedule[mov].begin >= endStart) {
				result++;
				endStart = sschedule[mov].end  ;
			}
			mov++;
		}

		cout << result << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	room op;
	op.initialize();
	op.operate();
	return 0;
}