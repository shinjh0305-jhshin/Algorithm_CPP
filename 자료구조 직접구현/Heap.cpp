#include <iostream>
using namespace std;

struct info {
	char name[50];
	int score;
};

int maxSize = 10;
info* heap = nullptr;
int sz_heap = 0;

void insertHeap() {
	if (sz_heap + 2 == maxSize) {
		//increase heap
	}
}

int main() {
	heap = new info[maxSize];
}