#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int numTemp[103];
	int sz_commands = commands.size(), mov;

	for (int i = 0; i < sz_commands; i++) {
		mov = 0;
		for (int inNum = commands[i][0] - 1; inNum <= commands[i][1] - 1; inNum++, mov++) {
			numTemp[mov] = array[inNum];
		}
		sort(numTemp, numTemp + mov);
		answer.push_back(numTemp[commands[i][2] - 1]);
	}


	return answer;
}