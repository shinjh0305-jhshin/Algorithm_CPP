#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#pragma warning (disable:4996)
#define endl "\n"
using namespace std;

class min_dist {
private:
	string str_one, str_two;
	int str_one_size, str_two_size;
	int** rawdata;
public:
	min_dist() :rawdata(NULL), str_one_size(0), str_two_size(0) {};

	void initialize() {
		int i;
		cin >> str_one; cin.get();
		cin >> str_two; cin.get();

		str_one_size = str_one.size();
		str_two_size = str_two.size();

		rawdata = new int*[str_one_size + 1];
		for (i = 0; i <= str_one_size; i++) {
			rawdata[i] = new int[str_two_size + 1];
		}
		for (i = 0; i <= str_one_size; i++) rawdata[i][0] = i;
		for (i = 1; i <= str_two_size; i++) rawdata[0][i] = i;
	}

	void dist() {
		enum op { del, ins, xchg };

		/*int operation[] : 각 operation 별 소요 편집 거리 저장
		  int min_op : operation 배열 내에서 가장 작은 숫자 저장*/
		int operation[3], min_op;

		for (int i = 1; i <= str_one_size; i++) {
			for (int j = 1; j <= str_two_size; j++) {
				min_op = operation[del] = rawdata[i - 1][j] + 1;
				operation[ins] = rawdata[i][j - 1] + 1;
				operation[xchg] = rawdata[i - 1][j - 1];
				if (str_one[i - 1] != str_two[j - 1]) operation[xchg]++;

				for (int k = 1; k <= 2; k++) { //operation 배열 내에서 가장 작은 숫자 찾는 과정
					min_op = min(min_op, operation[k]);
				}
				
				rawdata[i][j] = min_op;
			}
		}
	}

	void js_shit() {
		stack<char> st;
		int i = str_one_size, j = str_two_size, same_char_flag;
		while (i >= 1 && j >= 1) {
			if (str_one[i - 1] == str_two[j - 1]) same_char_flag = 0;
			else same_char_flag = 1;

			if (rawdata[i - 1][j] + 1 == rawdata[i][j]) {
				i--;
				st.push('d');
			}
			else if (rawdata[i][j - 1] + 1 == rawdata[i][j]) {
				j--;
				st.push('i');
			}
			else if (rawdata[i - 1][j - 1] + same_char_flag == rawdata[i][j]) {
				i--; j--;
				if (same_char_flag) st.push('s'); //서로 다른 letter
				else st.push('.'); //서로 같은 letter
			}
		}


		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << endl;

	}

	void print() {
		cout << rawdata[str_one_size][str_two_size] << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);

	min_dist op;
	op.initialize();
	op.dist();
	op.print();
	op.js_shit();
	return 0;
}