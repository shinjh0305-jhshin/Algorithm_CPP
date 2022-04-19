#include <iostream>
#include <bitset>
#include <stack>
#define endl "\n"
using namespace std;

int rawdata[100003];
int test_cases, sz_rawdata, sz_impossible;
enum status { group = -1, impossible };
bitset<100003> visited(0);

void initialize() {
	cin >> sz_rawdata;
	for (int i = 1; i <= sz_rawdata; i++) {
		cin >> rawdata[i];
	}
}

void scan(int num) {
	stack<int> st;
	visited.reset();

	int curnum = num, nextnum, temp;
	while (1) {
		st.push(curnum);
		visited[curnum] = true;
		nextnum = rawdata[curnum];

		if (nextnum > 0) { //탐색을 안 한 사람에 와 있는 경우
			if (visited[nextnum]) { //group 형성됨. 즉, loop 발견됨.
				//stack에 있는 사람들 전부 group으로 만든다
				while (1) {
					temp = st.top();
					rawdata[temp] = group;
					st.pop();
					if (temp == nextnum) { //group의 시작점으로 돌아왔다.
						break;
					}
				}
				while (!st.empty()) { //진행해도 자신과는 관계 없는 그룹을 만난다. 그룹 형성 불가.
					rawdata[st.top()] = impossible; 
					sz_impossible++;
					st.pop();
				}
				break;
			}
			else { //아직 group이 형성되지 않음.
				curnum = nextnum;
			} 
		}

		else { //탐색했으나, group을 형성 못 하는 사람으로 판별됨.
			st.pop(); //st.top은 이미 impossible로 카운트 된 사람이다.
			//stack에 있는 사람들 전부 impossible로 마크한다
			while (!st.empty()) {
				rawdata[st.top()] = impossible;
				sz_impossible++;
				st.pop();
			}
			break;
		}

	}
}

void operate() {
	sz_impossible = 0;
	for (int i = 1; i <= sz_rawdata; i++) {
		if (rawdata[i] > 0) scan(i);
	}
	cout << sz_impossible << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> test_cases;
	for (int i = 0; i < test_cases; i++) {
		initialize();
		operate();
	}

	return 0;	
}

/*
1
8
1 2 3 4 5 6 7 8
ans : 0

1
7
3 1 3 7 3 4 6
ans : 3

1
4
2 4 2 3
ans : 1

1
7
2 3 4 2 6 7 5
ans : 1

1
5
3 3 1 2 1
ans : 3

1
5
2 3 4 5 4
ans : 3
*/