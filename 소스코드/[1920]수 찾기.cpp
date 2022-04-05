#include <iostream>
#include <set>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

multiset<int> st;

void initialize() {
	int num, temp;
	cin >> num; cin.get();

	for (int i = 0; i < num; i++) {
		cin >> temp; cin.get();
		st.insert(temp);
	}
}

void findout() {
	int num, target;
	multiset<int>::iterator iter;

	cin >> num; cin.get();

	for (int i = 0; i < num; i++) {
		cin >> target; cin.get();
		
		iter = st.find(target);
		if (iter != st.end()) cout << 1 << endl;
		else cout << 0 << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	findout();

	return 0;
}