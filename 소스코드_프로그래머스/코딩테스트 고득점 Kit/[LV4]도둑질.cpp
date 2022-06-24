#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2][1000005];

int solution(vector<int> money) {
    int house = money.size();
    
    //1. 첫 번째 집을 안 터는 경우
    dp[0][0] = dp[1][0] = 0;
    for (int i = 1; i < house; i++) {
        dp[0][i] = dp[1][i - 1] + money[i];
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }
    
    int firstNotRobbed = max(dp[0][house - 1], dp[1][house - 1]);
    
    //2. 첫 번째 집을 터는 경우
    dp[0][0] = dp[1][0] = dp[0][1] = dp[1][1] = money[0];
    for (int i = 2; i < house - 1; i++) {
        dp[0][i] = dp[1][i - 1] + money[i];
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }
    
    int firstRobbed = max(dp[0][house - 2], dp[1][house - 2]);
    
    return max(firstNotRobbed, firstRobbed);
}