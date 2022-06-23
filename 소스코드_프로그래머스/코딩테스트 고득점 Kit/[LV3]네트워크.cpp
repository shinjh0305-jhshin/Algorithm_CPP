#include <string>
#include <vector>

using namespace std;

bool visited[205] = { false };
int sz_computers;

void DFS(int node, vector<vector<int>>& computers) {
    visited[node] = true;
    
    for (int i = 0; i < sz_computers; i++) {
        if (i == node) continue;
        if (computers[node][i] == 1 && !visited[i]) {
            DFS(i, computers);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    sz_computers = computers.size();
    
    for (int i = 0; i < sz_computers; i++) {
        if (!visited[i]) {
            DFS(i, computers);
            answer++;
        }
    }
    return answer;
}