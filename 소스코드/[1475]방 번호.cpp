#include <iostream>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

int remaining[10];
int ans = 1;

void buyOneMore(int ch) {
	for (int i = 0; i < 10; i++) remaining[i]++;
	ans++;
	remaining[ch]--;
}

void operate() {
	int ch;

	for (int i = 0; i < 10; i++) remaining[i] = 1;

	while ((ch = cin.get()) != '\n') {
		ch -= '0';

		if (ch == 6 || ch == 9) {
			if (remaining[6]) remaining[6]--;
			else if (remaining[9]) remaining[9]--;
			else buyOneMore(6);
		}
		else {
			if (remaining[ch]) remaining[ch]--;
			else buyOneMore(ch);
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	operate();

	return 0;
}