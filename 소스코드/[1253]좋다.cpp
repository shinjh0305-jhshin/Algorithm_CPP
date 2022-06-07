#include <iostream>
#include <unordered_set>
using namespace std;

int nums, maxNum = -2134567890, minNum = 2134567890;
unordered_multiset<int> rawdata;
unordered_multiset<int> resultNum;

void initialize() {
	cin >> nums;
	
	int temp;
	for (int i = 0; i < nums; i++) {
		cin >> temp;
		rawdata.insert(temp);

		maxNum = maxNum > temp ? maxNum : temp;
		minNum = minNum < temp ? minNum : temp;
	}
}

void operate() {
	int add2, result = 0;

	for (const auto target : rawdata) {
		for (const auto add1 : rawdata) {
			if (&target == &add1) continue; //add1 target는 서로 다른 값을 참조할 수 있음이 보장됨

			add2 = target - add1;
			if (add1 == add2 && rawdata.count(add1) < 2) continue; //add1 add2는 서로 다른 값을 참조할 수 있음이 보장됨

			if (rawdata.find(add2) != rawdata.end()) { //add2가 존재한다
				if (add1 == 0 && add2 == 0) {
					if (rawdata.count(0) >= 3) { //add1 == add2 == target == 0인 특수상황
						result++; break;
					}
				}
				else if (add1 == 0 || add2 == 0) {
					if (rawdata.count(target) >= 2) { //add1, add2와 target은 서로 다른 값을 참조하는 것이 보장됨
						result++; break;
					}
				}
				else { //중복 상황이 발생하지 않는다.
					result++; break;
				}
			}

		}
	}

	cout << result << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}