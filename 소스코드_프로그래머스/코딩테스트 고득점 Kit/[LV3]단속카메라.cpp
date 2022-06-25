#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareOut(const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; }

int operate(vector<vector<int>>& routes) {
    int previousCamera = -30005; //previousCamera : 직전 카메라 위치
    int answer = 0;
    
    for (const auto& outMov : routes) {
        //다음에 나갈 차가, 직전 단속카메라가 나온 이후에 들어온 자동차인가
        if (outMov[0] > previousCamera) {
            answer++;
            previousCamera = outMov[1]; //지금 자동차가 나가는 시점에 카메라를 설치한다
        }
    }
    
    return answer;
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), compareOut);
    return operate(routes);
}