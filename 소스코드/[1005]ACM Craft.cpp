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
	vector<int>* graph; //각 건물 별 먼저 지어야 할 건물의 INDEX
	int* duration, *in_order, *acc; //duration : 각 건물을 짓는 데 필요한 시간, in_order : 선행관계, acc : 해당 건물을 짓기 시작할 수 있는 시각
	int cases, bldgs, order, target;

public:
	void initialize() {
		cin >> cases; cin.get();
	}

	void get_cases() {
		cin >> bldgs >> order; cin.get();

		//RAWDATA 배열들 메모리 할당 및 초기화
		graph = new vector<int>[bldgs + 1]; 
		duration = new int[bldgs + 1];
		acc = new int[bldgs + 1];
		memset(acc, 0, sizeof(int)*(bldgs + 1)); 
		in_order = new int[bldgs + 1];
		memset(in_order, 0, sizeof(int)*(bldgs + 1));

		//각 건물을 짓는 데 필요한 시간을 받는다
		for (int j = 1; j <= bldgs; j++) {
			cin >> duration[j]; cin.get(); 
		}

		int first, second;
		for (int j = 0; j < order; j++) {
			cin >> first >> second; cin.get();
			in_order[second]++; //건물을 짓기 이전에 지어야 할 건물의 수를 저장한다
			graph[first].push_back(second); //건물을 짓기 이전에 지어야 할 건물의 INDEX를 저장한다
		}

		cin >> target; cin.get();
	}

	void free_cases() { //다음 TEST CASE를 위한 메모리 해제
		delete[] graph; 
		delete[] in_order;
		delete[] duration;
		delete[] acc;
	}

	void operate() {
		for (int i = 0; i < cases; i++) {
			get_cases();

			queue<int> next; //지금 지을 수 있는 건물을 저장하는 큐
			for (int j = 1; j <= bldgs; j++) { //완전 처음에 먼저 지어야 할 건물이 없는 건물들을 찾는다.
				if (in_order[j] == 0) next.push(j);
			}

			int next_house, mov, temp;
			while (!next.empty()) {
				temp = next.front(); //TEMP == 나
				next.pop();

				mov = 0;
				while (mov != graph[temp].size()) {
					next_house = graph[temp][mov]; //나를 선행 건물로 갖고 있는 건물
					acc[next_house] = max(acc[next_house], duration[temp] + acc[temp]); //그 건물의 시작 가능 시각을 업데이트시켜준다.

					if (--in_order[next_house] == 0) { //이제 그 건물을 지을 수 있는가?
						if (next_house == target) goto print;
						next.push(next_house);
					}
					mov++;
				}
			}
		print:;
			acc[target] += duration[target]; //TARGET 자체 건설 소요 시간 + 선행 건물 건설 소요 시간
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