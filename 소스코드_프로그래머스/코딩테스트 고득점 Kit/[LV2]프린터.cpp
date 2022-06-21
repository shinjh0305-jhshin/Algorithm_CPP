#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> qu;

void initialize(vector<int>& priorities) {
    int sz_rawdata = priorities.size();
    for (int i = 0; i < sz_rawdata; i++) {
        qu.push({ i, priorities[i] }); //인쇄 일련번호, 인쇄 우선순위
    }
    sort(priorities.begin(), priorities.end(), greater<int>());
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    initialize(priorities);
    
    int sortedIdx = 0;
    while (1) {
        if (qu.front().second == priorities[sortedIdx]) { //맨 앞 문서 우선순위 == 현재 최고 우선순위
            if (qu.front().first == location) { //인쇄 일련번호 == 내가 찾는 일련번호
                return sortedIdx + 1;
            }
            qu.pop(); //문서 인쇄
            sortedIdx++; //다음 최고 일련번호 가져오기
        }
        else { //맨 앞 문서 우선순위 != 현재 최고 우선순위
            const auto temp = qu.front(); qu.pop(); //pop 한 뒤 다시 넣기
            qu.push(temp);
        }
    }
}