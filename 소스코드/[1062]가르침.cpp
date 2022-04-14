//bitset을 이용해서 시간 줄여보기

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
using namespace std;

int words, numLearn, ans = 777;
vector<int> rawdata; //들어오는 단어들의 가변 부분을 bitmasking 한 값 저장. (antic제외)
vector<int> rawdataNum; //가변 부분에서 한 번이라도 나온 글자의 bitmask index 저장. (antic제외)

void initialize() {
	cin >> words >> numLearn;
	
	numLearn -= 5; //antic는 무조건 가르쳐야하기에, 이를 제외한 나머지 알파벳을 가르친다.
	rawdata.resize(words);
	
	string temp;
	int num, sz_temp, sumRawdata = 0; //sumRawdata : 가변 부분을 전부 or 연산한 값
	for (int i = 0; i < words; i++) {
		cin >> temp;

		num = 0;
		sz_temp = temp.size() - 4;

		for (int j = 4; j < sz_temp; j++) {
			if (temp[j] == 'a' || temp[j] == 'n' || temp[j] == 't' || temp[j] == 'i' || temp[j] == 'c') continue;
			num |= (1 << (temp[j] - 'a'));
		}
		rawdata[i] = num; //rawdata에는 antic를 제외한 배워야 할 알파벳들이 남는다.
		sumRawdata |= num;
	}

	if (numLearn < 0) {
		ans = 0;
		return;
	}

	for (int i = 0; i < 26; i++) {
		if ((sumRawdata >> i) & 1) {
			rawdataNum.push_back(i);
		}
	}

	if (numLearn >= rawdataNum.size()) ans = words; //가르쳐야 하는 글자가 단어 안에 있는 글자보다 많다.
}

void DFS(int rawdata_idx, int depth, int& tempNum) { //depth : 지금까지 배운 숫자의 개수
	if (depth != numLearn) { 
		int upperBound = rawdataNum.size() - (numLearn - depth); //배워야 되는 숫자보다 남은 숫자가 적어지는 경우 배제
		for (int i = rawdata_idx; i <= upperBound; i++) {
			tempNum |= (1 << (rawdataNum[i]));
			DFS(i + 1, depth + 1, tempNum);
			tempNum &= ~(1 << rawdataNum[i]);
		}
	}
	else {
		int ans_temp = 0;
		for (int k = 0; k < words; k++) {
			for (int i = 0; i < 26; i++) {
				if ((rawdata[k] >> i) & 1) {
					if ((tempNum >> i) & 1) continue;
					else {
						ans_temp--;
						break;
					}
				}
			}
			ans_temp++;
		}

		ans = max(ans, ans_temp);
	}
}

void operate() {
	if (ans != 777) {
		cout << ans << endl;
		return;
	}

	ans = 0;
	int tempNum = 0;
	//접두사 anta 접미사 tica에서 antic는 무조건 가르친다
	tempNum |= (1 << ('a' - 'a'));
	tempNum |= (1 << ('n' - 'a'));
	tempNum |= (1 << ('t' - 'a'));
	tempNum |= (1 << ('i' - 'a'));
	tempNum |= (1 << ('c' - 'a'));

	DFS(0, 0, tempNum);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	initialize();
	operate();

	return 0;
}

/*
3 8
antacbetica
antachemtica
antatica
ans : 2

1 5
antatica

ans : 1

3 7
antawxtica
antaytica
antaztica
ans : 2
*/