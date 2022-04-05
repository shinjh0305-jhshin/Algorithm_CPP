#include <stdio.h>
#pragma warning(disable:4996)

int minHeap[50005], maxHeap[50005];
int rawdata[100005];
int sz_minHeap = 0, sz_maxHeap = 0, input_num;

void insert_min_heap(int num) {
	sz_minHeap++;
	int child = sz_minHeap, parent = sz_minHeap / 2;

	while (parent && num < minHeap[parent]) {
		minHeap[child] = minHeap[parent];
		child = parent;
		parent = child / 2;
	}

	minHeap[child] = num;
}

void insert_max_heap(int num) {
	sz_maxHeap++;
	int child = sz_maxHeap, parent = sz_maxHeap / 2;

	while (parent && num > maxHeap[parent]) {
		maxHeap[child] = maxHeap[parent];
		child = parent;
		parent = child / 2;
	}

	maxHeap[child] = num;
}

int pop_min_heap() {
	int ret = minHeap[1];
	int temp = minHeap[sz_minHeap--];
	int parent = 1, child = 2;
	
	while (child <= sz_minHeap) {
		if (child < sz_minHeap && minHeap[child] > minHeap[child + 1]) child++;
		if (temp <= minHeap[child])break;
		minHeap[parent] = minHeap[child];
		parent = child; child *= 2;
	}
	minHeap[parent] = temp;
	return ret;
}

int pop_max_heap() {
	int ret = maxHeap[1];
	int temp = maxHeap[sz_maxHeap--];
	int parent = 1, child = 2;

	while (child <= sz_maxHeap) {
		if (child < sz_maxHeap && maxHeap[child] < maxHeap[child + 1]) child++;
		if (temp >= maxHeap[child])break;
		maxHeap[parent] = maxHeap[child];
		parent = child; child *= 2;
	}
	maxHeap[parent] = temp;
	return ret;
}

void initialize() {
	scanf("%d", &input_num); getchar();
	for (int i = 0; i < input_num; i++) {
		scanf("%d", &rawdata[i]); getchar();
	}
}

void swapminmax() {
	int from_min = pop_min_heap();
	int from_max = pop_max_heap();
	insert_min_heap(from_max);
	insert_max_heap(from_min);
}

void operate() {
	//규칙1 : maxheap은 minheap과 크기가 같거나 1이 더 크다.
	//규칙2 : minheap의 top은 maxheap의 top보다 크거나 같다.
	//규칙3 : 위 규칙들이 지켜지지 못하면 min과 max를 swap한다.

	for (int i = 0; i < input_num; i++) {
		if (sz_maxHeap == sz_minHeap) insert_max_heap(rawdata[i]);
		else insert_min_heap(rawdata[i]);

		if (sz_maxHeap && sz_minHeap) {
			if (maxHeap[1] > minHeap[1]) swapminmax();
		}

		printf("%d\n", maxHeap[1]);
	}
}

int main() {
	initialize();
	operate();
	return 0;
}