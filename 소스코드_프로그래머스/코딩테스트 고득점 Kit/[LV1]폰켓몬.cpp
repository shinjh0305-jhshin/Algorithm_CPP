#include <vector>
using namespace std;

bool exists[200005];

int solution(vector<int> nums)
{
    int answer = 0;
    
    int types = 0;
    for (const auto& it : nums) {
        if (!exists[it]) {
            exists[it] = true;
            types++;
        }
    }
    
    int target = nums.size() / 2;
    
    answer = target > types ? types : target;
    
    return answer;
}