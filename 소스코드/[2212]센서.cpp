#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sensors, ant;

void operate() {
	cin >> sensors >> ant;
	vector<int> sensor(sensors);

	for (int i = 0; i < sensors; i++) {
		cin >> sensor[i];
	}

	sort(sensor.begin(), sensor.end());

	vector<int> dist(sensors - 1);
	
	for (int i = 0; i < sensors - 1; i++) {
		dist[i] = sensor[i + 1] - sensor[i];
	}

	sort(dist.begin(), dist.end(), greater<int>());

	int ans = 0;
	for (int i = ant - 1; i < sensors - 1; i++) {
		ans += dist[i];
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	operate();

	return 0;
}