#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int horiz, vert;
    for (int i = 1; i * i <= yellow; i++) {
        if (yellow % i == 0) {
            horiz = yellow / i;
            vert = i;
            
            if (horiz * 2 + vert * 2 + 4 == brown) {
                answer.push_back(horiz + 2);
                answer.push_back(vert + 2);
                return answer;
            }
        }
    }
}