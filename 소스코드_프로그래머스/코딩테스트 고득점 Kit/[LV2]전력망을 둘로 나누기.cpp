#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool visited[105];
vector<int> map[105];
int answer = 2134567890, nodes;

void initialize(vector<vector<int>>& wires) {
    for (const auto& it : wires) {
        map[it[0]].push_back(it[1]);
        map[it[1]].push_back(it[0]);
    }    
    
    visited[1] = true;
}

int DFS (int node) {
    int temp, sum = 1;
    
    int num1, num2;
    for (const auto& it : map[node]) {
        if (!visited[it]) {
            visited[it] = true;
            
            temp = DFS(it);
            sum += temp;
            
            num1 = nodes - temp;
            num2 = temp;
            
            if (num1 < num2) swap(num1, num2);
            
            answer = min(answer, num1 - num2);
        }
    }
    
    return sum;
}

int solution(int n, vector<vector<int>> wires) {
    nodes = n;
    
    initialize(wires);
    DFS(1);
    
    return answer;
}