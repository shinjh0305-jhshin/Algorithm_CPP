#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxMax = 0, minMax = 0;
    int num1, num2;
    for (const auto& it : sizes) {
        num1 = it[0]; num2 = it[1];
        if (num1 < num2) swap(num1, num2);
        
        maxMax = max(num1, maxMax);
        minMax = max(num2, minMax);
    }
    
    return minMax * maxMax;
}