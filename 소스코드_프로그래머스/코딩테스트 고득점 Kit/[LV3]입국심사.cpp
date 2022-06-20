#include <string>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

long long solution(int ppls, vector<int> times) {
    ll left = 1, right = 0, mid;
    int desks = times.size();
    
    for (const auto it : times) { //가장 오래 걸리는 심사대를 구한다.
        right = max(right, (ll)it);
    }
    right *= (ppls / desks + 1);    
    
    while (left < right) {
        mid = (left + right) / 2; 
        
        ll maxCapa = 0; //mid 분 동안 처리 할 수 있는 사람 수
        for (const auto it : times) {
            maxCapa += mid / (ll)it;
        }
        
        if (maxCapa >= ppls) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}