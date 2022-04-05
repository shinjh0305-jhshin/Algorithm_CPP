#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;

bool compare(const int &a) {
	if (a >= 60) return true;
	return false;
}

int main() {
	list<int> li1 = { -2,4,8,9 };
	list<int> li2 = { 30,30,60,110,140 };

	li2.unique();

	map<string, int> m = { {"shin", 980305}, {"choi", 971210} };
	m.insert({ "park", 980114 });
	for (auto s : m) {
		cout << s.first << ' ' <<s.second << endl;
	}

	map<string, int> m1 = { {"shin", 980305}, {"choi", 971210} };
	map<string, int>::iterator it = m1.begin();
	auto it=m1.begin();

	//cout << m["shin"] << endl;
	//m["park"] = 980114;
	//cout << m["park"] << endl;

	multiset<int> myset = { 3,1,5,4,3,5,1,4,4,3,2,2,7,6,4,3,6 };
	int arr[] = { 10,20,30 };

	myset.insert(100);
	myset.insert({ 100,200,300 });
	myset.insert(arr, arr + 3);

	cout << *myset.find(3) << endl;
	cout << *(myset.find(3)++) << endl;
	cout << *myset.upper_bound(4) << endl;

	for (auto s : myset) {
		cout << s << ' ';
	}

	//list<string> st1 = { "apple", "banana", "charlie" };
	//list<string> st2 = { "delta", "echo", "foxtrot" };

	//st1.merge(st2);

	return 0;
}