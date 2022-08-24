#include <string>
#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

bool solution(string s) {
    for (const auto& it : s) {
        if (it == '(') {
            st.push(it);
        }
        else  {
            if (st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        }
    }
    
    if (!st.empty()) return false;
    return true;
}