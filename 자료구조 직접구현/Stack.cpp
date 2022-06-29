#include <iostream>
using namespace std;

struct info {
	char name[60];
	int score;
};

struct node {
	info data;
	node* nextnode;
	node* prevnode;
};

node* root = nullptr;
node* curNode = nullptr;
int sz_stack = 0;

void push() {
	curNode->nextnode = new node;
	curNode->nextnode->prevnode = curNode;
	curNode = curNode->nextnode;
	sz_stack++;

	cout << "이름을 입력하세요   >>  ";
	cin.getline(curNode->data.name, 60, '\n');  //getline은 버퍼에 개행문자 안 남겨둠!

	cout << "성적을 입력하세요   >>  ";
	cin >> curNode->data.score; cin.get();

	cout << "입력된 이름은 " << curNode->data.name << "이며, 성적은 " << curNode->data.score << "점 입니다." << endl;
}

void pop() {
	if (sz_stack == 0) {
		cout << "삭제 할 데이터가 없습니다." << endl;
		return;
	}

	node* temp = curNode;
	curNode = curNode->prevnode;
	curNode->nextnode = nullptr;

	cout << sz_stack << "번째 학생인 " << temp->data.name << "(성적 : " << temp->data.score << ")의 성적 데이터를 삭제합니다." << endl;
	sz_stack--;
	delete temp;
}

void printScore() {
	cout << endl << endl;
	cout << "//////////////////////////////////////////////////" << endl;
	cout << "                    스코어보드                     " << endl;

	node* mov = root->nextnode;
	for (int i = 0; i < sz_stack; i++) {
		cout << mov->data.name << "  |  " << mov->data.score << "점" << endl;
		mov = mov->nextnode;
	}
	cout << "//////////////////////////////////////////////////" << endl << endl;
}

int main() {
	root = new node; //dummy node
	curNode = root;

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