#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

struct info {
	int key;
	int frequency;
};
vector<int> rawdata;
vector<info> infodata;

bool compare(const info &a, const info &b) {
	if (a.frequency > b.frequency) return true;
	else if (a.frequency == b.frequency) {
		if (a.key < b.key) return true;
	}
	return false;
}

double average() {
	int sz = rawdata.size();
	double ans = 0;
	for (int i = 0; i < sz; i++) {
		ans += rawdata[i];
	}

	ans /= sz;
	ans = round(ans);
	return ans;
}

int mid() {
	sort(rawdata.begin(), rawdata.end());
	
	int index = rawdata.size() / 2;
	return rawdata[index];
}

int frequent() {
	int frequency = 1, key = rawdata[0], sz = rawdata.size();

	for (int i = 1; i < sz; i++) {
		if (key != rawdata[i]) { //서로 다른 숫자일 경우
			infodata.push_back({ key, frequency });
			key = rawdata[i]; frequency = 1; //초기화
		}
		else { //서로 같은 숫자일 경우
			frequency++;
		}
	}
	infodata.push_back({ key, frequency }); //마지막 숫자 산입

	sort(infodata.begin(), infodata.end(), compare);

	if (infodata.size() > 1 && infodata[0].frequency == infodata[1].frequency) return infodata[1].key;
	else return infodata[0].key;
}

int range() {
	return rawdata.back() - rawdata.front();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nums, temp;

	cin >> nums; cin.get();
	for (int i = 0; i < nums; i++) {
		cin >> temp; cin.get();
		rawdata.push_back(temp);
	}

	cout << average() << endl;
	cout << mid() << endl;
	cout << frequent() << endl;
	cout << range() << endl;

	return 0;
}