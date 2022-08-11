#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int cranes, containers;
vector<int> crane, container;
int curCrane[52];
bool done[10003];

void initialize() {
	cin >> cranes;
	crane.resize(cranes);
	for (int i = 0; i < cranes; i++) {
		cin >> crane[i];
	}

	cin >> containers;
	container.resize(containers);
	for (int i = 0; i < containers; i++) {
		cin >> container[i];
	}

	sort(crane.begin(), crane.end());
	sort(container.begin(), container.end());
	memset(curCrane, -1, sizeof(curCrane));
}

void operate() {
	int craneIdx = cranes - 1, containerIdx = containers - 1;

	if (crane[craneIdx] < container[containerIdx]) {
		cout << -1 << endl;
		return;
	}
	
	while (containerIdx >= 0 && craneIdx >= 0) {
		while (containerIdx >= 0 && crane[craneIdx] < container[containerIdx]) {
			containerIdx--;
		}

		if (containerIdx < 0) break;

		curCrane[craneIdx] = containerIdx;
		done[containerIdx] = true;
		craneIdx--;
		containerIdx--;
	}

	int time = 1;
	bool stillWorking;

	while (1) {
		stillWorking = false;

		for (craneIdx = 0; craneIdx < cranes; craneIdx++) {
			for (int temp = curCrane[craneIdx]; temp >= 0; temp--) {
				if (!done[temp]) {
					stillWorking = true;
					curCrane[craneIdx] = temp;
					done[temp] = true;
					break;
				}
				if (temp == 0) curCrane[craneIdx] = -1;
			}
		}

		if (!stillWorking) {
			cout << time << endl;
			return;
		}
		time++;
	}

	//아래 코드는 다음과 같은 반례를 해결하지 못함
	//4 1 2 3 4 8 1 1 2 2 3 3 4 4
	
	//int availableCrane = 0, containerToGo = 0;
	//int time = 1;
	//while (1) {
	//	for (int i = availableCrane; i < cranes && containerToGo < containers; i++) {
	//		if (container[containerToGo] <= crane[i]) {
	//			containerToGo++;
	//		}
	//		else {
	//			while (crane[i] < container[containerToGo] && i < cranes) i++;
	//			if (i == cranes) {
	//				cout << -1 << endl;
	//				return;
	//			}
	//			else {
	//				availableCrane = i;
	//				containerToGo++;
	//			}
	//		}
	//	}

	//	if (containerToGo == containers) {
	//		cout << time << endl;
	//		return;
	//	}

	//	time++;
	//}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	initialize();
	operate();

	return 0;
}