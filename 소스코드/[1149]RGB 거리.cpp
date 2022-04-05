#include <stdio.h>
#pragma warning (disable:4996)

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main() {
	int save_matrix[3], in_matrix[3], house;

	scanf("%d", &house); getchar();
	house--; /*첫 집은 save_matrix에 저장한다.*/

	scanf("%d %d %d", &save_matrix[0], &save_matrix[1], &save_matrix[2]); getchar();

	int i, j;
	int prev_1, prev_2; /*save_matrix에서 참조할 index*/
	for (i = 0; i < house; i++) {
		scanf("%d %d %d", &in_matrix[0], &in_matrix[1], &in_matrix[2]); getchar();

		for (j = 0; j < 3; j++) {
			prev_1 = (j + 1) % 3; prev_2 = (j + 2) % 3;
			in_matrix[j] = MIN(save_matrix[prev_1], save_matrix[prev_2]) + in_matrix[j];
		}

		for (j = 0; j < 3; j++) {
			save_matrix[j] = in_matrix[j];
		}
	}

	int print_flag = 0;
	for (i = 0; i < 3; i++) {
		if (!print_flag && save_matrix[i] <= save_matrix[(i + 1) % 3] && save_matrix[i] <= save_matrix[(i + 2) % 3]) {
			printf("%d\n", save_matrix[i]);
			print_flag = 1;
		}
	}

	return 0;
}