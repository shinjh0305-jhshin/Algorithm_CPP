#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

class height {
private:
	vector<int>* rawdata;
	int* in_order;
	int ppl, rule;

public:
	void initialize() {
		cin >> ppl >> rule; cin.get();

		rawdata = new vector<int>[ppl + 1];
		in_order = new int[ppl + 1];
		memset(in_order, 0, sizeof(int)*(ppl + 1));

		int front, rear;
		for (int i = 0; i < rule; i++) {
			cin >> front >> rear; cin.get();
			rawdata[front].push_back(rear);
			in_order[rear]++;
		}
	}

	void operate() {
		//next : in_order가 0인 노드를 담는 큐
		//order : 키 비교 순서(결과)를 담는 큐
		queue<int> order, next;

		int temp, mov;

		for (int i = 1; i <= ppl; i++) { //in_order가 0인 사람을 넣는다.
			if (in_order[i] == 0) next.push(i);
		}

		while (order.size() != ppl) { //모든 사람이 order에 들어갈 때 까지
			temp = next.front(); next.pop(); //하나씩 꺼낸다
			order.push(temp);

			mov = 0;
			while (mov != rawdata[temp].size()) {
				if (--in_order[rawdata[temp][mov]] == 0) { //in_order을 하나씩 줄인다
					next.push(rawdata[temp][mov]);
				}
				mov++;
			}
		}

		while (!order.empty()) { //출력
			cout << order.front() << ' ';
			order.pop();
		}
		cout << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	height op;
	op.initialize();
	op.operate();
	return 0;
}