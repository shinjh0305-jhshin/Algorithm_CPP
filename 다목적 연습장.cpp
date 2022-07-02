#include <iostream>
using namespace std;


void changeName(char(&name)[20]) {
	cout << name << endl;
	name[0] = 'A';
	cout << name << endl;
}

int main() {
	char name[20] = "shin Jaehyun";

	int num = 0b1110000;

	changeName(name);

	cout << name << endl;

	return 0;
}