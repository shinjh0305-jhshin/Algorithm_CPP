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

	for (int i = 0; i <= price; i++) {
		if (i%currency[0] == 0) rawdata[0][i] = 1;
		else rawdata[0][i] = 0;
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