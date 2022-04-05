#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));

	int tot_num;
	for (int i = 0; i < 10; i++) {
		tot_num = rand() % 50;
		printf("%d\n", tot_num);
		for (int j = 0; j < tot_num; j++) {
			printf("%d ", rand() % 101);
		}
		printf("\n");
	}
}