#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[20003] = { false };
queue<int> qu;
vector<int> map[20003];

void initialize(vector<vector<int>>& edge) {
    for(const auto it : edge) {
        map[it[0]].push_back(it[1]);
        map[it[1]].push_back(it[0]);
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    initialize(edge);
    
    visited[1] = true;
    qu.push(1);

    int size_qu, curNode, nextNode;
    while (!qu.empty()) {
        size_qu = qu.size();
        for (int i = 0; i < size_qu; i++) {
            curNode = qu.front(); qu.pop();
            
            for (const auto nextNode : map[curNode]) {
                if (!visited[nextNode]) {
                    visited[nextNode] = true;
                    qu.push(nextNode);
                }
            }
        }
    }
    
    return size_qu;
}