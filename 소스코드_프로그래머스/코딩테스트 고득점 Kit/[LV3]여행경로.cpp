#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct edge {
    string from ,to;
};
vector<edge> tickets;
unordered_map<string, vector<int>> rawdata; //string : 공항명, rawdata : tickets 벡터의 index를 넣는다.

bool compare(const edge& a, const edge& b) {
    return a.to > b.to;
}

void initialize(vector<vector<string>>& input) {
    for (const auto& it : input) {
        tickets.push_back({ it[0], it[1] });
    }
    sort(tickets.begin(), tickets.end(), compare);
    
    for (int i = 0; i < tickets.size(); i++) {
        rawdata[tickets[i].from].push_back(i);
    }
}

void operate(vector<string>& answer) {
    stack<string> st;
    st.push("ICN");
    
    string curAirport, nextAirport;
    int curTicket;
    while (!st.empty()) {
        curAirport = st.top();
        
        if (!rawdata[curAirport].empty()) { //사용하지 않은 비행기표가 있다.
            curTicket = rawdata[curAirport].back(); //지금 사용할 비행기표
            nextAirport = tickets[curTicket].to;
            st.push(nextAirport);
            rawdata[curAirport].pop_back(); //사용한 비행기표는 없앤다.
        } else { //비행기표를 전부 사용했다.
            answer.push_back(curAirport);
            st.pop();
        }
    }
    
}

vector<string> solution(vector<vector<string>> input) {
    vector<string> answer;
    
    initialize(input);    
    operate(answer);
    
    reverse(answer.begin(), answer.end());

    return answer;
}