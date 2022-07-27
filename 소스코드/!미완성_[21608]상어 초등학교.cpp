#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<pair<int, int>, int> candidate; //��ǥ��, ģ�� ����
int favor[23][5]; //�л� ��ȣ, �л� ��ȣ 1~4
bool seatTaken[22][22] = {false};
pair<int, int> seat[450]; //seat[studnet] = seatnumber
int sz_map, students;

int drow[4] = { 1,0,-1,0 };
int dcol[4] = { 0,-1,0,1 };

void initialize() {
	cin >> sz_map;
	students = sz_map * sz_map;

	for (int i = 0; i < students; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> favor[i][j];
		}
	}
}

void operate() {
	//ù ��° �л��� �׻� 2,2�� �ɴ´�
	seatTaken[2][2] = true;
	seat[favor[0][0]] = { 2,2 };

	int currow, curcol, nrow, ncol, curmax, curBlank, tempBlank;
	for (int i = 1; i < students; i++) {
		candidate.clear();
		int curStudent = favor[i][0];
		for (int j = 1; j <= 4; j++) {
			int favorStudent = favor[i][j];
			if (seat[favorStudent] == make_pair(0, 0)) continue; //��ȣ�ϴ� ģ���� �¼��� ���� ���� ������

			currow = seat[favorStudent].first;
			curcol = seat[favorStudent].second;

			for (int k = 0; k < 4; k++) {
				nrow = currow + drow[k];
				ncol = curcol + dcol[k];

				if (nrow < 1 || nrow > sz_map || ncol < 1 || ncol > sz_map || seatTaken[nrow][ncol]) continue;

				candidate[{nrow, ncol}]++;
			}
		}
		curmax = 0; curBlank = 0;

		c
		for (const auto& it : candidate) {
			if (it.second > curmax) { //������ ģ�� ���ڰ� �� ���� ĭ �߰�!
				curmax = it.second;
				currow = it.first.first;
				curcol = it.first.second;

				curBlank = 0;
				for (int k = 0; k < 4; k++) { //������ ĭ �߿��� �� ĭ ���� ����
					nrow = currow + drow[k];
					ncol = curcol + dcol[k];

					if (!seatTaken[nrow][ncol]) curBlank++;
				}

			}
			else if (it.second == curmax) { //������ ģ�� ���ڰ� ����. 2�� ���� �˻�
				tempBlank = 0;
				for (int k = 0; k < 4; k++) {
					nrow = it.first.first + drow[k];
					ncol = it.first.second + dcol[k];

					if (!seatTaken[nrow][ncol]) tempBlank++;
				}
				
				if (tempBlank > curBlank) { //�� ĭ�� �� ���� ĭ �߰�!
					currow = it.first.first;
					curcol = it.first.second;
					curBlank = tempBlank;
				}
				else if (curBlank == tempBlank) { //������ ĭ �߿��� ����ִ� ĭ�� ������ �Ȱ���
					if (currow > it.first.first || ((currow == it.first.first) && curcol > it.first.second)) {
						currow = it.first.first;
						curcol = it.first.second;
					}
				}
			}
		}

	}

}