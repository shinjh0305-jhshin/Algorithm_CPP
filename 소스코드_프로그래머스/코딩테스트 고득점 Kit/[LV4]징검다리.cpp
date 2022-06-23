#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0, right = distance, mid;
    int deletedRock, prevRock;
    
    sort(rocks.begin(), rocks.end());
    
    while (left <= right) {
        mid = (left + right) / 2;
        deletedRock = 0;
        prevRock = 0;
        
        for (const auto curRock : rocks) {
            if (curRock - prevRock < mid) { //이전바위 - 현재바위 사이 거리가 mid 보다 작다 (현재 바위 제거!)
                deletedRock++;
            }
            else { //이전바위 - 현재바위 사이 거리가 mid 보다 크거나 같다 (현재 바위 남긴다!)
                prevRock = curRock;
            }
        }
        
        if (distance - prevRock < mid) deletedRock++;
        
        if (deletedRock > n) right = mid - 1; //더 많은 돌이 제거되었다. 간격을 줄일 필요가 있다.
        else { //적거나 같은 양의 돌이 제거되었다. 간격을 늘릴 필요가 있다.
            answer = max(answer, mid);
            left = mid + 1;
        } 
    }
    
    return answer;
}