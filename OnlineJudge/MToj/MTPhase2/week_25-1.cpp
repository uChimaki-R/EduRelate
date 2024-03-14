#include<iostream>
using namespace std;

bool isPrime(int n)
{
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)return false;
	}
	return true;
}

int main()
{
	int i;
	cin >> i;
	if (isPrime(i))cout << 1;
	else if (i % 2 == 0)cout << 2;
	else if (isPrime(i - 2))cout << 2;
	else cout << 3;
	return 0;
}