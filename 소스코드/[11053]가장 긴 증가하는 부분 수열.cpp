#include <stdio.h>

#pragma warning (disable:4996)
#define IS_EMPTY(a) (!(a))

struct node {
	int num;
	int order;
	node* llink;
	node* rlink;
};

class list {
private:
	node* head;
	int order_max;
	int nodes;
public:
	list() : order_max(0), head(NULL), nodes(0) {};
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
		int local_order_max;
		for (int i = 0; i < nodes; i++) {
			local_order_max = 0;

			mov = head; trail = NULL;
			node* temp = new node;
			int num_in;
			scanf("%d", &num_in); getchar();

			temp->num = num_in;
			if (IS_EMPTY(head)) {
				temp->llink = NULL;
				temp->order = ++local_order_max;
				temp->rlink = NULL;
				head = temp;
			}
			else {
				while (mov && mov->num < num_in) {
					if (mov->order > local_order_max) {
						local_order_max = mov->order;
					}
					trail = mov;
					mov = mov->rlink;
				}
				temp->order = ++local_order_max;
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

			if (local_order_max > order_max) {
				order_max = local_order_max;
			}

		}
	}

	void print_list() {
		printf("%d\n", order_max);
	}
};

int main() {
	list* data = new list;
	data->how_many_nodes();
	data->make_list();
	data->print_list();
	delete data;

	return 0;
}

