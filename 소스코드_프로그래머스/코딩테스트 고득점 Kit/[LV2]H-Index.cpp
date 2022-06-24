#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int sz_citations = citations.size();
    sort(citations.begin(), citations.end(), greater<int>());
    
    if (citations[sz_citations - 1] >= citations.size()) return sz_citations;
    
    for (int i = 0; i < sz_citations; i++) {
        if (citations[i] < i + 1) return i;
    }
}