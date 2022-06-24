#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int root[105];

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

void initialize(int n, vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(), compare);
    for (int i = 0; i < n; i++) {
        root[i] = -1;
    }
}

int getRoot(int num) {
    if (root[num] < 0) return num;
    else return root[num] = getRoot(root[num]);
}

bool mergeRoot(int num1, int num2) {
    int root1 = getRoot(num1);
    int root2 = getRoot(num2);
    
    if (root1 == root2) return false;
    
    if (root[root1] > root[root2]) swap(root1, root2);
    
    root[root1] += root[root2];
    root[root2] = root1;
    
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    initialize(n, costs);
    
    int edges = 0; //n-1개의 edge가 생겨야 tree가 된다.
    for (int i = 0;; i++) {
        if (mergeRoot(costs[i][0], costs[i][1])) { //서로 합쳐짐
            edges++;
            answer += costs[i][2];
            
            if (edges == n - 1) return answer;
        }
    }
}