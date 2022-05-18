#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int tite[500002] = { 0 }, mite[500002] = { 0 }; //index : 높이
int num_rawdata, height;

void initialize() {
	cin >> num_rawdata >> height;

	int temp;
	for (int i = 0; i < num_rawdata; i++) {
		cin >> temp; //높이가 들어온다

		if (i % 2) tite[temp]++;
		else mite[temp]++;
	}
}

void operate() {
	int miteSum = 0, titeSum = 0; //부숴야 하는 각 물질의 개수
	int minSum = 1234567890, mins = 0;

	for (int i = 1; i < height; i++) miteSum += mite[i]; //높이는 height 보다는 작다
	titeSum = tite[height]; //1층부터 시작한다

	int tempSum;
	for (int i = 1; i <= height; i++) { //1층부터 height(꼭대기) 층까지 탐색한다
		tempSum = miteSum + titeSum;
		if (tempSum < minSum) { //새로운 min 발견
			minSum = tempSum;
			mins = 1;
		}
		else if (tempSum == minSum) mins++; //기존 min개수에 추가!

		miteSum -= mite[i];
		titeSum += tite[height - i];
	}

	cout << minSum << ' ' << mins << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}