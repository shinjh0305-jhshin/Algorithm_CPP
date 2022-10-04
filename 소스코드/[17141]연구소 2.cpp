#include <iostream>
#include <queue>
#include <vector>
#include <cstring>//memset
using namespace std;

struct Pos {
	int x, y;
};

int N, M;
int Lab[50][50];
int visited[50][50];//bfs flood fill
bool check[50][50];//바이러스 놓았는지 확인
vector<Pos>Virus;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int Min = 987654321;

bool Spread() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Lab[i][j] != 1 && visited[i][j] == -1)
				return false;
		}
	}
	return true;
}

int bfs() {
	queue<Pos>q;
	int res = 0;
	memset(visited, -1, sizeof(visited));
	//바이러스가 있는 위치 모두 queue에 넣어주기
	for (int i = 0; i < Virus.size(); i++) {
		q.push({ Virus[i].x,Virus[i].y });
		visited[Virus[i].x][Virus[i].y] = 0;
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (Lab[nx][ny] != 1 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				res = visited[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
	//마지막에 퍼뜨린 곳의 시간이 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간임
	return res;
}

//바이러스 위치 조합 구하기
void dfs(int x, int y, int cnt) {
	if (cnt == M) {
		int res = bfs();
		if (Spread() == true) {
			if (Min > res)
				Min = res;
		}
		return;
	}
	for (int i = x; i < N; i++) {
		for (int j = y; j < N; j++) {
			if (Lab[i][j] != 2 || check[i][j] == true)
				continue;
			check[i][j] = true;
			Virus.push_back({ i,j });
			dfs(i, j, cnt + 1);
			check[i][j] = false;
			Virus.pop_back();
		}
		y = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Lab[i][j];
		}
	}
	dfs(0, 0, 0);
	if (Min == 987654321)
		Min = -1;
	cout << Min << '\n';
	return 0;
}
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cassert>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//vector<pair<int, int>> candid; //virus candidate site
//queue<pair<int, int>> virusSite;
//int sz_map, sz_virus, sz_candid;
//int map[55][55];
//enum a { BLANK, WALL, VIRUS };
//int drow[4] = { 1,0,-1,0 }, dcol[4] = { 0,-1,0,1 };
//int result = 2134567890;
//
//void initialize() {
//	cin >> sz_map >> sz_virus;
//
//	for (int i = 0; i < sz_map; i++) {
//		for (int j = 0; j < sz_map; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == VIRUS) {
//				candid.push_back({ i, j });
//			}
//		}
//	}
//
//	sz_candid = candid.size();
//}
//
//void spreadVirus() {
//	int sz_queue, currow, curcol, nrow, ncol;
//
//	int maptemp[55][55];
//	queue<pair<int, int>> qu(virusSite);
//	
//	memcpy(maptemp, map, sizeof(map));
//	int timeSpread = 0;
//
//	sz_queue = qu.size(); 
//
//	while (sz_queue--) {
//		maptemp[qu.front().first][qu.front().second] = -1;
//		pair<int, int> temp = qu.front();
//		qu.pop();
//		qu.push(temp);
//	}
//
//	while (1) {
//		sz_queue = qu.size();
//
//		while (sz_queue--) {
//			currow = qu.front().first; curcol = qu.front().second;
//			qu.pop();
//
//			for (int k = 0; k < 4; k++) {
//				nrow = currow + drow[k]; ncol = curcol + dcol[k];
//
//				if (nrow < 0 || nrow >= sz_map || ncol < 0 || ncol >= sz_map || maptemp[nrow][ncol] == WALL) continue;
//				if (maptemp[nrow][ncol] == -1) continue; //전파된 곳
//
//				maptemp[nrow][ncol] = -1;
//				qu.push({ nrow, ncol });
//			}
//		}
//
//		if (qu.empty()) {
//			int a = 0;
//			for (int i = 0; i < sz_map; i++) {
//				for (int j = 0; j < sz_map; j++) {
//					if (maptemp[i][j] != -1 && maptemp[i][j] != WALL) return;
//				}
//			}
//			result = min(result, timeSpread);
//			return;
//		}
//
//		timeSpread++;
//	}
//}
//
//void chooseVirus(int idx = 0, int chosen = 0) {
//	//if (sz_candid - idx < sz_virus - chosen) {
//	//	return; //남아있는 바이러스 다 선택해도 모든 바이러스 못 놓는 경우
//	//}
//	if (chosen == sz_virus) {
//		spreadVirus();
//		return;
//	}
//	if (idx >= sz_candid) return;
//
//	//현재 바이러스 사이트 선택
//	virusSite.push(candid[idx]);
//	chooseVirus(idx + 1, chosen + 1);
//	virusSite.pop();
//
//	//현재 바이러스 사이트 미선택
//	chooseVirus(idx + 1, chosen);
//}
//
//void operate() {
//	chooseVirus();
//	if (result == 2134567890) cout << -1 << endl;
//	else cout << result << endl;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	initialize();
//	operate();
//
//	return 0;
//}