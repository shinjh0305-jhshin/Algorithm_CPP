//�Ϻ��� Ʋ�� �ڵ�
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define endl "\n"
#define EMPTY '.'
#define WALL '*'
#define DOC '$'
using namespace std;

bool doorOpened[26];
bool visited[105][105];
string map[105];
int rows, cols;
int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };

void initialize() {
	/*initialize all data*/
	memset(doorOpened, false, sizeof(doorOpened));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 105; i++) map[i].clear();

	cin >> rows >> cols;

	string st;
	for (int i = 0; i <= cols + 1; i++) map[0] += '.'; //����
	for (int i = 1; i <= rows; i++) {
		cin >> st;
		map[i] = ".";
		map[i] += st;
		map[i] += ".";
	}
	for (int i = 0; i <= cols + 1; i++) map[rows + 1] += '.'; //�Ʒ���
	
	cin >> st; //���� ���� �ִ� ����
	if (st != "0") {
		for (const auto& it : st) {
			doorOpened[it - 'a'] = true;
		}
	}
}

void operate() {
	int currow, curcol, nrow, ncol;
	queue<pair<int, int>> qu;
	qu.push({ 0, 0 });

	int getDocs = 0;
	char nextData;
	while (!qu.empty()) {
		currow = qu.front().first; curcol = qu.front().second;
		qu.pop();

		for (int k = 0; k < 4; k++) {
			nrow = currow + drow[k]; ncol = curcol + dcol[k];
			
			if (nrow < 0 || nrow > rows + 1 || ncol < 0 || ncol > cols + 1) continue; //out of bounds

			nextData = map[nrow][ncol];

			if (visited[nrow][ncol] || nextData == WALL) continue;  //visited or wall
			else if (nextData == DOC) { //������
				getDocs++;
				map[nrow][ncol] = EMPTY;
			}
			if ('A' <= nextData && nextData <= 'Z') { //���̴�
				if (!doorOpened[nextData - 'A']) continue; //���� �� �� ���̴�.
			}
			else if ('a' <= nextData && nextData <= 'z') { //�����
				if (!doorOpened[nextData - 'a']) { //ó�� �߰��� ���� ���� �����
					doorOpened[nextData - 'a'] = true;
					memset(visited, false, sizeof(visited));
				}
			}
			
			visited[nrow][ncol] = true; //�湮 �Ϸ�!
			qu.push({ nrow, ncol });
		}
	}

	cout << getDocs << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--) {	
		initialize();
		operate();
	}

	return 0;
}