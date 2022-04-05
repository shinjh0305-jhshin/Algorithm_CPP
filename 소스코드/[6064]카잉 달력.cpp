#include <stdio.h>
#pragma warning (disable:4996)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int operate(int freq1, int freq2, int target1, int target2);

int main() {
	int test_case;
	scanf("%d", &test_case); getchar();

	int M, N, x, y, result;
	for (int i = 0; i < test_case; i++) {
		scanf("%d %d %d %d", &M, &N, &x, &y); getchar();
		if (M == MAX(M, N)) result = operate(M, N, x, y);
		else result = operate(N, M, y, x);

		printf("%d\n", result);
	}
	return 0;
}

int operate(int freq1, int freq2, int target1, int target2) {
	//freq1 : M,N 중 더 큰 수, target 1 : freq1을 주기로 갖는 년도 데이터
	int year = 0, target2_temp;
	for (int i = 0;; i++) {
		year = freq1 * i;
		if (year && year % freq2 == 0) return -1;
		year += target1;

		target2_temp = (year - 1) % freq2 + 1;
		if (target2_temp == target2) return year;
	}
}