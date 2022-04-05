#include <iostream>
#include <vector>
#include <string>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct node {
	bool finished; //여기에서 종료되는 전화번호가 있는지
	node* child[10];

	node() {
		for (int i = 0; i < 10; i++) {
			child[i] = NULL;
		}
		finished = false;
	}
};

int test_cases, sz_string;
vector<string> rawdata;
node* root = NULL;

void initialize() {
	cin >> test_cases;
}

void get_string() {
	root = new node;
	root->finished = false;

	cin >> sz_string; cin.get();

	rawdata.clear();
	rawdata.resize(sz_string);

	for (int i = 0; i < sz_string; i++) {
		getline(cin, rawdata[i]);
	}
}

bool make_tree(int cur_str, int str_idx, node* curNode) {
	if (curNode->finished) return false; //이미 같은 접두사를 갖는 번호가 있었을 경우
	else if (str_idx == rawdata[cur_str].size() - 1) {
		curNode->finished = true; //현재 위치에서 번호가 끝난다
		for (int i = 0; i < 10; i++)
			if (curNode->child[i]) return false; //현재 번호를 접두사로 갖는 번호가 있을 경우
		return true; //그렇지 않을 경우
	}
	else {
		str_idx++;
		int target_num = rawdata[cur_str][str_idx] - '0';
		if (!curNode->child[target_num]) { //into the unknown
			curNode->child[target_num] = new node;
		}
		return make_tree(cur_str, str_idx, curNode->child[target_num]);
	}
}

void operate() {
	for (int i = 0; i < sz_string; i++) {
		if (make_tree(i, -1, root) == false) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

void free_mem(node* curNode) {
	for (int i = 0; i < 10; i++) {
		if (curNode->child[i])
			free_mem(curNode->child[i]);
	}

	delete curNode;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	for (int i = 0; i < test_cases; i++) {
		get_string();
		operate();
		free_mem(root);
	}

	return 0;
}

/*

1
3
911
97625999
91125426

1
5
113
12340
123440
12345
98346

1
2
1236
1234
*/

