#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

char a[55], b[55];

int main() {
	scanf("%s", a); getchar();
	scanf("%s", b); getchar();

	int iter = strlen(b) - strlen(a) + 1;
	int diff = 9999, diff_temp;
	for (int i = 0; i < iter; i++) {
		//a의 시작점을 b의 i에 맞춘다.
		diff_temp = 0;
		for (int j = 0; j < strlen(a); j++) {
			if (a[j] != b[i + j]) diff_temp++;
		}
		if (diff_temp < diff) diff = diff_temp;
	}
	printf("%d\n", diff);
	return 0;
}