#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> maxheap, maxDelheap;
priority_queue<int, vector<int>, greater<int>> minheap, minDelheap;

void insertNum(int num) {
    maxheap.push(num);
    minheap.push(num);
}

void getAns(vector<int>& answer) {
    while (!maxDelheap.empty() && !maxheap.empty() && maxheap.top() == maxDelheap.top()) { //minheap에서 삭제 된 숫자를 전부 없앤다.
        maxheap.pop();
        maxDelheap.pop();
    }
    
    if (maxheap.empty()) answer.push_back(0);
    else answer.push_back(maxheap.top());
    
    while (!minDelheap.empty() && !minheap.empty() && minheap.top() == minDelheap.top()) { //maxheap에서 삭제 된 숫자를 전부 없앤다.
        minheap.pop();
        minDelheap.pop();
    }
    
    if (minheap.empty()) answer.push_back(0);
    else answer.push_back(minheap.top());

}

int deleteMin() {    
    while (!minDelheap.empty() && !minheap.empty() && minheap.top() == minDelheap.top()) { //maxheap에서 삭제 된 숫자를 전부 없앤다.
        minheap.pop();
        minDelheap.pop();
    }
    
    if (minheap.empty()) return 0; //빈 힙일 경우 무시!
    
    int ret = minheap.top(); minheap.pop();
    maxDelheap.push(ret); //minheap에서 삭제 된 숫자를 maxDelheap에 준다.
    
    return ret;
}

int deleteMax() {    
    while (!maxDelheap.empty() && !maxheap.empty() && maxheap.top() == maxDelheap.top()) { //minheap에서 삭제 된 숫자를 전부 없앤다.
        maxheap.pop();
        maxDelheap.pop();
    }
    
    if (maxheap.empty()) return 0;
    
    int ret = maxheap.top(); maxheap.pop();
    minDelheap.push(ret); //maxheap에서 삭제 된 숫자를 minDelheap에 준다.
    
    return ret;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for (const auto it : operations) {
        if (it[0] == 'I') {
            insertNum(stoi(it.substr(2)));
        } else {
            if (it[2] == '-') {
                deleteMin();
            } else {
                deleteMax();
            }
        }
    }
    
    getAns(answer);
    
    return answer;
}