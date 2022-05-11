#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

string st = "";
int len;

bool isGoodString(int stLen) {
	string a, b;
	for (int i = 1; i <= stLen / 2; i++) {
		a = st.substr(stLen - i, i);
		b = st.substr(stLen - i * 2, i);
		if (a == b) return false;
	}
	return true;
}

bool make_st(int stLen) {
	if (stLen == len) return true;
	for (int i = 1; i <= 3; i++) {
		st += i + '0';
		if (isGoodString(stLen + 1)) {
			if (make_st(stLen + 1)) return true;
		}
		st.pop_back();
	}
	return false;
}

void operate() {
	cin >> len;
	make_st(0);
	cout << st << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}


//bool make_ans(int depth) {
//	int temp;
//	bool status;
//
//	for (temp = 1; temp <= 3; temp++) {
//		if (answer.empty()) { //depth == 1인 경우, 즉 첫 번째 숫자를 정하는 경우다.
//			answer.push_back(temp);
//			status = true;
//		}
//		else if (temp == answer.back()) continue; //앞 숫자랑 같으면 바로 다음 숫자로 넘어간다
//		else {
//			auto pos = find(answer.rbegin(), answer.rend(), temp);
//			if (pos == answer.rend()) { //처음 들어오는 숫자다
//				answer.push_back(temp);
//				status = true;
//			}
//			else {
//				auto right = answer.rbegin();
//				auto left = pos + 1;
//				status = false;
//				while (right != pos) {
//					if (left == answer.rend() || *left != *right) { //좋은수열이다
//						answer.push_back(temp);
//						status = true;
//						break;
//					}
//					else { //나쁜 수열이다
//						right++;
//						left++;
//					}
//				}
//			}
//		}
//		if (status == true) { //좋은 수열이 완성되었다.
//			if (depth == len) return true; //주어진 길이의 좋은 수열을 완성했다
//
//			if (make_ans(depth + 1)) return true;
//			else answer.pop_back();
//		}
//	}
//
//	if (temp > 3) { //이전 단계의 값이 잘못되었다.
//		return false;
//	}
//}
//
//void operate() {
//	cin >> len;
//
//	make_ans(1);
//
//	for (auto it : answer) {
//		cout << it;
//	}
//	cout << endl;
//}

