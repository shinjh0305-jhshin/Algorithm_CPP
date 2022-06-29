#include <iostream>
using namespace std;

struct info {
	char name[60];
	int score;
};
struct node {
	info data;
	node* nextnode;
};

node* root = nullptr;
node* curnode = nullptr;
int sz_queue = 0;

void pop() {
	if (sz_queue == 0) {
		cout << "제거 할 데이터가 없습니다." << endl;
		return;
	}

	node* temp = root;
	root = root->nextnode;
	delete temp;

	cout << root->data.name << "학생(성적 : " << root->data.score << "점)을 제거합니다." << endl;
	sz_queue--;
}

void push() {
	curnode->nextnode = new node;
	curnode = curnode->nextnode;
	sz_queue++;

	cout << "이름을 입력하세요   >>  ";
	cin.getline(curnode->data.name, 60, '\n');  //getline은 버퍼에 개행문자 안 남겨둠!

	cout << "성적을 입력하세요   >>  ";
	cin >> curnode->data.score; cin.get();

	cout << "입력된 이름은 " << curnode->data.name << "이며, 성적은 " << curnode->data.score << "점 입니다." << endl;
}

void printScore() {
	cout << endl << endl;
	cout << "//////////////////////////////////////////////////" << endl;
	cout << "                    스코어보드                     " << endl;

	node* mov = root->nextnode;
	for (int i = 0; i < sz_queue; i++) {
		cout << mov->data.name << "  |  " << mov->data.score << "점" << endl;
		mov = mov->nextnode;
	}
	cout << "//////////////////////////////////////////////////" << endl << endl;
}

int main() {
	root = new node;
	curnode = root;

	int op;

	while (1) {
		cout << "어떤 작업을 수행할까요? (1 : 푸시, 2 : 팝)   >>  ";
		cin >> op; cin.get();

		if (op == 1) {
			push();
			printScore();
		}
		if (op == 2) {
			pop();
			printScore();
		}
	}

	
}