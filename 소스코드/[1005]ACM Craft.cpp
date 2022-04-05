#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class AcmCraft {
private:
	vector<int>* graph;
	int* duration, *in_order, *acc; //duration : 건물을 짓는 데 필요한 시간, in_order : 선행관계, acc : 해당 건물을 짓기 이전에 소요된 시간(max)
	int cases, bldgs, order, target;

public:
	void initialize() {
		cin >> cases; cin.get();
	}

	void get_cases() {
		cin >> bldgs >> order; cin.get();
		graph = new vector<int>[bldgs + 1];
		duration = new int[bldgs + 1];
		acc = new int[bldgs + 1];
		memset(acc, 0, sizeof(int)*(bldgs + 1));
		in_order = new int[bldgs + 1];
		memset(in_order, 0, sizeof(int)*(bldgs + 1));

		for (int j = 1; j <= bldgs; j++) {
			cin >> duration[j]; cin.get();
		}

		int first, second;
		for (int j = 0; j < order; j++) {
			cin >> first >> second; cin.get();
			in_order[second]++;
			graph[first].push_back(second);
		}

		cin >> target; cin.get();
	}

	void free_cases() {
		delete[] graph;
		delete[] in_order;
		delete[] duration;
		delete[] acc;
	}

	void operate() {
		for (int i = 0; i < cases; i++) {
			get_cases();

			queue<int> next;
			for (int j = 1; j <= bldgs; j++) {
				if (in_order[j] == 0) next.push(j);
			}

			int next_house, mov, temp;
			while (!next.empty()) {
				temp = next.front();
				next.pop();

				mov = 0;
				while (mov != graph[temp].size()) {
					next_house = graph[temp][mov];
					acc[next_house] = max(acc[next_house], duration[temp] + acc[temp]);

					if (--in_order[next_house] == 0) {
						if (next_house == target) goto print;
						next.push(next_house);
					}
					mov++;
				}
			}
		print:;
			acc[target] += duration[target];
			cout << acc[target] << endl;
			free_cases();
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	AcmCraft op;
	op.initialize();
	op.operate();
	return 0;
}