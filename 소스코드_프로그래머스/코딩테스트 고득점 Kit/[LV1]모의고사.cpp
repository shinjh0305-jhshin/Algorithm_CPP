#include <string>
#include <vector>

using namespace std;

int problems;

int student1(vector<int>& answers) {
	int correct = 0;
	for (int i = 0; i < problems; i++) {
		if (answers[i] == i % 5 + 1) correct++;
	}

	return correct;
}

int student2(vector<int>& answers) {
	int correct = 0;
	for (int i = 0; i < problems; i++) {
		if (i % 2 == 0) { if (answers[i] == 2) correct++; }
		else {
			int idx = i % 8;
			if (idx == 7) { if (answers[i] == 5) correct++; }
			else if (idx == 5) { if (answers[i] == 4) correct++; }
			else if (idx == 3) { if (answers[i] == 3) correct++; }
			else if (idx == 1) { if (answers[i] == 1) correct++; }
		}
	}
	return correct;
}

int student3(vector<int>& answers) {
	int correct = 0;
	for (int i = 0; i < problems; i++) {
		int idx = i % 10;
		if (idx <= 1) { if (answers[i] == 3) correct++; }
		else if (idx <= 3) { if (answers[i] == 1) correct++; }
		else if (idx <= 5) { if (answers[i] == 2) correct++; }
		else if (idx <= 7) { if (answers[i] == 4) correct++; }
		else if (idx <= 9) { if (answers[i] == 5) correct++; }
	}
	return correct;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	problems = answers.size();

	int temp, maxCorrect;
	/*
	answer.push_back(student1(answers));
	answer.push_back(student2(answers));
	answer.push_back(student3(answers));
	*/

	maxCorrect = temp = student1(answers);
	answer.push_back(1);

	temp = student2(answers);
	if (maxCorrect <= temp) {
		if (maxCorrect < temp) answer.pop_back();
		answer.push_back(2);
		maxCorrect = temp;
	}

	temp = student3(answers);
	if (maxCorrect <= temp) {
		if (maxCorrect < temp) answer.clear();
		answer.push_back(3);
	}

	return answer;
}