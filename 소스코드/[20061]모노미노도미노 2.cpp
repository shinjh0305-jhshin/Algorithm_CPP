#include <iostream>
#include <vector>
using namespace std;

//모든 블록의 기준점은 가장 왼쪽, 가장 위의 블록이다
int blueArea[4][6] = { 0 }, greenArea[6][4] = { 0 }; //행렬 index 조심!!

void moveTypeOne(vector<int>& info) {													//■
	//info에 행,열이 도착하면, 파란 초록 순서대로 몇행 몇열에 가서 붙는지를 리턴한다.
	int currow = info[0], curcol = info[1];

	int nextcol; //파란색 영역에서 몇 열에 가서 붙을지
	for (nextcol = 0; nextcol < 5; nextcol++) {
		if (blueArea[currow][nextcol + 1] != 0) break;
	}

	int nextrow; //초록생 영역에서 몇 행에 가서 붙을지
	for (nextrow = 0; nextrow < 5; nextrow++) {
		if (greenArea[nextrow + 1][curcol] != 0) break;
	}

	blueArea[currow][nextcol] = 1;
	greenArea[nextrow][curcol] = 1;
}

void moveTypeTwo(vector<int>& info) {													 //■■
	//info에 행,열이 도착하면, 파란 초록 순서대로 몇행 몇열에 가서 붙는지를 리턴한다.
	int currow = info[0], curcol = info[1];

	int nextcol; //파란색 영역에서 몇 열에 가서 붙을지
	for (nextcol = 1; nextcol < 5; nextcol++) { //오른쪽 사각형이 기준이 됐다
		if (blueArea[currow][nextcol + 1] != 0) break;
	}

	int nextrow; //초록생 영역에서 몇 행에 가서 붙을지
	for (nextrow = 0; nextrow < 5; nextrow++) {
		if (greenArea[nextrow + 1][curcol] != 0 || greenArea[nextrow + 1][curcol + 1] != 0)  break;
	}

	blueArea[currow][nextcol - 1] = blueArea[currow][nextcol] = 1;
	greenArea[nextrow][curcol] = greenArea[nextrow][curcol + 1] = 1;
}

void moveTypeThree(vector<int>& info) {													 //■
	//info에 행,열이 도착하면, 파란 초록 순서대로 몇행 몇열에 가서 붙는지를 리턴한다.             ■
	int currow = info[0], curcol = info[1];

	int nextcol; //파란색 영역에서 몇 열에 가서 붙을지
	for (nextcol = 0; nextcol < 5; nextcol++) {
		if (blueArea[currow][nextcol + 1] != 0 || blueArea[currow + 1][nextcol + 1] != 0) break;
	}

	int nextrow; //초록생 영역에서 몇 행에 가서 붙을지
	for (nextrow = 1; nextrow < 5; nextrow++) {
		if (greenArea[nextrow + 1][curcol] != 0) break;
	}
	blueArea[currow][nextcol] = blueArea[currow + 1][nextcol] = 1;
	greenArea[nextrow - 1][curcol] = greenArea[nextrow][curcol] = 1;
}

int eraseRowCol() {
	//파란색 영역은 열 단위로 본다
	int erasedCol = 0;

	bool fullCol;
	for (int colMov = 5; colMov >= 0; colMov--) {
		fullCol = true;
		for (int rowMov = 0; rowMov < 4; rowMov++) {
			if (blueArea[rowMov][colMov] == 0) { //빈 칸이 있을 경우
				fullCol = false;
				break;
			}
		}

		if (fullCol) { //빈 칸이 없을 경우
			for (int rowMov = 0; rowMov < 4; rowMov++) {
				blueArea[rowMov][colMov] = 0; //전부 빈칸으로 만든다.
			}
			erasedCol++; //지워진 열 개수 증가
		}
		else if (erasedCol) { //현재 열에 빈 칸이 있고, 기존에 지워진 열이 있었을 경우, 지워진 열의 개수만큼 내린다.
			for (int rowMov = 0; rowMov < 4; rowMov++) {
				blueArea[rowMov][colMov + erasedCol] = blueArea[rowMov][colMov]; //앞선 블록들을 내린다.
				blueArea[rowMov][colMov] = 0; //기존 블록 위치를 0으로 만든다.
			}
		}
	}
	
	//초록색 영역은 행 단위로 본다
	int erasedRow = 0;
	bool fullRow;
	for (int rowMov = 5; rowMov >= 0; rowMov--) {
		fullRow = true;
		for (int colMov = 0; colMov < 4; colMov++) {
			if (greenArea[rowMov][colMov] == 0) { //빈 칸이 있을 경우
				fullRow = false;
				break;
			}
		}

		if (fullRow) { //빈 칸이 없을 경우
			for (int colMov = 0; colMov < 4; colMov++) {
				greenArea[rowMov][colMov] = 0; //전부 빈칸으로 만든다.
			}
			erasedRow++; //지워진 행 개수 증가
		}
		else if (erasedRow) { //현재 행에 빈 칸이 있고, 기존에 지워진 행이 있었을 경우, 지워진 행의 개수만큼 내린다.
			for (int colMov = 0; colMov < 4; colMov++) {
				greenArea[rowMov + erasedRow][colMov] = greenArea[rowMov][colMov]; //앞선 블록들을 내린다.
				greenArea[rowMov][colMov] = 0; //기존 블록 위치를 0으로 만든다.
			}
		}
	}

	return erasedCol + erasedRow;
}

void eraseBuffer() { //연한 색 부위 검토하고 삭제한다.
	//파란색
	int eraseCols = 0;
	for (int col = 0; col < 2; col++) {
		for (int row = 0; row < 4; row++) {
			if (blueArea[row][col] != 0) {
				eraseCols++;
				break;
			}
		}
	}

	if (eraseCols) {
		for (int col = 5 - eraseCols; col >= 0; col--) {
			for (int row = 0; row < 4; row++) {
				blueArea[row][col + eraseCols] = blueArea[row][col];
				blueArea[row][col] = 0;
			}
		}
	}

	//초록색
	int eraseRows = 0;
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 4; col++) {
			if (greenArea[row][col] != 0) {
				eraseRows++;
				break;
			}
		}
	}

	if (eraseRows) {
		for (int row = 5 - eraseRows; row >= 0; row--) {
			for (int col = 0; col < 4; col++) {
				greenArea[row + eraseRows][col] = greenArea[row][col];
				greenArea[row][col] = 0;
			}
		}
	}
}

void operate() {
	int blocks, type, startrow, startcol;
	cin >> blocks;
	
	vector<int> info(4);

	int answer = 0;
	while (blocks--) {
		cin >> type >> startrow >> startcol;
		info[0] = startrow;
		info[1] = startcol;

		if (type == 1) moveTypeOne(info);
		else if (type == 2) moveTypeTwo(info);
		else moveTypeThree(info);

		answer += eraseRowCol();
		eraseBuffer();
	}

	int leftBlocks = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (blueArea[j][i]) leftBlocks++;
			if (greenArea[i][j]) leftBlocks++;
		}
	}

	cout << answer << endl;
	cout << leftBlocks << endl;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}