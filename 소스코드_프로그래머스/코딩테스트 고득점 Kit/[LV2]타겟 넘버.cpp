#include <string>
#include <vector>

using namespace std;

int DFS(vector<int> &numbers, int idx, int sum, int target) {
    int temp = 0;
    if (idx == numbers.size()) {
        if (sum == target) return 1;
        else return 0;
    }
    temp += DFS(numbers, idx + 1, sum + numbers[idx], target);
    temp += DFS(numbers, idx + 1, sum - numbers[idx], target);
    
    return temp;
}

int solution(vector<int> numbers, int target) {
    int answer = DFS(numbers, 0, 0, target);
    return answer;
}