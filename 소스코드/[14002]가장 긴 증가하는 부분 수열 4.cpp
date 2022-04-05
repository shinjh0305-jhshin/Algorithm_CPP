#include <stdio.h>
#include <stack>
using namespace std;

#pragma warning (disable:4996)

struct node {
	int num; /*들어있는 숫자*/
	int order; /*숫자가 몇 번째로 작은지*/
	node* llink;
	node* rlink;
	node* previous;
};

class list {
private:
	node* head;
	int order_max; /*가장 긴 수열의 길이*/
	node* node_order_max; /*가장 긴 수열의 끝 node*/
	int nodes;
public:
	list() : order_max(0), nodes(0), node_order_max(NULL){
		head = new node;
		head->llink = head;
		head->rlink = head;
		head->num = 0;
		head->order = 0;
		head->previous = NULL;
	};
	~list() {
		node* temp = NULL;
		while (nodes) {
			temp = head;
			head = head->rlink;
			delete temp;
			nodes--;
		}
	}
	void how_many_nodes() {
		scanf("%d", &nodes); getchar();
	}

	void make_list() {
		node* mov = NULL, * temp_previous = NULL;
		int local_order_max; 

		for (int i = 0; i < nodes; i++) {
			local_order_max = 0;
			temp_previous = NULL;

			mov = head->rlink;
			node* temp = new node;
			int num_in;
			scanf("%d", &num_in); getchar();

			temp->num = num_in;

			/*mov가 head르 안 올 때까지, mov->num이 num_in보다 작을때까지 탐색*/
			while (mov->num > 0 && mov->num < num_in) { 
				if (mov->order > local_order_max) {
					local_order_max = mov->order;
					temp_previous = mov;
				}
				mov = mov->rlink;
			}

			temp->order = ++local_order_max;
			temp->llink = mov->llink;
			temp->rlink = mov;
			temp->llink->rlink = temp;
			temp->rlink->llink = temp;
			temp->previous = temp_previous;

			if (local_order_max > order_max) {
				order_max = local_order_max;
				node_order_max = temp;
			}
		}
	}

	void print_list() {
		stack<node*> stack;
		node* mov = node_order_max;

		while (mov) {
			stack.push(mov);
			mov = mov->previous;
		}

		printf("%d\n", order_max);
		while (!stack.empty()) {
			printf("%d ", stack.top()->num);
			stack.pop();
		}
		printf("\n");
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