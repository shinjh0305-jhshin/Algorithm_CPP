#include <stdio.h>
#pragma warning (disable:4996)
long long mod = 1e9;

int main() {
	int num, components;
	scanf("%d %d", &num, &components);

	long long** arr = new long long*[components + 1];
	int i, j;
	for (i = 0; i <= components + 1; i++) {
		*(arr + i) = new long long[num + 1];
	}

	for (i = 0; i <= 1; i++) {
		for (j = 0; j <= num; j++) {
			arr[i][j] = i;
		}
	}

	for (i = 2; i <= components; i++) {
		arr[i][0] = 1;
		for (j = 1; j <= num; j++) {
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % mod;
		}
	}

	printf("%lld\n", arr[components][num]);
	return 0;
}