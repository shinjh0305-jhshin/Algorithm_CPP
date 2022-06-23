#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int level = triangle.size();
    
    for (int height = 1; height < level; height++) {
        for (int width = 0; width <= height; width++) {
            if (width == 0) {
                triangle[height][0] += triangle[height - 1][0]; 
            }
            else if (width == height) {
                triangle[height][height] += triangle[height - 1][height - 1];
            }
            else {
                triangle[height][width] += max(triangle[height - 1][width - 1], triangle[height - 1][width]);
            }
        }
    }
    
    for (const auto it : triangle[level - 1]) {
        answer = max(answer, it);
    }
    
    return answer;
}