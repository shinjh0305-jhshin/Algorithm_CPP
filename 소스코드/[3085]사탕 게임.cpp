#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

class candy_game {
private:
	vector<char> rawdata[50];
	int board_size;

public:
	void initialize() {
		cin >> board_size; cin.get();
		for (int i = 0; i < board_size; i++) {
			for (int j = 0; j < board_size; j++) {
				rawdata[i].push_back(cin.get());
			}
			cin.get();
		}
	}

	void operate() {
		// **saved_max : global maximum,  **current_calc : local maximum
		int front, back, i, j, k, saved_max = 0, current_calc;
		for (i = 0; i < board_size; i++) { //가로 방향의 이웃한 한 쌍을 바꾸는 과정
			for (front = 0; front <= board_size - 2; front++) { 
				back = front + 1;
				swap(rawdata[i][front], rawdata[i][back]); //가로 index는 고정

				current_calc = 1;
				for (j = 0; j <= board_size - 2; j++) { //가로 방향에서 가장 긴 같은 사탕 고르기
					if (rawdata[i][j] == rawdata[i][j + 1]) { //가로 index는 고정
						current_calc++;
					}
					else {
						if (current_calc > saved_max) saved_max = current_calc;
						current_calc = 1;
					}
				}
				if (current_calc > saved_max) saved_max = current_calc; //마지막에까지 연속된 같은 사탕이 있으면 체크

				for (k = front; k <= back; k++) { //세로 방향에서 가장 긴 같은 사탕 고르기, 2번 반복해야됨
					current_calc = 1;
					for (j = 0; j <= board_size - 2; j++) {
						if (rawdata[j][k] == rawdata[j + 1][k]) { //세로 index는 고정
							current_calc++;
						}
						else {
							if (current_calc > saved_max) saved_max = current_calc; 
							current_calc = 1;
						}
					}
				}
				if (current_calc > saved_max) saved_max = current_calc; //마지막에까지 연속된 같은 사탕이 있으면 체크

				swap(rawdata[i][front], rawdata[i][back]); //원상복구
			}
		}

		for (i = 0; i < board_size; i++) { //세로 방향의 이웃한 한 쌍을 바꾸는 과정
			for (front = 0; front <= board_size - 2; front++) {
				back = front + 1;
				swap(rawdata[front][i], rawdata[back][i]); //세로 index는 고정

				current_calc = 1;
				for (j = 0; j <= board_size - 2; j++) { //세로 방향에서 가장 긴 같은 사탕 고르기
					if (rawdata[j][i] == rawdata[j + 1][i]) { //세로 index는 고정
						current_calc++;
					}
					else {
						if (current_calc > saved_max) saved_max = current_calc;
						current_calc = 1;
					}
				}
				if (current_calc > saved_max) saved_max = current_calc; //마지막에까지 연속된 같은 사탕이 있으면 체크

				for (k = front; k <= back; k++) { //가로 방향에서 가장 긴 같은 사탕 고르기, 2번 반복해야됨
					current_calc = 1;
					for (j = 0; j <= board_size - 2; j++) {
						if (rawdata[k][j] == rawdata[k][j + 1]) { //세로 index는 고정
							current_calc++;
						}
						else {
							if (current_calc > saved_max) saved_max = current_calc;
							current_calc = 1;
						}
					}
				}
				if (current_calc > saved_max) saved_max = current_calc; //마지막에까지 연속된 같은 사탕이 있으면 체크

				swap(rawdata[front][i], rawdata[back][i]);
			}
		}
		cout << saved_max << endl;
	}

};

int main() {
	ios::sync_with_stdio(false);
	candy_game op;
	op.initialize();
	op.operate();
	return 0;
}