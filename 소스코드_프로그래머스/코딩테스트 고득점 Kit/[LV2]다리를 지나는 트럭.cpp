#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> qu; //트럭의 무게, 트럭이 나가는 시각

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int weightMargin = weight; //다리의 남은 허용 무게
    int idx = 0, sz_truck = truck_weights.size();
    
    for (int time = 1;; time++) {
        if (!qu.empty() && qu.front().second == time) { //트럭이 나간다!!
            weightMargin += qu.front().first;
            qu.pop();
        }
        if (weightMargin >= truck_weights[idx]) {
            qu.push({ truck_weights[idx], time + bridge_length });
            weightMargin -= truck_weights[idx];
            idx++;
        }
        
        if (idx == sz_truck) {
            return time + bridge_length;
        }
    }
}