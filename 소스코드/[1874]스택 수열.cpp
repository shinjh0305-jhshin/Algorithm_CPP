#include <cstdio>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)
using namespace std;

class operate {
private : 
	int stack_size;
	int flag;
	queue<char> QU;

public:
	operate() :stack_size(0), flag(0) {};

	void initialize() {
		scanf("%d", &stack_size); getchar();
	}

	void make_seq() {
		int num_target, next_stack_push_num = 1;
		stack<int> ST;
		

		for (int i = 0; i < stack_size; i++) {
			scanf("%d", &num_target); getchar();
			if (flag) continue;

			while (ST.empty() || ST.top() != num_target) {
				if (next_stack_push_num > stack_size) {
					flag = 1; break;
				}
				ST.push(next_stack_push_num);
				QU.push('+');
				next_stack_push_num++;
			}

			if (ST.top() == num_target) {
				QU.push('-');
				ST.pop();
			}
		}
	}

	void print_result() {
		if (flag)
			printf("NO\n");
		else {
			while (!QU.empty()) {
				printf("%c\n", QU.front());
				QU.pop();
			}
		}
	}
};

int main() {
	operate op;
	op.initialize();
	op.make_seq();
	op.print_result();
	return 0;
}