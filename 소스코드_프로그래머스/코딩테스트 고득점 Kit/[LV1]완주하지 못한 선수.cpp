#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> rawdata;

string solution(vector<string> participant, vector<string> completion) {
	string answer;

	for (auto it : participant) {
		rawdata[it]++;
	}

	for (auto it : completion) {
		rawdata[it]--;
	}

	for (auto it : rawdata) {
		if (it.second != 0) {
			answer = it.first;
			break;
		}
	}

	return answer;
}