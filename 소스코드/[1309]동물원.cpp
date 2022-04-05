#include <stdio.h>
#pragma warning (disable:4996)

#define MOD 9901

int main() {
	unsigned long i, N, rawdata[100002] = { 3,7 };

	scanf("%ld", &N);

	for (i = 0; i < N; i++)
	{
		rawdata[i + 2] = (2 * rawdata[i + 1] + rawdata[i]) % MOD;
	}

	printf("%ld\n", rawdata[N - 1] % MOD);
	return 0;
}

// 메모리 초과
//struct node {
//	unsigned long up;
//	unsigned long down;
//};
//
//int main() {
//	unsigned long sz_cage;
//
//	scanf("%ld", &sz_cage);
//
//	if (sz_cage == 1) {
//		printf("%ld\n", sz_cage * 2);
//		return 0;
//	}
//
//	node** rawdata = new node * [sz_cage + 1];
//	for (unsigned long i = 0; i <= sz_cage; i++) {
//		rawdata[i] = new node[sz_cage + 1];
//	}
//
//	for (unsigned long i = 1; i <= sz_cage; i++) {
//		rawdata[1][i].up = 2;
//		rawdata[1][i].down = 2 * (i - 1);
//	}
//
//
//	for (unsigned long i = 2; i <= sz_cage; i++) {
//		for (unsigned long j = 1; j <= sz_cage; j++) {
//			if (j < i) continue;
//			if (j == i) {
//				rawdata[i][j].up = 2; rawdata[i][j].down = 0;
//				continue;
//			}
//			rawdata[i][j].up = (rawdata[i - 1][j - 1].up + 2 * rawdata[i - 1][j - 1].down) % MOD;
//			rawdata[i][j].down = (rawdata[i][j - 1].up + rawdata[i][j - 1].down) % MOD;
//		}
//	}
//
//	int sum = 1;
//	for (unsigned long i = 1; i <= sz_cage; i++) {
//		sum += (rawdata[i][sz_cage].up + rawdata[i][sz_cage].down) % MOD;
//	}
//	sum = sum % MOD;
//
//	printf("%ld\n", sum);
//	return 0;
//}