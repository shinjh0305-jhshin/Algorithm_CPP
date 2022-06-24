#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<pair<int, int>> st; //들어온 시간, 가격

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int lenPrices = prices.size();
    answer.resize(lenPrices);
    
    for (int i = 0; i < lenPrices; i++) {
        while (!st.empty() && st.top().second > prices[i]) {
            answer[st.top().first] = i - st.top().first;
            st.pop();
        }
        st.push({ i, prices[i] });
    }
    
    while (!st.empty()) {
        answer[st.top().first] = lenPrices - st.top().first - 1;
        st.pop();
    }
    
    return answer;
}