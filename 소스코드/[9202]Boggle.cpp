#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#define endl "\n"
using namespace std;

struct info {
	bool finished = false; //현재 글자에서 끝나는 단어가 있는가
	info* nextLetter[26] = { NULL };
};

struct info root;
string map[4];
int drow[8] = { 1,1,0,-1,-1,-1,0,1 }, dcol[8] = { 0,-1,-1,-1,0,1,1,1 };
bool visited[5][5];
set<string> result;
string longest;

void insertTrie(string& st) {
	int letterIdx;
	info* mov = &root;

	for (const auto& curLetter : st) {
		letterIdx = curLetter - 'A';

		if (!mov->nextLetter[letterIdx]) {
			mov->nextLetter[letterIdx] = new info;
		}

		mov = mov->nextLetter[letterIdx];
	}

	mov->finished = true;
}

void DFS(int row, int col, info* node, string st) {
	int nrow, ncol, letterIdx;

	visited[row][col] = true;

	if (node->finished) { //st와 일치하는 단어가 있다.
		if (st.length() > longest.length() || (st.length() == longest.length() && st < longest)) {
			longest = st;
		}
		result.insert(st);
	}

	if (st.length() == 8) {
		visited[row][col] = false;
		return; //8까지만 탐색
	}

	for (int k = 0; k < 8; k++) {
		nrow = row + drow[k]; ncol = col + dcol[k];

		if (nrow < 0 || nrow >= 4 || ncol < 0 || ncol >= 4 || visited[nrow][ncol]) continue;

		letterIdx = map[nrow][ncol] - 'A';
		if (!node->nextLetter[letterIdx]) continue; //그 다음 글자가 발견되지 않는 경우


		DFS(nrow, ncol, node->nextLetter[letterIdx], st + map[nrow][ncol]);
	}

	visited[row][col] = false;
}


void printResult() {
	int points = 0;
	for (const auto& it : result) {
		int itLen = it.length();

		if (itLen <= 2) points += 0;
		else if (itLen <= 4) points += 1;
		else if (itLen <= 6) points += itLen - 3;
		else if (itLen == 7) points += 5;
		else points += 11;
	}
	cout << points << ' ' << longest << ' ' << result.size() << endl;
}

void initialize() {
	string st;
	
	int words;
	cin >> words;

	for (int i = 0; i < words; i++) {
		cin >> st;
		insertTrie(st);
	}
}

void operate() {
	int op;
	cin >> op;

	while (op--) {
		longest = ""; //가장 긴 문자열 초기화
		result.clear(); //찾은 글자 초기화

		for (int i = 0; i < 4; i++) {
			cin >> map[i];
		}

		for (int currow = 0; currow < 4; currow++) {
			for (int curcol = 0; curcol < 4; curcol++) {				
				if (root.nextLetter[map[currow][curcol] - 'A']) {
					string st;
					st += map[currow][curcol];
					DFS(currow, curcol, root.nextLetter[map[currow][curcol] - 'A'], st);
				}
			}
		}

		printResult();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}