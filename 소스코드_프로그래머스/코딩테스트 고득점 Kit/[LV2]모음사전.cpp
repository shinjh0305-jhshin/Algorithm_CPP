#include <string>
#include <vector>
using namespace std;

string target;
char rawdata[5] = {'A', 'E', 'I', 'O', 'U'};
int answer = 0, idx = 0;

bool DFS(int depth = 0, string st = "") {
    if (st == target) {
        answer = idx;
        return true;
    }
    if (depth == 5) return false;
    
    bool ret;
    for (int k = 0; k < 5; k++) {
        st.push_back(rawdata[k]);
        idx++;
        ret = DFS(depth + 1, st);
        
        if (ret) return true;
         
        st.pop_back();
    }
    
    return false;
}

int solution(string word) {
    target = word;
    
    DFS();
    
    return answer;
}