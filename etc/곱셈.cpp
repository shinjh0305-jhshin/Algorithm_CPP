#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)
#pragma warning (disable:6031)
#define threshold 2
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int add = 0, mul = 0;

int operate(int num1, int num2);
int digit(int num);

int main() {
	int num1, num2;
	printf("NUM1 : ");
	scanf("%d", &num1); getchar();


	printf("NUM2 : ");
	scanf("%d", &num2); getchar();

	int result = operate(num1, num2);
	printf("result = %d\n", result);
	printf("Result || Add : %d    Mul : %d\n", add, mul);
	return 0;

}

int operate(int num1, int num2) {
	printf("#######################################################\n");
	printf("Phase r started with(%d, %d)\n", num1, num2);

	int max_digit = MAX(digit(num1), digit(num2));
	if (max_digit <= threshold) return num1 * num2;

	int half_digit = max_digit / 2;
	int pow_of_ten = pow(10, half_digit);

	int x_0 = num1 / pow_of_ten, y_0 = num1 % pow_of_ten, w_0 = num2 / pow_of_ten, z_0 = num2 % pow_of_ten;

	int x_0y_0 = x_0 + y_0; add++;
	int w_0z_0 = w_0 + z_0; add++;

	int r;
	if (MAX(digit(x_0y_0), digit(w_0z_0)) > threshold) {
		r = operate(x_0y_0, w_0z_0);
	}
	else {
		r = x_0y_0 * w_0z_0; mul++;
	}

	printf("Result || Add : %d    Mul : %d\n", add, mul);
	printf("-------------------------------------------------------\n");
	printf("Phase p started with (%d, %d)\n", num1, num2);

	int p;
	if (MAX(digit(x_0), digit(w_0)) > threshold) {
		p = operate(x_0, w_0);
	}
	else {
		p = x_0 * w_0; mul++;
	}

	printf("Result || Add : %d    Mul : %d\n", add, mul);
	printf("-------------------------------------------------------\n");
	printf("Phase q started with (%d, %d)\n", num1, num2);


	int q;
	if (MAX(digit(y_0), digit(z_0)) > threshold) {
		q = operate(y_0, z_0);
	}
	else {
		q = y_0 * z_0; mul++;
	}

	int result = 0;
	result += p * pow(10, 2 * half_digit);
	result += (r - p - q) * pow(10, half_digit);
	result += q;
	add += 4;

	printf("Result || Add : %d    Mul : %d\n", add, mul);
	printf("#######################################################\n");
	return result;
}