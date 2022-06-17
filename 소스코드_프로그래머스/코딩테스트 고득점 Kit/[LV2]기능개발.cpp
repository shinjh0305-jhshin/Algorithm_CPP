#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int curTopProgress = 0, sz_progress = progresses.size();

	int progressToPop;
	while (curTopProgress < sz_progress) {
		for (int mov = curTopProgress; mov < sz_progress; mov++) { //시간을 전부 더한다.
			if (progresses[mov] >= 100) continue; //이미 완료되어 앞 작업이 끝날 때 까지 기다리는 작업
			progresses[mov] += speeds[mov];
		}

		progressToPop = 0; //오늘 작업을 마친 뒤, 완료되어 pop 할 수 있는 프로그래스
		for (int mov = curTopProgress; mov < sz_progress; mov++) {
			if (progresses[mov] >= 100) progressToPop++;
			else break;
		}

		if (progressToPop) answer.push_back(progressToPop);
		curTopProgress += progressToPop;
	}

	return answer;
}