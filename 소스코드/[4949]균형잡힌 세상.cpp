#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#pragma warning (disable:4996)

char stack[105];
int top = -1;

int main() {
	char ch = getchar();

	while (ch != '.') {
		do {
			if (ch == '(' || ch == '[') {
				stack[++top] = ch;
			}
			else if (ch == ')') {
				if (stack[top] == '(') {
					stack[top--] = '\0';
				}
				else {
					printf("no\n");
					while ((ch = getchar()) != '.');
					goto end;
				}
			}
			else if (ch == ']') {
				if (stack[top] == '[') {
					stack[top--] = '\0';
				}
				else {
					printf("no\n");
					while ((ch = getchar()) != '.');
					goto end;
				}
			}
			ch = getchar();
		} while (ch != '\n');

		if (top == -1) printf("yes\n");
		else printf("no\n");

	end:;
		while (top != -1) stack[top--] = '\0';

		ch = getchar();
	}
}