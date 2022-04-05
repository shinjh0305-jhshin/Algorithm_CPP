/******************************************/
// Floyd algorithm 
// a.k.a  all pairs shortest paths problem
/******************************************/

#include <cstdio>
#include <cstring>
#include <stack> //PATH FINDER
#pragma warning (disable:4996)
#define INF 98765432
using namespace std;

class floyd {
private:
	int ** route = NULL;
	int ** path_save = NULL;
	int edge_num, node_num;

public:
	floyd() : edge_num(0), node_num(0) {};

	void initialize() {
		int start_node, end_node, cost;

		scanf("%d", &node_num); getchar();
		scanf("%d", &edge_num); getchar();
		
		route = new int*[node_num + 1];
		for (int i = 1; i <= node_num; i++) {
			route[i] = new int[node_num + 1];
		}

		/*PATH FINDER*/
		path_save = new int*[node_num + 1];
		for (int i = 1; i <= node_num; i++) {
			path_save[i] = new int[node_num + 1];
			memset(path_save[i], 0, sizeof(int)*(node_num + 1));
		}

		/***********************************************
		start_mov : 배열의 row 이동
		end_mov : 배열의 column 이동
		***********************************************/
		int start_mov = 0, end_mov = 0;

		for (start_mov = 1; start_mov <= node_num; start_mov++) {
			for (end_mov = 1; end_mov <= node_num; end_mov++) {
				route[start_mov][end_mov] = INF;
			}
		}

		for (int i = 0; i < edge_num; i++) {
			scanf("%d %d %d", &start_node, &end_node, &cost); getchar();
			if (route[start_node][end_node] > cost) {
				route[start_node][end_node] = cost;
			}
		}
	}

	void get_path() {
		int temp;

		for (int k = 1; k <= node_num; k++) {
			for (int i = 1; i <= node_num; i++) {
				for (int j = 1; j <= node_num; j++) {
					temp = route[i][k] + route[k][j];

					if (temp < route[i][j]) {
						route[i][j] = temp;
						path_save[i][j] = k; //PATH FINDER
					}
				}
			}
		}
	}

	void print_result() {
		for (int i = 1; i <= node_num; i++) {
			for (int j = 1; j <= node_num; j++) {
				if (i == j || route[i][j] == INF) {
					printf("0 ");
				}
				else {
					printf("%d ", route[i][j]);
				}
			}
			printf("\n");
		}
	}

	void find_path() {
		stack<int> ST;
		int flag, start, end, mov;

		while (1) {
			printf("Find Path? (NO :0, YES : 1) ");
			scanf("%d", &flag); getchar();
			if (!flag) return;

			printf("Start and end : ");
			scanf("%d %d", &start, &end); getchar();
			mov = end;

			ST.push(end);
			while (path_save[start][mov]) {
				ST.push(path_save[start][mov]);
				mov = path_save[start][mov];
			}
			ST.push(start);

			printf("Route : ");
			while (!ST.empty()) {
				printf("%d ", ST.top());
				ST.pop();
			}
			printf("\n");
		}
	}
};

int main() {
	floyd op;
	op.initialize();
	op.get_path();
	op.print_result();
	op.find_path();
	return 0;
}