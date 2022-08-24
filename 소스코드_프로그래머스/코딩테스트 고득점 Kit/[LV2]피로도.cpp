#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[10];
int sz_dungeon, answer = -1;

void DFS(int curStat, int node, vector<vector<int>>& dungeons, int depth = 1) {
    visited[node] = true;
    curStat -= dungeons[node][1];

    for (int i = 0; i < sz_dungeon; i++) {
        if (visited[i] || curStat < dungeons[i][0]) continue;
        DFS(curStat, i, dungeons, depth + 1);
    }
    
    answer = max(answer, depth);
    visited[node] = false;
}

int solution(int k, vector<vector<int>> dungeons) {
    sz_dungeon = dungeons.size();
    
    for (int i = 0; i < sz_dungeon; i++) {
        DFS(k, i, dungeons);
    }
    
    return answer;
}