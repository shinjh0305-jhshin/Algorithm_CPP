#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {    
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = 0, right = people.size() - 1;
    while (left < right) {
        if (people[left] + people[right] <= limit) {
            left++; right--;
        }
        else {
            right--;
        }
        answer++;
    }
    if (left == right) answer++; //마지막 남은 한 사람 처리
    
    return answer;
}