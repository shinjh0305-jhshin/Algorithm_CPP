//lazy propagation
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> switchtree(262144);

void updateswitchtree(int start, int end, int node)
{
	if (switchtree[node].second)
	{
		switchtree[node].first = (end - start + 1) - switchtree[node].first;
		if (start != end)
		{
			switchtree[node * 2].second = !switchtree[node * 2].second;
			switchtree[node * 2 + 1].second = !switchtree[node * 2 + 1].second;
		}
		switchtree[node].second = 0;
	}
}

void changestatus(int start, int end, int left, int right, int node)
{
	updateswitchtree(start, end, node);

	if (start > right || end < left)
		return;

	if (start >= left && end <= right)
	{
		switchtree[node].second = !switchtree[node].second;
		updateswitchtree(start, end, node);
		return;
	}

	int mid = (start + end) / 2;

	changestatus(start, mid, left, right, node * 2);
	changestatus(mid + 1, end, left, right, node * 2 + 1);
	switchtree[node].first = switchtree[node * 2].first + switchtree[node * 2 + 1].first;
}

int getvalue(int start, int end, int left, int right, int node)
{
	updateswitchtree(start, end, node);

	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return switchtree[node].first;

	int mid = (start + end) / 2;

	return getvalue(start, mid, left, right, node * 2) + getvalue(mid + 1, end, left, right, node * 2 + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, task, a, b;
	cin >> n >> m;
	while (m--)
	{
		cin >> task >> a >> b;
		if (task == 0)
			changestatus(0, n - 1, a - 1, b - 1, 1);
		else
			cout << getvalue(0, n - 1, a - 1, b - 1, 1) << '\n';
	}
	return 0;
}


//시간초과
//#include <iostream>
//#include <vector>
//#define endl "\n"
//using namespace std;
//
//bool sw[100003] = { false };
//int segTree[400012] = { 0 };
//
//int switches, opers;
//
//int updateTree(int curLeft, int curRight, int querLeft, int querRight, int idx) {
//	if (querRight < curLeft || curRight < querLeft) return 0;
//
//	if (curLeft == curRight) {
//		if (segTree[idx] == 0) {
//			segTree[idx] = 1;
//			return 1;
//		}
//		else {
//			segTree[idx] = 0;
//			return -1;
//		}
//	}
//
//	int mid = (curLeft + curRight) / 2;
//	int statusChanged = updateTree(curLeft, mid, querLeft, querRight, idx * 2) + 
//						updateTree(mid + 1, curRight, querLeft, querRight, idx * 2 + 1);
//
//	segTree[idx] += statusChanged;
//	return statusChanged;
//}
//
//int getSum(int curLeft, int curRight, int querLeft, int querRight, int idx) {
//	if (querRight < curLeft || curRight < querLeft) return 0;
//	if (querLeft <= curLeft && curRight <= querRight) {
//		return segTree[idx];
//	}
//
//	int mid = (curLeft + curRight) / 2;
//	return getSum(curLeft, mid, querLeft, querRight, idx * 2) + getSum(mid + 1, curRight, querLeft, querRight, idx * 2 + 1);
//}
//
//void initialize() {
//	cin >> switches >> opers;
//}
//
//void operate() {
//	int op, from, to, changed;
//	for (int i = 0; i < opers; i++) {
//		cin >> op >> from >> to;
//
//		if (op == 0) { //스위치 반전
//			changed = updateTree(1, switches, from, to, 1);
//			//cout << "켜진 스위치가 "<<changed << "개 증가되었습니다." << endl;  /*********************************************************디버깅 삭제요망*********************/
//		}
//		else {
//			cout << getSum(1, switches, from, to, 1) << endl;
//		}
//	}
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