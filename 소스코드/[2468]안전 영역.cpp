#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int** map = NULL;
int** searched = NULL;
int len, max = -1, min = 999;
int area = 1;

int drow[4] = { 0,1,0,-1 };
int dcol[4] = { 1,0,-1,0 };

void dfs(int row, int col, int rain) {
	int nrow, ncol;
	searched[row][col] = 1;

	for (int i = 0; i < 4; i++) {
		nrow = row + drow[i];
		ncol = col + dcol[i];

		if (nrow < 0 || ncol < 0 || nrow >= len || ncol >= len) continue;
		if (searched[nrow][ncol] == 1 || map[nrow][ncol] <= rain) continue;

		dfs(nrow, ncol, rain);
	}
}

int main() {
	scanf("%d", &len); getchar();

	map = (int**)malloc(sizeof(int*)*len);
	for (int i = 0; i < len; i++) {
		map[i] = (int*)malloc(sizeof(int)*len);
	}
	searched = (int**)malloc(sizeof(int*)*len);
	for (int i = 0; i < len; i++) {
		searched[i] = (int*)malloc(sizeof(int)*len);
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] < min) min = map[i][j];
			else if (map[i][j] > max) max = map[i][j];
		}
	}

	int area_temp;
	for (int rain = min; rain <= max; rain++) {
		area_temp = 0;

		for (int i = 0; i < len; i++) {
			memset(searched[i], 0, sizeof(int)*len); //방문이력 초기화
		}

		for (int row = 0; row < len; row++) {
			for (int col = 0; col < len; col++) {
				if (searched[row][col] == 1 || map[row][col] <= rain) continue;
				dfs(row, col, rain);
				area_temp++;
			}
		}

		if (area_temp > area) area = area_temp;
	}

	printf("%d\n", area);
	return 0;
}