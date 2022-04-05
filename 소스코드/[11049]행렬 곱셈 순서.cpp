/*추후 발전사항*/
//어떤 방식으로 곱셈을 했는지 괄호를 넣어서 식 하나로 표현하면 어떨까?
//필요 : 괄호 판별 알고리즘 -> 자료구조에서 배운거 써먹을까...??

#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
#pragma warning (disable:4996)

struct mtx_sz {
	int row;
	int col;
};

class mtx_mult {
private:
	int mtx_cnt; /*matrix 개수*/
	mtx_sz* size_info; /*matrix의 사이즈 저장*/
	unsigned int** rawdata; /*행렬 곱셈 횟수 저장*/
	int i, j; /*iterating variable*/
public:
	mtx_mult() :mtx_cnt(0), rawdata(NULL), i(0), j(0) {};
	void initialize() {
		scanf("%d", &mtx_cnt); getchar();
		size_info = new mtx_sz[mtx_cnt + 1];

		for (i = 1; i <= mtx_cnt; i++) {
			scanf("%d %d", &size_info[i].row, &size_info[i].col); getchar();
		}
	}

	void get_opt() {
		int back_mov, front_mov;
		rawdata = new unsigned int*[mtx_cnt + 1];

		for (i = 1; i <= mtx_cnt; i++) {
			rawdata[i] = new unsigned int[mtx_cnt + 1];
		}

		for (i = 1; i <= mtx_cnt; i++) { /*자기자신을 곱할 때는 곱셈 횟수 == 0*/
			rawdata[i][i] = 0;
		}

		//Version 1
		/*AB, BC, CD ...하고(case 1) ABC, BCD, CDE ...하고(case 2) ABCD BCDE CDEF ...하는식(case 3)으로 진행*/
		//for (i = 2; i <= mtx_cnt; i++) { /*case가 거듭될수록 AB, ABC, ABCD 등 첫 곱셈의 끝 matrix 가 뒤로간다*/
		//	back_mov = i;
		//	for (front_mov = 1; back_mov <= mtx_cnt; front_mov++, back_mov++) { /*case x 내에서 돌아가는 반복문*/
		//		rawdata[front_mov][back_mov] = INT_MAX; /*initialize*/

		//		for (j = front_mov; j < back_mov; j++) { /*case x의 특정 원소가 갖는 곱셈 경우의 수 전부 확인 (j : 분절점)*/
		//			rawdata[front_mov][back_mov] = min(rawdata[front_mov][back_mov], rawdata[front_mov][j] + rawdata[j + 1][back_mov]
		//				+ size_info[front_mov].row*size_info[j].col*size_info[back_mov].col);
		//		}
		//	}
		//}

		//Version 2 -> lecture version
		/*맨 밖 for loop이 거리로 쪼개져 있는 것 이외에 다른 점 없다.*/
		for (i = 1; i <= mtx_cnt - 1; i++) { // i : matrix 간 거리
			for (front_mov = 1; front_mov <= mtx_cnt - i; front_mov++) {
				back_mov = front_mov + i;

				rawdata[front_mov][back_mov] = INT_MAX; /*initialize*/

				for (j = front_mov; j < back_mov; j++) { /*case x의 특정 원소가 갖는 곱셈 경우의 수 전부 확인 (j : 분절점)*/
					rawdata[front_mov][back_mov] = min(rawdata[front_mov][back_mov], rawdata[front_mov][j] + rawdata[j + 1][back_mov]
						+ size_info[front_mov].row*size_info[j].col*size_info[back_mov].col);
				}
			}
		}
	}
	
	void print_result() {
		printf("%d\n", rawdata[1][mtx_cnt]);
	}
};

int main() {
	mtx_mult op;
	op.initialize();
	op.get_opt();
	op.print_result();
	return 0;
}