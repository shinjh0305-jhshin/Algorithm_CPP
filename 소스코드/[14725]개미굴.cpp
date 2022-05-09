#include <iostream>
#include <map>
#include <string>
using namespace std;

struct TRIE {
	map<string, TRIE*> child;
};

TRIE rootNode;

void print_result(TRIE* currentNode, int depth) {
	for (auto it : currentNode->child) {
		for (int i = 0; i < depth * 2; i++) {
			cout << '-';
		}
		cout << it.first << endl;
		print_result(it.second, depth + 1);
	}
}

void operate() {
	int opers, depth;
	string target;
	TRIE* currentNode, *newTRIE;
	cin >> opers;

	for (int i = 0; i < opers; i++) {
		currentNode = &rootNode;

		cin >> depth; //이동한 깊이를 받는다
		for (int j = 0; j < depth; j++) {
			cin >> target; //먹이 이름

			auto it = currentNode->child.find(target);
			if (it == currentNode->child.end()) { //탐색한 적 없는 노드임
				newTRIE = new TRIE(); //새로운 자식 노드
				currentNode->child.insert({ target, newTRIE });
				currentNode = newTRIE; //다음 자식 노드로 간다
			}
			else { //탐색한 적 있는 노드임
				currentNode = (*it).second; //그 노드로 간다.
			}
		}
	}
	print_result(&rootNode, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}

//4ms 답안--다음에는 이거 이해!!
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<set>
//using namespace std;
//
//set<string> s;
//
//int main() {
//
//	int N, K, t;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> K;
//		string tmp = "";
//		string str = "";
//		for (int j = 0; j < K; j++)
//		{
//			cin >> tmp;
//			str += "*" + tmp;
//			s.insert(str);
//		}
//	}
//
//	for (auto value : s) {
//		int cnt = count(value.begin(), value.end(), '*');
//		int pos = value.find_last_of("*");
//		string tmp = value.substr(pos + 1);
//		for (int i = 0; i < cnt - 1; i++) cout << "--";
//		cout << tmp << '\n';
//	}
//}