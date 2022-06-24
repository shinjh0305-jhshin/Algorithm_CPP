#include <string>
#include <vector>
#define MOD 1000000007;


using namespace std;

int map[105][105] = { 0 };

int solution(int cols, int rows, vector<vector<int>> puddles) { //col,row
    //initializing phase
    for (const auto it : puddles) {
        map[it[1] - 1][it[0] - 1] = -1; //puddle
    }
    for (int i = 1; i < cols; i++) {
        if (map[0][i] == -1) break;
        map[0][i] = 1;
    }
    for (int i = 1; i < rows; i++) {
        if (map[i][0] == -1) break;
        map[i][0] = 1;
    }

    
    for (int row = 1; row < rows; row++) {
        for (int col = 1; col < cols; col++) {
            if (map[row][col] == -1) continue;
            if (map[row - 1][col] != -1) map[row][col] += map[row - 1][col];
            if (map[row][col - 1] != -1) map[row][col] += map[row][col - 1];
            map[row][col] %= MOD;
        }
    }
    
    return map[rows - 1][cols - 1];
}