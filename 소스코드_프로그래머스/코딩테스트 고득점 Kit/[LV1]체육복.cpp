#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int* hasSuit = new int[n];
	for (int i = 0; i < n; i++) {
		hasSuit[i] = 1;
	}
	for (const auto it : lost) {
		hasSuit[it - 1]--;
	}
	for (const auto it : reserve) {
		hasSuit[it - 1]++;
	}

	for (int i = 0; i < n; i++) {
		if (hasSuit[i] == 0) {
			if (i >= 1 && hasSuit[i - 1] == 2) {
				hasSuit[i - 1]--;
				hasSuit[i]++;
			}
			else if (i <= n - 2 && hasSuit[i + 1] == 2) {
				hasSuit[i + 1]--;
				hasSuit[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (hasSuit[i]) answer++;
	}

	return answer;
}