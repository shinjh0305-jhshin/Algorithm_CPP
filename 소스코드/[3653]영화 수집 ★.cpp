#include <iostream>
#include <vector>
using namespace std;

vector<int> segTree(800016), rawdata(200004), index(100002), result(100002);
int test_cases, movies, queries, sz_rawdata;

/*
1. segTree는 (쿼리부)+(영화부)로 이루어진다.
2. 쿼리부는 전부 0으로 영화부는 전부 1로 채워넣는다.
3. 영화를 보기 시작하면 해당 영화는 쿼리부의 맨 끝부터 앞으로 쌓아나가기 시작한다. 이 때 영화의 바뀐 index는 index 벡터에서 관리한다.
4. 영화 위에 있던 영화의 개수는, 영화 index가 바뀌기 이전의 index - 1 까지의 누적합이다.
*/

int makeSegTree(int left, int right, int idx) {
	if (left == right) return segTree[idx] = rawdata[left];
	
	int mid = (left + right) / 2;
	return segTree[idx] = makeSegTree(left, mid, idx * 2) + makeSegTree(mid + 1, right, idx * 2 + 1);
}

int getQuery(int left, int right, int queryLeft, int queryRight, int idx) {
	if (queryRight < left || right < queryLeft) return 0;
	if (queryLeft <= left && right <= queryRight) return segTree[idx];
	
	int mid = (left + right) / 2;
	return getQuery(left, mid, queryLeft, queryRight, idx * 2) + getQuery(mid + 1, right, queryLeft, queryRight, idx * 2 + 1);
}

void changeSegTree(int left, int right, int dataIdx, int diff, int treeIdx) {
	if (left <= dataIdx && dataIdx <= right) {
		segTree[treeIdx] += diff;
		
		if (left == right) return;

		int mid = (left + right) / 2;
		changeSegTree(left, mid, dataIdx, diff, treeIdx * 2);
		changeSegTree(mid + 1, right, dataIdx, diff, treeIdx * 2 + 1);
	}
}

void initialize() {
	cin >> movies >> queries;

	sz_rawdata = movies + queries;

	for (int i = 1; i <= queries; i++) {
		rawdata[i] = 0; //rawdata : 쿼리 부분은 전부 0으로 채워넣고, 영화 부분만 1로 채워넣는다,
	}

	for (int i = 1; i <= movies; i++) {
		index[i] = queries + i; //index : rawdata 상에서 일련번호가 i인 영화의 index
		rawdata[queries + i] = 1;
	}

	makeSegTree(1, sz_rawdata, 1);
}

void operate() {
	int targetMovie;
	for (int i = 0; i < queries; i++) {
		cin >> targetMovie;
		result[i] = getQuery(1, sz_rawdata, 1, index[targetMovie] - 1, 1); //영화 앞에 있던 영화의 개수를 구해온다.

		//영화의 위치를 맨 위로 올려놓는다.
		rawdata[index[targetMovie]] = 0; //기존에 있던 위치는 0으로 만든다.
		changeSegTree(1, sz_rawdata, index[targetMovie], -1, 1);

		index[targetMovie] = queries - i;
		rawdata[index[targetMovie]] = 1; //새로운 위치는 1로 만든다.
		changeSegTree(1, sz_rawdata, index[targetMovie], 1, 1);
	}

	for (int i = 0; i < queries; i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> test_cases;
	for (int i = 0; i < test_cases; i++) {
		initialize();
		operate();
	}
	return 0;
}
/*
1
5 3
4 4 5
ans : 3 0 4


*/