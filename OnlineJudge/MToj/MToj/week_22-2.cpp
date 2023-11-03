#include<iostream>
using namespace std;

int my(int a, int b)
{
	if (a % b) {
		return my(b, a % b);
	}
	return b;
}

void toreal(int fz, int fm)
{
	int m = my(fz, fm);
	cout << fz / m << '/' << fm / m;
}

int main()
{
	int n, sum = 0;
	cin >> n;
	for (int i = 2; i < n; i++) {
		int temp = n;
		while (temp) {
			sum += temp % i;
			temp /= i;
		}
	}
	toreal(sum, n - 2);
	return 0;
}