#include <cstdio>
#include <cmath>
#include <stack>
#include <limits.h>
using namespace std;

#pragma warning (disable:4996)


/*greedy approach*/
//class operate {
//private:
//	double num;
//	int result;
//	stack<double> stack;
//
//public:
//	operate() : num(0), result(0) {};
//
//	void get_num() {
//		scanf("%lf", &num); getchar();
//	}
//
//	void get_sqrnum() {
//		double root = floor(sqrt(num));
//		stack.push(root);
//		num = num - pow(root, 2);
//		result++;
//
//		if (num >= 1) {
//			get_sqrnum();
//		}
//	}
//
//	void print_result() {
//		printf("%d\n", result);
//		while (!stack.empty()) {
//			printf("%2.0lf^2 + ", stack.top());
//			stack.pop();
//		}
//		printf("\n");
//	}
//};
//
//int main() {
//	operate op;
//	op.get_num();
//	op.get_sqrnum();
//	op.print_result();
//	return 0;
//}

/*Dynamic Programming --> 제출본*/
class operate {
private:
	int num;
	int* rawdata;
public:
	operate() :num(0), rawdata(NULL) {};
	~operate() {
		delete[] rawdata;
	}

	void get_num() {
		scanf("%d", &num); getchar();
		rawdata = new int[num + 1];
	}

	void get_sqrnum() {
		/*****************************************************
		* 예를 들어 101이라는 수가 들어오면 
		* 1. 해당 수가 제곱수인지 먼저 판단하고,
		* 2. 제곱수가 아니면, 1^2, 2^2, ... , 10^2까지 가면서
		* 3. 101 - (2에서 구한 수)가 어떻게 구성된지를 판단한다.
		* ***************************************************/
		if (floor(sqrt(num)) == sqrt(num)) {
			rawdata[num] = 1;
			return;
		}

		int num_saved; /*3.의 계산식 값 저장*/
		for (int current = 1; current <= num; current++) {
			if (floor(sqrt(current)) == sqrt(current)) {
				rawdata[current] = 1;
				continue;
			}

			rawdata[current] = INT_MAX;

			for (int i = 1; current > i * i; i++) {
				num_saved = current - i * i;
				if (rawdata[num_saved] + 1 < rawdata[current]) {
					rawdata[current] = rawdata[num_saved] + 1;
				}
			}
		}
	}

	void print_result() {
		printf("%d\n", rawdata[num]);
	}
};

int main() {
	operate op;
	op.get_num();
	op.get_sqrnum();
	op.print_result();
	return 0;
}