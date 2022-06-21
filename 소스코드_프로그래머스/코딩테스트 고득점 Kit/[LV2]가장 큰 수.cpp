#include string
#include vector
#include algorithm

using namespace std;

vectorstring rawdata;
 
bool compare(const string& a, const string& b) {
    string lr = a + b;
    string rl = b + a;
    
    if (lr  rl) return true;
    return false;
}

string solution(vectorint numbers) {
    string answer = ;
    
    for (const auto it  numbers) {
        rawdata.push_back(to_string(it));
    }
    
    sort(rawdata.begin(), rawdata.end(), compare);
    
    if (rawdata[0] == 0) return 0;
    
    for (const auto it  rawdata) {
        answer += it;
    }
    return answer;
}