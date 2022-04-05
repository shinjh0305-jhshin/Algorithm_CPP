#include <iostream>
#include <cstdlib>
#include <ctime>
#define endl "\n"
#pragma warning (disable:4996)
using namespace std;

double X, Y;
int ori;

void initialize() {
	/*cin >> Y >> X;*/
	X = rand() % 1000000000;
	while (1) {
		Y = rand();
		if (Y <= X) break;
	}
	ori = (int)(X / Y * 100);
}

int operate1() {
	int Z = (X * 100) / Y;

	//È®·üÀÌ ¹Ù²ð ¼ö ¾ø´Â °æ¿ì

	if (Z >= 99)

	{
		return -1;
	}


	int low = 0, high = 1000000000;

	int result = -1;

	while (low <= high)

	{
		int mid = (low + high) / 2;

		//ÀÌºÐÅ½»ö °á°ú È®·ü

		int tempZ = (100 * (X + mid)) / (Y + mid);

		if (Z >= tempZ)
		{
			result = mid + 1;
			low = mid + 1;
		}

		else
			high = mid - 1;
	}

	return result;
}

int operate() {
	int left = 0, right = 1000000000, mid, temp, target;

	if (ori == (int)((X + right) / (Y + right) * 100)) return -1;
	
	target = ori + 1;
	while (left < right) {
		mid = (left + right) / 2;

		temp = (int)((X + mid) / (Y + mid) * 100);

		if (temp >= target) right = mid;
		else left = mid + 1;
	}
	
	return left;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	srand((unsigned int)time(NULL));

	while (1) {
		initialize();
		int a = operate();
		int b = operate1();

		if (a != b) {
			cout << X << Y << endl;
		}
	}

	return 0;
}




