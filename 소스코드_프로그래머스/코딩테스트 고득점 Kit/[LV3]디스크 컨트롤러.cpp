#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct info { //작업 대기 시간 = 작업 시작 시각 + cost - reqTime
    int reqTime; //요청이 들어온 시각
    int cost; //소요 시간. pq의 정렬 기준.
};
struct compareheap {
    bool operator() (const info& a, const info& b) {
        if (a.cost > b.cost) return true;
        else if (a.cost == b.cost) {
            if (a.reqTime > b.reqTime) return true;
        }
        return false;
    }
};

bool compare(const vector<int>& a, const vector<int>& b) { //{요청 시각, 소요시간}
    return a[0] < b[0]; //요청 시각이 이른 순으로 정렬
}
priority_queue<info, vector<info>, compareheap> pq; //지금 시점에 진행할 수 있는 작업 중 소요시간이 가장 작은 작업

int solution(vector<vector<int>> jobs) { //{요청 시각, 소요시간}
    int sz_jobs = jobs.size();
    
    sort(jobs.begin(), jobs.end(), compare); //요청 시각이 이른 순으로 정렬한다.
    
    int jobsIdx = 0; //jobs 배열을 보면서, 현재 시각에 새로운 작업을 pq에 넣을 수 있는지를 판단한다.
    //아래 두 개 변수는 job을 시작할 때 값을 최신화한다.
    int currentJobEnd = -1; //현재 진행중인 작업이 마무리 되는 시각.
    int timeSum = 0; //전체적인 작업이 기다린 시간.
    
    for (int currentTime = 0;; currentTime++) {
        //지금 시각부터 시작할 수 있는 모든 작업을 pq에 넣는다.
        while (jobsIdx < sz_jobs && jobs[jobsIdx][0] == currentTime) { //현재 시각과 같다
            pq.push({ jobs[jobsIdx][0], jobs[jobsIdx][1] }); //새로운 작업을 pq에 넣는다.
            jobsIdx++; //다음 job으로 넘어간다
        }
        
        //현재 작업하는 요청이 없는 경우. 지금 막 다른 요청을 마무리 한 경우
        if (currentJobEnd <= currentTime) {
            if (!pq.empty()) { //대기중인 요청이 있는 경우
                currentJobEnd = currentTime + pq.top().cost; //새로운 작업의 종료시각 설정
                timeSum += currentJobEnd - pq.top().reqTime; //누적 시간을 추가한다.
                pq.pop();
            }
        }
        
        if (jobsIdx >= sz_jobs && pq.empty()) break; //모든 작업이 힙에 들어갔고, 모든 작업이 실행된 경우 끝낸다.
    }
    
    return timeSum / sz_jobs;
}