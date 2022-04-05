#include <stdio.h>
#include <limits.h>

#pragma warning (disable:4996)
#define IS_EMPTY(a) (!(a))

struct node {
	int num;
	int sum;
	node* llink;
	node* rlink;
};

class list {
private:
	node* head;
	int sum_max;
	int nodes;
public:
	list() : sum_max(0), head(NULL), nodes(0) {};
	~list() {
		node* temp = NULL;
		while (head) {
			temp = head;
			head = head->rlink;
			delete temp;
		}
	}
	void how_many_nodes() {
		scanf("%d", &nodes); getchar();
	}

	void make_list() {
		node* mov = NULL, * trail = NULL;
		int local_sum_max;
		for (int i = 0; i < nodes; i++) {
			local_sum_max = 0;

			mov = head; trail = NULL;
			node* temp = new node;
			int num_in;
			scanf("%d", &num_in); getchar();

			temp->num = num_in;
			if (IS_EMPTY(head)) {
				local_sum_max += num_in;

				temp->llink = NULL;
				temp->sum = local_sum_max;
				temp->rlink = NULL;
				head = temp;
			}
			else {
				while (mov && mov->num < num_in) {
					if (mov->sum > local_sum_max) {
						local_sum_max = mov->sum;
					}
					trail = mov;
					mov = mov->rlink;
				}
				local_sum_max += temp->num;
				temp->sum = local_sum_max;
				temp->llink = trail;
				temp->rlink = mov;
				if (mov == head) {
					head = temp;
				}

				if (temp->llink) {
					temp->llink->rlink = temp;
				}
				if (temp->rlink) {
					temp->rlink->llink = temp;
				}
			}

			if (local_sum_max > sum_max) {
				sum_max = local_sum_max;
			}

		}
	}

	void print_list() {
		printf("%d\n", sum_max);
	}
};

int main() {
	list data;
	data.how_many_nodes();
	data.make_list();
	data.print_list();
	return 0;
}