#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> types[11] = {
	{"1000", "1111", "1000"},
	{"0100", "1111", "1000"},
	{"0010", "1111", "1000"},
	{"0001", "1111", "1000"},
	{"0100", "1111", "0100"},
	{"0010", "1111", "0100"},
	{"0011", "0110", "1100"},
	{"0011", "1110", "1000"},
	{"1100", "0111", "0100"},
	{"0100", "1110", "0011"},
	{"00111", "11100"}
};
char rawdata[6][6];


void initialize() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			rawdata[i][j] = cin.get();
			cin.get(); //개행문자 제거
		}
	}
}

void rotateBlock(vector<string>& st)  {
	vector<string> ret;

	int rows = st[0].length(), cols = st.size(); //row, col : ret 벡터의 row, col
	ret.resize(rows, "");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret[i] += st[cols - j - 1][i];
		}
	}

	st.clear();

	for (const auto it : ret) st.push_back(it);
}

void invertBlock(vector<string>& st) {
	vector<string> ret;

	int rows = st.size(), cols = st[0].length(); //row, col : ret 벡터의 row, col
	ret.resize(rows, "");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret[i] += st[i][cols - j - 1];
		}
	}

	st.clear();

	for (const auto it : ret) st.push_back(it);
}

bool operate() {
	int rows, cols;
	vector<string> curBlock;


	bool isSame;
	for (int type = 0; type < 11; type++) {
		rows = types[type].size();
		cols = types[type][0].length();

		for (const auto it : types[type]) {
			curBlock.push_back(it);
		}

		for (int invert = 0; invert < 2; invert++) { //좌우반전 2회
			for (int rota = 0; rota < 4; rota++) { //시계방향 회전 4회

				for (int currow = 0; currow <= 6 - rows; currow++) { //현재 검사중인 전개도의 처음부터 끝까지 모든 격자점을 확인한다
					for (int curcol = 0; curcol <= 6 - cols; curcol++) { //currow, curcol : 검사 시작점
						isSame = true;

						for (int i = 0; i < rows; i++) { //후보 전개도를 하나씩 맞춰본다
							for (int j = 0; j < cols; j++) {
								if (rawdata[currow + i][curcol + j] != curBlock[i][j]) {
									isSame = false;
									break;
								}
							}
						}

						if (isSame) {
							return true;
						}

					}
				}

				rotateBlock(curBlock);
				swap(rows, cols);
			}
			if (!invert) invertBlock(curBlock);
		}

		curBlock.clear();
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		initialize();
		if (operate()) {
			cout << "yes" << endl;
		}
		else cout << "no" << endl;
	}


	return 0;
}