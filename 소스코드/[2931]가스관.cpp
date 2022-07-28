#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

enum a { north = 1, south, east, west };
char blocktype[7] = { '|', '-', '+', '1', '2', '3', '4' };
struct info {
	int row, col, dir;
	bool isValid = false;
};
vector<pair<int, int>> block[7] = {
	{{north, north}, {south, south}}, //|
	{{east, east}, {west, west}}, //-
	{{north, north}, {south, south}, {east, east}, {west, west}}, //+
	{{north, east}, {west, south}}, //1
	{{south, east}, {west, north}}, //2
	{{east, north}, {south, west}}, //3
	{{east, south}, {north, west}} //4
};
pair<int, int> moscow, zagreb;
vector<string> map;
int rows, cols;
int drow[5] = { 0,-1,1,0,0 }, dcol[5] = { 0,0,0,1,-1 }; //north, south, east, west 순서

void initialize() {
	cin >> rows >> cols;
	map.resize(rows);

	for (int i = 0; i < rows; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (map[i][j] == 'M') moscow = { i, j };
			else if (map[i][j] == 'Z') zagreb = { i, j };
		}
	}
}

int hasDir(char blockType, int curDir) {
	if (blockType == '.') return 0; //다음 칸이 빈 칸일 경우 갈 수 없음을 리턴
	else if (blockType == 'M' || blockType == 'Z') return curDir; //다음칸이 목적지인 경우, 현 방향 그대로 리턴

	int blockIdx = find(blocktype, blocktype + 7, blockType) - blocktype; //현재 블록의 내부 index를 찾는다

	for (const auto& it : block[blockIdx]) { //현재 블록이 curDir의 방향으로 진입을 허용하는지 알아본다.
		if (it.first == curDir) {
			return it.second; //진입이 허용되면 진출 방향을 리턴한다.
		}
	}

	return 0; //진입이 허용되지 않으면 0(아무 방향도 지정되지 않음)을 리턴한다.
	
}

info destinationOf(pair<int, int> start, int dir = 0, bool checkVisited = false) {
	int currow = start.first, curcol = start.second, curdir = dir;
	int nrow, ncol, ndir;
	int visited[30][30] = { 0 };

	if (curdir == 0) { //시작점 혹은 불분명한 방향
		for (int k = 1; k <= 4; k++) {
			nrow = currow + drow[k]; ncol = curcol + dcol[k];
			if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || map[nrow][ncol] == 'M' || map[nrow][ncol] == 'Z' || map[nrow][ncol] == '.') continue;
			ndir = hasDir(map[nrow][ncol], k);
			if (ndir) { //k 방향에 k 방향으로 진입할 수 있는 파이프가 있다.
				currow = nrow; curcol = ncol; curdir = ndir;
				break;
			} 
		}
	}

	//if (curdir == 0) return { currow, curcol, 0 }; //시작 지점에서 인접한 파이프가 없는 경우

	while (1) {
		visited[currow][curcol]++;
		nrow = currow + drow[curdir]; ncol = curcol + dcol[curdir];
		if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols) break;

		ndir = hasDir(map[nrow][ncol], curdir);

		if (!ndir) break;

		currow = nrow; curcol = ncol; curdir = ndir;
	}

	if (checkVisited) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (map[i][j] == 'M' || map[i][j] == 'Z' || map[i][j] == '.')  continue;
				if ((map[i][j] == '+' && visited[i][j] < 2) || visited[i][j] < 1) {
					return { currow, curcol, curdir, false };
				}
			}
		}
	}
	return { currow, curcol, curdir, true };
}

void operate() {
	//1. 모스크바 및 자그레브에서 각각 출발해서 어디까지 갈 수 있는지 확인한다.
	//2. 모스크바에서 끝난 방향, 자그레브에서 끝난 방향(의 반대)를 이을 수 있는 파이프를 하나씩 대입한 뒤, 모스크바에서 끝까지 갈 수 있는지 확인한다.
	info fromMoscow = destinationOf(moscow);
	info fromZagreb = destinationOf(zagreb);

	int targetrow = fromMoscow.row + drow[fromMoscow.dir];
	int targetcol = fromMoscow.col + dcol[fromMoscow.dir];

	int inDir = fromMoscow.dir;
	int outDir = fromZagreb.dir;

	outDir = outDir == 1 ? 2 : (outDir == 2 ? 1 : (outDir == 3 ? 4 : (outDir == 4 ? 3 : 0)));

	for (int i = 0; i < 7; i++) {
		map[targetrow][targetcol] = blocktype[i];
		info testData = destinationOf(moscow, 0, true);

		if (make_pair(testData.row, testData.col) == zagreb && testData.isValid) {
			cout << targetrow + 1 << ' ' << targetcol + 1 << ' ' << blocktype[i] << endl;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}