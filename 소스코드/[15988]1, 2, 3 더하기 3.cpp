#include <stdio.h>
#pragma warning (disable:4996)
#define MOD 1000000009

int main() {
	unsigned long* rawdata = new unsigned long[1000005];
	rawdata[1] = 1; rawdata[2] = 2; rawdata[3] = 4;

	int test_cases;
	scanf("%d", &test_cases); getchar();

	unsigned long num_in;
	unsigned long local_max = 3; /*local max : 저장된 data의 최대 index를 나타냄*/

	for (int i = 0; i < test_cases; i++) {
		scanf("%ld", &num_in); getchar();
		if (num_in > local_max) {
			while (local_max != num_in) {
				rawdata[local_max + 1] = (rawdata[local_max] + rawdata[local_max - 1] + rawdata[local_max - 2]) % MOD;
				local_max++;
			}
		}
		printf("%ld\n", rawdata[num_in]);
	}

	return 0;
}