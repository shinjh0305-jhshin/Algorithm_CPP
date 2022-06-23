#include <string>
#include <vector>

using namespace std;

bool visited[105][105] = { false };

void initialize(int n, vector<vector<int>>& results) {
    for (const auto it : results) {
        visited[it[0]][it[1]] = true;
    }
    for (int i = 1; i <= n; i++) {
        visited[i][i] = true;
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    initialize(n, results);
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (!visited[i][k]) continue;
            for (int j = 1; j <= n; j++) {
                if (visited[k][j]) {
                    visited[i][j] = true;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        bool status = true;
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j] && !visited[j][i]) {
                status = false;
                break;
            }
        }
        if (status) answer++;
    }
    
    return answer;
}