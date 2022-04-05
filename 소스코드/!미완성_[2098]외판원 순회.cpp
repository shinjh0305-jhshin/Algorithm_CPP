/**************************************************************************************************/
//문제의 주안점 : DFS, DP, Bitmasking
//Key Point : 시작점이 주어지지 않았더라도, 하나의 정점에서만 고려해도 된다.
//사유 : 0123450이 최소(1000원)라고 하면, 이 경로는 2345012(역시 1000원)와 정확히 일치하기 때문.
/**************************************************************************************************/
#include <cstdio>
#include <algorithm>
#pragma warning (disable:4996)

class operate {
private:
	int city_no; //도시 수
	int cost[16][16]; //비용 배열
	int result[16][1 << 16]; //결과 저장 배열

public:
	operate() :city_no(0) {};

	void initialize() {
		scanf("%d", &city_no); getchar();

		for (int i = 0; i < city_no; i++) {
			for (int j = 0; j < city_no; j++) {
				scanf("%d", &cost[i][j]); getchar();
			}
		}
	}

	void traverse() {

	}
};