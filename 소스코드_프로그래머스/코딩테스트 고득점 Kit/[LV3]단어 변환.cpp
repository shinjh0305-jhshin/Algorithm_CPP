#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int wordLen;

bool compare (string& st1, string& st2) { //st1과 st2가 1글자가 다른지 확인
    bool ret = true;
    for (int i = 0; i < wordLen; i++) {
        if (st1[i] != st2[i]) {
            if (ret) ret = false; //1개 다를 때는 그냥 false로 처리
            else return false; //2개 이상 다르면 return false 
        }
    }
    if (ret == false) return true; //1개가 다른 경우 true
    return false; //다 똑같을 경우 false
}

int solution(string begin, string target, vector<string> rawdata) {
    int answer = 0;
    if (find(rawdata.begin(), rawdata.end(), target) == rawdata.end()) return 0; //최종 글자가 rawdata에 없는 경우
    
    int words = rawdata.size(); //주어진 단어의 개수
    bool used[52] = { false }; //방문한 단어인지 확인
    queue<int> qu; //BFS 큐
    int sz_queue, curStringIdx;
    wordLen = begin.length();
    
    //initialize phase
    for (int i = 0; i < words; i++) {
        if (compare(begin, rawdata[i])) {
            qu.push(i);
            used[i] = true;
        }
    }
    
    //operation phase
    for (answer = 1;; answer++) {
        sz_queue = qu.size();
        while (sz_queue--) {
            curStringIdx = qu.front(); qu.pop(); //현재 작업중인 글자
            if (rawdata[curStringIdx] == target) return answer; //target 글자 발견!
            
            for (int i = 0; i < words; i++) { //i : 돌아다니면서 비교되는 대상
                if (!used[i] && compare(rawdata[curStringIdx], rawdata[i])) { //검토하지 않았으며, 1글자 차이 나는 단어 발견!
                    qu.push(i);
                    used[i] = true;
                }
            }
        }
    }
}