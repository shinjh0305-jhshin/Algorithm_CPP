#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int sz[3];
bool visited[202][202][202] = { false };
vector<int> result;

void initialize() {
	cin >> sz[0] >> sz[1] >> sz[2];
}

void makeChange(int curWater[3]) {
	if (visited[curWater[0]][curWater[1]][curWater[2]]) return;
	visited[curWater[0]][curWater[1]][curWater[2]] = true;

	if (curWater[0] == 0) result.push_back(curWater[2]);

	int tempWater[3];
	for (int i = 0; i < 3; i++) {
		if (curWater[i]) { //i번 탱크를 옮긴다.
			for (int j = 0; j < 3; j++) { //j번 탱크로 물을 옮긴다.
				if (i == j || curWater[j] == sz[j]) continue; //같은 탱크거나, 옮길 탱크가 꽉 찼으면 pass

				for (int k = 0; k < 3; k++) tempWater[k] = curWater[k]; //넘겨줄 물 용량값

				if (sz[j] - curWater[j] >= curWater[i]) { //i의 물 전부를 j에게 줄 수 있다면
					tempWater[i] = 0; tempWater[j] = curWater[i] + curWater[j];
					makeChange(tempWater);
				}
				else { //i의 물 일부를 j에게 줄 수 있다면. 즉 j가 꽉 찬다.
					tempWater[i] = curWater[i] - (sz[j] - curWater[j]);
					tempWater[j] = sz[j];
					makeChange(tempWater);
				}
			}
		}
	}
}

void operate() {
	int initial[] = { 0,0,sz[2] };
	makeChange(initial);

	sort(result.begin(), result.end());

	for (const auto it : result) {
		cout << it << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}