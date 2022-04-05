#include <stdio.h>
#pragma warning(disable:4996)

int maxHeap[100005];
int sz_maxHeap = 0, input_num;

void insert_max_heap(int num) {
	sz_maxHeap++;
	int child = sz_maxHeap;

	while (child != 1 && num > maxHeap[child / 2]) {
		maxHeap[child] = maxHeap[child / 2];
		child /= 2;
	}

	maxHeap[child] = num;
}

int pop_max_heap() {
	int ret = maxHeap[1];
	int temp = maxHeap[sz_maxHeap--];
	int parent = 1, child = 2;

	while (child <= sz_maxHeap) {
		if (child < sz_maxHeap && maxHeap[child] < maxHeap[child + 1]) child++;
		if (temp >= maxHeap[child]) break;
		maxHeap[parent] = maxHeap[child];
		parent = child; child *= 2;
	}
	maxHeap[parent] = temp;
	return ret;
}

int main() {
	int op_num, op, ret;
	scanf("%d", &op_num); getchar();

	for (int i = 0; i < op_num; i++) {
		scanf("%d", &op); getchar();
		if (op == 0) {
			if (sz_maxHeap == 0) printf("0\n");
			else {
				ret = pop_max_heap();
				printf("%d\n", ret);
			}
		}
		else {
			insert_max_heap(op);
		}
	}
}