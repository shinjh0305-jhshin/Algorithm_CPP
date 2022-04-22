#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, x, y;
double ans;
vector<pair<double, double>> v;

double Product(int v1, int v2, int v3)
{
	double x1 = v[v1].first;
	double x2 = v[v2].first;
	double x3 = v[v3].first;
	double y1 = v[v1].second;
	double y2 = v[v2].second;
	double y3 = v[v3].second;

	double tmp1 = x1 * y2 + x2 * y3 + x3 * y1;
	double tmp2 = x2 * y1 + x3 * y2 + x1 * y3;

	double result = tmp1 - tmp2;
	return result / 2;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		v.push_back({ x,y });
	}

	ans = Product(0, 1, 2);

	if (ans > 0) cout << 1;
	else if (ans == 0) cout << ans;
	else cout << -1;
}