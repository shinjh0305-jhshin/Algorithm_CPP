#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool dp[2505][2505] = { false };
int result[2505];
string st;
int sz_string;

void initialize() {
	cin >> st;
	sz_string = st.size();
	st.insert(0, "."); //string index를 위한 dummy character
	
	//부분 문자열이 팰린드롬이 되는지를 판별하는 과정이다.
	//문자열의 길이 순서로 팰린드롬 여부를 판정한다.
	for (int i = 1; i <= sz_string; i++) {
		dp[i][i] = true; //길이가 1인 문자열은 팰린드롬이다.
		if (i <= sz_string - 1 && st[i] == st[i + 1]) { //길이가 2인 문자열의 팰린드롬 여부 판별.
			dp[i][i + 1] = true;
		}
	}

	int end_of_start, end;
	for (int sz = 3; sz <= sz_string; sz++) { //길이가 3 이상인 문자열의 팰린드롬 여부 판별.
		end_of_start = sz_string - (sz - 1); //end_of_start : 문자열의 시작 지점의 상한선

		for (int start = 1; start <= end_of_start; start++) { //start : 문자열의 시작 지점
			end = start + sz - 1; //end : 문자열의 종료 지점

			if (st[start] == st[end] && dp[start + 1][end - 1] == 1) { //양 끝단이 같고, 중간이 팰린드롬이면 팰린드롬!
				dp[start][end] = true;
				continue;
			}
		}
	}
}

void operate() {
	result[0] = 0; //문자열의 처음부터 끝까지 팰린드롬인지 판별하는 경우를 대비한 dummy data.

	//문자열의 종료 지점을 기준으로 판별한다.
	for (int back = 1; back <= sz_string; back++) {
		result[back] = 1234567890;
		//처음(start)부터 종료 지점(back)까지 한 칸씩 뒤로가며 그 지점을 쪼개서 확인하는데,
		//쪼개진 부분부터 끝까지가 팰린드롬이라면
		//(처음부터 쪼개진 부분까지 팰린드롬의 최소 개수 + 1) 만큼의 팰린드롬이 생긴다.

		for (int start = 1; start <= back; start++) { 
			if (dp[start][back]) {
				result[back] = min(result[back], result[start - 1] + 1);
			}
		}
	}

	cout << result[sz_string] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}