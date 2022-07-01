#include <iostream>
#include <cstring>
#include <stack>
#define UND 1234568790
using namespace std;

int plates, nums, rotates; //plates : 원판, nums : 원판 당 숫자, rotate : 회전 횟수
int rawdata[52][52];

void initialize() {
	cin >> plates >> nums >> rotates;

	for (int i = 1; i <= plates; i++) {
		for (int j = 1; j <= nums; j++) {
			cin >> rawdata[i][j];
		}
	}
}

void doRotate() { //회전만 시킨다
	//a, b, c
	//a의 배수인 원판을 b방향으로 c칸 회전시킨다.

	int a, b, c;
	cin >> a >> b >> c;

	int num[52] = { 0 };

	int targetPlate, numBefore, numCurrent, idx, nextIdx;
	for (int i = 1;; i++) {
		targetPlate = i * a;
		if (targetPlate > plates) return;

		memset(num, 0, sizeof(num));

		for (int idx = 1; idx <= nums; idx++) {
			if (b == 0) { //시계방향
				nextIdx = idx + c; //다음 index 간다
				if (nextIdx > nums) nextIdx %= nums; //다음 인덱스가 앞으로 넘어가는 경우
			}
			else if (b == 1) { //반시계방향
				nextIdx = idx - c;
				if (nextIdx <= 0) nextIdx += nums; //다음 인덱스가 맨 뒤로 가는 경우
			}

			num[nextIdx] = rawdata[targetPlate][idx];

		}
		for (int i = 1; i <= nums; i++) rawdata[targetPlate][i] = num[i];
	}
}

void getAdjacent() {
	int idxBefore, idxAfter, idxUp, idxDown;

	stack<pair<int, int>> st;

	for (int i = 1; i <= plates; i++) { //인접한 같은 수 전부 삭제
		for (int j = 1; j <= nums; j++) {
			if (rawdata[i][j] == UND) continue; //지워진 수
			
			idxBefore = j - 1 > 0 ? j - 1 : nums;
			idxAfter = j + 1 <= nums ? j + 1 : 1;

			if ((rawdata[i][idxBefore] == rawdata[i][j]) || (rawdata[i][idxAfter] == rawdata[i][j]) || 
				(i < plates && (rawdata[i + 1][j] == rawdata[i][j])) || (i > 1 && (rawdata[i - 1][j] == rawdata[i][j]))) {
				st.push({ i, j });
			}
		}
	}

	bool isDeleted = !st.empty();

	while (!st.empty()) {
		rawdata[st.top().first][st.top().second] = UND;
		st.pop();
	}

	if (isDeleted) return;

	// 수를 삭제하지 못해서, 숫자의 평균을 구해야 한다.
	double sum = 0, totalnums = 0;
	for (int i = 1; i <= plates; i++) {
		for (int j = 1; j <= nums; j++) {
			if (rawdata[i][j] != UND) {
				sum += rawdata[i][j];
				totalnums++;
			} 
		}
	}

	if (totalnums == 0) return;

	double average = sum / totalnums;
	for (int i = 1; i <= plates; i++) {
		for (int j = 1; j <= nums; j++) {
			if (rawdata[i][j] != UND) {
				if (rawdata[i][j] - average > 0.00000001) rawdata[i][j]--;
				else if (average - rawdata[i][j] > 0.00000001) rawdata[i][j]++;
			}
		}
	}
}

void getSum() {
	int ans = 0;
	for (int i = 1; i <= plates; i++) {
		for (int j = 1; j <= nums; j++) {
			if (rawdata[i][j] != UND) ans += rawdata[i][j];
		}
	}

	cout << ans << endl;
}

void operate() {
	for (int i = 0; i < rotates; i++) {
		doRotate();
		getAdjacent(); 
	}

	getSum();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}