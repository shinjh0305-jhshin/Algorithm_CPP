#include <iostream>
#include <algorithm>
#define endl "\n"
#define NUM_MAX 98765432
#pragma warning (disable:4996)
using namespace std;

class atob {
private:
	long long ori_num, target_num;
	int result = NUM_MAX;

public:
	void initialize() {
		cin >> ori_num >> target_num;
	}

	void dfs(long long num, int op_num) { //op_num : num을 구하기 위해 진행한 연산 개수
		long long candid1 = num * 2;
		long long candid2 = num * 10 + 1;
		op_num++;

		if (candid1 == target_num || candid2 == target_num) {
			result = min(result, op_num);
			return;
		}
		else if (op_num == result) return;
		else {
			if (candid1 < target_num) dfs(candid1, op_num);
			if (candid2 < target_num) dfs(candid2, op_num);
		}
	}

	void operate() {
		//문제요구조건 : op_num 1부터 시작
		dfs(ori_num, 1);
		if (result == NUM_MAX) cout << -1 << endl;
		else cout << result << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	atob op;
	op.initialize();
	op.operate();
	return 0;
}