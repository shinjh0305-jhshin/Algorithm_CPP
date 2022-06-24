#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int lenNum = number.length();
    
    answer.push_back(number[0]);
    for (int i = 1; i < lenNum; i++) {
        while (!answer.empty() && k && answer.back() < number[i]) {
            answer.pop_back();
            k--;
        }
        answer.push_back(number[i]);
    }
    
    while (k) {
        answer.pop_back();
        k--;
    }
    
    return answer;
}