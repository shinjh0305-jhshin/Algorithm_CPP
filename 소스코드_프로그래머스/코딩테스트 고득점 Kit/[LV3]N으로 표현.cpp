#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

unordered_set<int> numOfLen[9];

bool makeNum(int N, int number, int len) {
	int left = 1, right = len - 1; //left (_) right해서 len개의 N으로 표현되는 숫자가 나온다
	while (left < len) {
		for (const auto leftMov : numOfLen[left]) {
			for (const auto rightMov : numOfLen[right]) {
				numOfLen[len].insert(leftMov + rightMov);
				numOfLen[len].insert(leftMov - rightMov);
				numOfLen[len].insert(leftMov * rightMov);
				if (rightMov) numOfLen[len].insert(leftMov / rightMov);
			}
		}
		left++; right--;
	}

	int blockNum = 0; //NNNN과 같은 같은 숫자가 여러 번 나오는 숫자.
	for (int i = 0; i < len; i++) {
		blockNum += N * pow(10, i);
	}
	numOfLen[len].insert(blockNum);

	if (numOfLen[len].find(number) == numOfLen[len].end()) return false;
	return true;

}

int solution(int N, int number) {
	numOfLen[1].insert(N);

	if (N == number) return 1;
	for (int len = 2; len <= 8; len++) {
		if (makeNum(N, number, len)) {
			return len;
		}
	}

	return -1;
}