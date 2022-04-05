#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int capacity = 10;
int front = capacity - 1, rear = capacity - 1;
int* queue = NULL;
void queueFull();

int compare(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

void addq(int num) {
	rear = (rear + 1) % capacity;
	if (front == rear) { 
		queueFull();
	}
	queue[rear] = num;
}

int deleteq() {
	if (front == rear) return -1;
	front = (front + 1) % capacity;
	return queue[front];
}

void copy(int* start, int* end, int* src) {
	int* mov = start, *dest = src;
	for (; mov != end; mov++, dest++) {
		*dest = *mov;
	}
}

void queueFull() {
	int* newqueue = (int*)malloc(sizeof(int) * 2 * capacity);

	int start = (front + 1) % capacity;
	if (start < 2) {
		copy(queue + start, queue + start + capacity - 1, newqueue);
	}
	else {
		copy(queue + start, queue + capacity, newqueue);
		copy(queue, queue + rear + 1, newqueue + capacity - start);
	}

	front = 2 * capacity - 1;
	rear = capacity - 1;
	capacity *= 2;
	free(queue);
	queue = newqueue;
}

int main() {
	queue = (int*)malloc(sizeof(int)*capacity);
	int test_cases;
	scanf("%d", &test_cases); getchar();
	
	int sz_data, target_index;
	int* stack = NULL;
	int stack_mov, num_in, queue_front, cnt;

	for (int i = 0; i < test_cases; i++) {
		cnt = 0;
		scanf("%d %d", &sz_data, &target_index);
		stack = (int*)malloc(sizeof(int)*sz_data);

		for (stack_mov = 0; stack_mov < sz_data; stack_mov++) {
			scanf("%d", &num_in); getchar();
			addq(num_in); stack[stack_mov] = num_in;
		}

		qsort(stack, sz_data, sizeof(int), compare);
		stack_mov = 0;

		while (1) {
			queue_front = deleteq();
			if (queue_front == stack[stack_mov]) { //max값인 경우
				if (target_index == 0) break; //임시.
				else {
					cnt++;
					target_index--;
					stack_mov++;
				}
			}
			else {
				addq(queue_front);
				if (target_index != 0) target_index--;
				else target_index = (sz_data - stack_mov) - 1;
			}
		}
		cnt++;
		printf("%d\n", cnt);
		free(stack);
		while (front != rear) {
			deleteq();
		}
	}
}