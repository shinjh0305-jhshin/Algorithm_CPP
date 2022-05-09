#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string st;
int sz_string;
vector<int> len;

void initialize() {
	cin >> st;
	sz_string = st.length();
	len.resize(sz_string);
}

void failure() {
	int left, ans = 0;

	for (int left_bound = 0; left_bound < sz_string - 1; left_bound++) { //LEFT를 안 움직이면 맨 처음에서 시작하는 덩어리만 보게 된다!!!!
		left = left_bound; //시점은 문자열의 처음부터 끝까지 모두 보게 된다.
		len[left] = - 1;

		for (int right = left_bound + 1; right < sz_string; right++) { //여기부터는 일반적인 KMP와 동일하다.
			while (1) { 
				if (st[left] == st[right]) {
					len[right] = left - left_bound; //KMP는 index 기반이기에, 왼쪽 시점이 밀린 만큼 이를 결과값에서 빼준다.
					left++;
					break;
				}
				if (left == left_bound) { //left 포인터가 시점까지 돌아왔을 경우.
					len[right] = - 1;
					break;
				}

				left = len[left - 1] + left_bound + 1; //역시 밀린 시점만큼 값을 보정한다.
			}
			ans = max(ans, len[right] + 1); // 한 단계씩 진행 할 때마다 최댓값을 갱신한다.
		}
	}
	

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	failure();

	return 0;
}

/*
asexexssexessex
ans : 4
*/