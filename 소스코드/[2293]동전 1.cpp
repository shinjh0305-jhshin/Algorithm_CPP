#include <iostream>
#include <algorithm>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int rawdata[2][10005];
int currency[102];

int main() {
	int now = 0, before = 1, type, price;

	cin >> type >> price; cin.get();
	for (int i = 0; i < type; i++) {
		cin >> currency[i]; cin.get();
	}
	sort(currency, currency + type);

	//숫자를 쪼갤 때, 순서가 상관없는 문제이기 때문에
	//목표 숫자에 1씩 증가하며 도달하는 것을 주 흐름으로 잡기보다는
	//쪼갤 수 있는 숫자를 바꿔가는 것을 주 흐름으로 잡는다.
	//쪼갤 수 있는 숫자가 제한적이기에 가능한 일이다.
	for (int i = 0; i <= price; i++) {
		if (i % currency[0] == 0) rawdata[now][i] = 1;
		else rawdata[now][i] = 0;
	}
	swap(now, before);

	int curCurrency; //현재 작업중인 화폐단위
	for (int i = 1; i < type; i++) {
		curCurrency = currency[i];
		rawdata[now][0] = 1;
		for (int j = 1; j <= price; j++) {
			rawdata[now][j] = rawdata[before][j];
			if (j >= curCurrency) rawdata[now][j] += rawdata[now][j - curCurrency];
		}
		swap(now, before);
	}

	cout << rawdata[before][price] << endl;
	return 0;
}