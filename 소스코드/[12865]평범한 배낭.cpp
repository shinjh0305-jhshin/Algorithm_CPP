//0-1 knapsack problem
#include <cstdio>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int sum[102][100002];

class knapsack {
private:
	int items;
	int	weight_max;

public:
	knapsack() :items(0), weight_max(0) {};
	void initialize() {
		scanf("%d %d", &items, &weight_max); getchar();

		for (int i = 0; i <= weight_max; i++) {
			sum[0][i] = 0;
		}
		for (int i = 1; i <= items; i++) {
			sum[i][0] = 0;
		}
	}

	void get_sum() {
		int in_weight, in_value;
		for (int i = 1; i <= items; i++) {
			scanf("%d %d", &in_weight, &in_value); getchar();

			for (int j = 1; j <= weight_max; j++) {
				if (j < in_weight) sum[i][j] = sum[i - 1][j];
				else {
					sum[i][j] = max(sum[i - 1][j], sum[i - 1][j - in_weight] + in_value);
				}
			}
		}
	}

	void print() {
		printf("%d\n", sum[items][weight_max]);
	}
};

int main() {
	knapsack op;
	op.initialize();
	op.get_sum();
	op.print();
	return 0;
}