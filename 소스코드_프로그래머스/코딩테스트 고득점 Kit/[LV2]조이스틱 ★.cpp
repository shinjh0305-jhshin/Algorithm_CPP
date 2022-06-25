//A가 아닌 글자인 현재 글자 위치를 X, X 직후에 나오는 A가 아닌 글자 위치를 Y라 하자.
//X위치가 갱신될 때 마다, min(원점-X-원점-Y, 원점-Y-원점-X)를 진행한다.

#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int nameLen = name.length(), nextIdx;
    
    int route = name.length() - 1; //최소 왕복 경로를 저장한다.
    
    for (int curIdx = 0; curIdx < nameLen; curIdx++) {
        answer += min(name[curIdx] - 'A', 'Z' - name[curIdx] + 1); //알파벳 바꾸는 경우!

        nextIdx = curIdx + 1;
        while (nextIdx < nameLen && name[nextIdx] == 'A') nextIdx++; //curIdx 다음에 나오는 A가 아닌 글자 위치 찾는다

        route = min(route, min(2 * curIdx + nameLen - nextIdx, 2 * (nameLen - nextIdx) + curIdx)); //min(Origin-X-Origin-Y, Origin-Y-Origin-X)
    }
    
    answer += route;
    
    return answer;
}