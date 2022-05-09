#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

int main() {
	int i, chars = 0;
	char ch;
	char rawdata[102];

	scanf("%s", rawdata);
	int last = strlen(rawdata) - 1;

	for (i = last; i >= 0; i--) {
		ch = rawdata[i];
		switch (ch) {
		case '=':
			i--;
			if (rawdata[i] == 'z' && i > 0 && rawdata[i - 1] == 'd') i--;
			break;
		case '-':
			i--;
			break;
		case 'j':
			if (i == 0) break;
			else if (rawdata[i - 1] == 'l' || rawdata[i - 1] == 'n') i--;
			break;
		}
		chars++;
	}
	printf("%d\n", chars);
}