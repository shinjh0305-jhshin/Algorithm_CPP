#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int add, sub, mul, div;
};
struct ret {
	int maxResult, minResult;
};

vector<int> nums;
info op;
int sz_num;

void initialize() {
	cin >> sz_num;
	nums.resize(sz_num);

	for (int i = 0; i < sz_num; i++) {
		cin >> nums[i];
	}

	cin >> op.add >> op.sub >> op.mul >> op.div;
}

ret operate(int num, int idx) {
	int maxResult = -1234567890, minResult = 1234567890;
	ret temp;

	if (op.add) {
		op.add--;
		if (idx < sz_num - 1) temp = operate(num + nums[idx], idx + 1);
		else temp.maxResult = temp.minResult = num + nums[idx];
		op.add++;

		maxResult = max(maxResult, temp.maxResult);
		minResult = min(minResult, temp.minResult);
	}
	if (op.sub) {
		op.sub--;
		if (idx < sz_num - 1) temp = operate(num - nums[idx], idx + 1);
		else temp.maxResult = temp.minResult = num - nums[idx];
		op.sub++;

		maxResult = max(maxResult, temp.maxResult);
		minResult = min(minResult, temp.minResult);
	}
	if (op.mul) {
		op.mul--;
		if (idx < sz_num - 1) temp = operate(num * nums[idx], idx + 1);
		else temp.maxResult = temp.minResult = num * nums[idx];
		op.mul++;

		maxResult = max(maxResult, temp.maxResult);
		minResult = min(minResult, temp.minResult);
	}
	if (op.div) {
		op.div--;
		if (idx < sz_num - 1) temp = operate(num / nums[idx], idx + 1);
		else temp.maxResult = temp.minResult = num / nums[idx];
		op.div++;

		maxResult = max(maxResult, temp.maxResult);
		minResult = min(minResult, temp.minResult);
	}

	return { maxResult, minResult };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	ret result = operate(nums[0], 1);

	cout << result.maxResult << endl;
	cout << result.minResult << endl;
	return 0;
}