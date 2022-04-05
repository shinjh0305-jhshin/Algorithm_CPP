#include <stdio.h>
#pragma warning (disable:4996)

struct node {
	int num;
	int sum;
	int from; /*for backtracking*/
};

class operate {
private:
	int len;
	int max_end; /*최대 합의 종점*/
	int max_sum; /*최대 합*/
	node* arr;
public:
	operate() : len(0), arr(NULL), max_end(0), max_sum(0){};
	~operate() {
		delete[] arr;
	}

	void get_num() {
		scanf("%d", &len); getchar();
		arr = new node[len];
	}

	void get_max_sum() {
		int in_num, sum_temp;
		for (int i = 0; i < len; i++) {

			scanf("%d", &in_num);
			arr[i].num = in_num;
			if (i == 0) {
				arr[0].from = 0;
				arr[0].sum = max_sum = in_num;
				continue;
			}

			sum_temp = arr[i - 1].sum + in_num;
			if (in_num >= sum_temp) {
				arr[i].from = i;
				arr[i].sum = in_num;
			}
			else {
				arr[i].from = arr[i - 1].from;
				arr[i].sum = sum_temp;
			}

			if (arr[i].sum > max_sum) {
				max_end = i;
				max_sum = arr[i].sum;
			}
		}
	}

	void print_result() {
		printf("%d\n", max_sum);
		
		///*backtracking 출력*/
		//int start = arr[max_end].from;
		//for (int i = start; arr[i].from == start; i++) {
		//	printf("%d ", arr[i].num);
		//}
		//printf("\n");
	}
};

int main() {
	operate op;
	op.get_num();
	op.get_max_sum();
	op.print_result();

	return 0;
}