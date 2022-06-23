#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> rawdata;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for (const auto it : clothes) {
        rawdata[it[1]]++;
    }
    
    for (const auto it : rawdata) {
        answer *= (it.second + 1);
    }
    
    return answer - 1;
}