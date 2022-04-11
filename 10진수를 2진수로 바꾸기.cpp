#include <iostream>
#include <bitset> //vector<bool>로 생각하면 된다.
#include <string>
#pragma warning (disable:4996)
using namespace std;

int main() {
	unsigned int num;
	cout << "10진수 : ";
	cin >> num;

	auto rawdata = bitset<32>(num);

	string st = rawdata.to_string();
	st = st.substr(st.find('1'));

	cout << "2진수 : ";
	cout << st << endl;
	cout << "1의 개수 : ";
	cout << rawdata.count() << endl;
	cout << "bitset 사이즈 : ";
	cout << rawdata.size();
	return 0;
}